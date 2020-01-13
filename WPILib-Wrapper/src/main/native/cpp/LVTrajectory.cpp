
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

void LV_CreateDifferentialDriveTrajectory(
    double ks_volts,
    double kv_voltSecondPerUnit,
    double ka_voltsSecondPerUnitSqrd,
    double maxVoltage,
    double trackwidth,
    double maxVelocity,
    double maxAccel
) {
    auto ks = units::volt_t(ks_volts);
    auto kv = kv_voltSecondPerUnit * 1_V * 1_s / 1_m;;
    auto ka = ka_voltsSecondPerUnitSqrd * 1_V * 1_s * 1_s / 1_m;
    auto voltageMax = units::volt_t(maxVoltage);
    auto trackwidthUnits = units::meter_t(trackwidth);
    auto maxVelocityUnits = units::meters_per_second_t(maxVelocity);
    auto maxAccelUnits = units::meters_per_second_squared_t(maxAccel);
    frc::DifferentialDriveKinematics DriveKinematics(trackwidthUnits);

    // Create a voltage constraint to ensure we don't accelerate too fast
    frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
        frc::SimpleMotorFeedforward<units::meters>(ks, kv, ka),
        DriveKinematics, voltageMax);

    // Set up config for trajectory
    frc::TrajectoryConfig config(maxVelocityUnits, maxAccelUnits);
    // Add kinematics to ensure max speed is actually obeyed
    config.SetKinematics(DriveKinematics);
    // Apply the voltage constraint
    config.AddConstraint(autoVoltageConstraint);

    // An example trajectory to follow.  All units in meters.
    auto trajectory = frc::TrajectoryGenerator::GenerateTrajectory(
        // Start at the origin facing the +X direction
        frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
        // Pass through these two interior waypoints, making an 's' curve path
        {frc::Translation2d(1_m, 1_m), frc::Translation2d(2_m, -1_m)},
        // End 3 meters straight ahead of where we started, facing forward
        frc::Pose2d(3_m, 0_m, frc::Rotation2d(0_deg)),
        // Pass the config
        config);
}
