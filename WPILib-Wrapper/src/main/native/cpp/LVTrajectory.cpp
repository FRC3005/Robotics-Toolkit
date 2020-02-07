
#include "labview/LVTrajectory.h"

#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

#include <algorithm>

struct lv_trajectory {
    frc::Trajectory value;
};


lv_trajectory_handle LV_CreateDifferentialDriveTrajectory2(
                    double ks_volts,
                    double kv_voltSecondPerUnit,
                    double ka_voltsSecondPerUnitSqrd,
                    double maxVoltage,
                    double trackwidth,
                    double maxVelocity,
                    double maxAccel,
                    double* position_vector_x,
                    double* position_vector_y,
                    double* velocity_vector_x,
                    double* velocity_vector_y,
                    double* acceleration_vector_x,
                    double* acceleration_vector_y,
                    size_t numPoints,
                    double* totalTimeSeconds,
                    size_t* trajectorySize ) {
    // TODO: If there are performance implications, create a class 
    // that can be initialized and passed around by LabVIEW with the below
    auto ks = units::volt_t(ks_volts);
    auto kv = kv_voltSecondPerUnit * 1_V * 1_s / 1_m;;
    auto ka = ka_voltsSecondPerUnitSqrd * 1_V * 1_s * 1_s / 1_m;
    auto voltageMax = units::volt_t(maxVoltage);
    auto trackwidthUnits = units::meter_t(trackwidth);
    auto maxVelocityUnits = units::meters_per_second_t(maxVelocity);
    auto maxAccelUnits = units::meters_per_second_squared_t(maxAccel);
    frc::DifferentialDriveKinematics DriveKinematics(trackwidthUnits);
    std::vector<frc::Spline<5>::ControlVector> controlVectors;
    controlVectors.reserve(numPoints);

    for ( int i = 0; i < (int)numPoints; i++ ) {
        frc::Spline<5>::ControlVector cv;
        cv.x[0] = position_vector_x[i];
        cv.x[1] = velocity_vector_x[i];
        cv.x[2] = acceleration_vector_x[i];
        cv.y[0] = position_vector_y[i];
        cv.y[1] = velocity_vector_y[i];
        cv.y[2] = acceleration_vector_y[i];
        controlVectors.push_back(cv);
    }

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
    struct lv_trajectory* trajectory = new struct lv_trajectory;
    trajectory->value = frc::TrajectoryGenerator::GenerateTrajectory(controlVectors, config);
    *totalTimeSeconds = units::unit_cast<double>(trajectory->value.TotalTime());
    *trajectorySize = trajectory->value.States().size();

    return static_cast<lv_trajectory_handle>(trajectory);
}

lv_trajectory_handle LV_CreateDifferentialDriveTrajectory(
                    double ks_volts,
                    double kv_voltSecondPerUnit,
                    double ka_voltsSecondPerUnitSqrd,
                    double maxVoltage,
                    double trackwidth,
                    double maxVelocity,
                    double maxAccel,
                    double* waypoints_x,
                    double* waypoints_y,
                    double* waypoints_theta,
                    size_t numPoints,
                    double* totalTimeSeconds,
                    size_t* trajectorySize,
                    uint8_t reverse ) {
    // TODO: If there are performance implications, create a class 
    // that can be initialized and passed around by LabVIEW with the below
    auto ks = units::volt_t(ks_volts);
    auto kv = kv_voltSecondPerUnit * 1_V * 1_s / 1_m;;
    auto ka = ka_voltsSecondPerUnitSqrd * 1_V * 1_s * 1_s / 1_m;
    auto voltageMax = units::volt_t(maxVoltage);
    auto trackwidthUnits = units::meter_t(trackwidth);
    auto maxVelocityUnits = units::meters_per_second_t(maxVelocity);
    auto maxAccelUnits = units::meters_per_second_squared_t(maxAccel);
    frc::DifferentialDriveKinematics DriveKinematics(trackwidthUnits);
    std::vector<frc::Pose2d> vectorWaypoints;
    vectorWaypoints.reserve(numPoints);

    for ( int i = 0; i < (int)numPoints; i++ ) {
        vectorWaypoints.push_back(frc::Pose2d(waypoints_x[i] * 1_m,
                                              waypoints_y[i] * 1_m,
                                              frc::Rotation2d(waypoints_theta[i] * 1_rad )));
    }

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

    config.SetReversed(reverse ? true : false);

    // An example trajectory to follow.  All units in meters.
    struct lv_trajectory* trajectory = new struct lv_trajectory;
    trajectory->value = frc::TrajectoryGenerator::GenerateTrajectory(vectorWaypoints, config);
    *totalTimeSeconds = units::unit_cast<double>(trajectory->value.TotalTime());
    *trajectorySize = trajectory->value.States().size();

    return static_cast<lv_trajectory_handle>(trajectory);
}

void LV_GetTrajectoryStates(lv_trajectory_handle lvTrajectory, lv_trajectory_state* states, size_t bufsize) {
    frc::Trajectory* trajectory = &lvTrajectory->value;
    
    std::transform(trajectory->States().begin(), trajectory->States().begin() + bufsize, states,
                   [](frc::Trajectory::State state) -> lv_trajectory_state { 
                       lv_trajectory_state result;
                       result.acceleration = units::unit_cast<double>(state.acceleration);
                       result.curvature = units::unit_cast<double>(state.curvature);
                       result.t = units::unit_cast<double>(state.t);
                       result.velocity = units::unit_cast<double>(state.velocity);
                       result.pose.x = units::unit_cast<double>(state.pose.Translation().X());
                       result.pose.y = units::unit_cast<double>(state.pose.Translation().Y());
                       result.pose.theta = units::unit_cast<double>(state.pose.Rotation().Radians());
                       return result;
                   });
}

void LV_FreeTrajectory(lv_trajectory_handle lvTrajectory) {
    delete lvTrajectory;
}
