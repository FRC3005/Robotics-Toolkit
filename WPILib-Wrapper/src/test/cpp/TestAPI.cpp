
#if 1
#include "gtest/gtest.h"
#include "labview/LVTrajectory.h"

#include <iostream>

TEST(Trajectory, TrajectoryAPI) {
    double totalTime = 0;
    size_t bufsize = 0;
    double waypoints_x[3] = {0.0, 1.0, 3.0};
    double waypoints_y[3] = {0.0, 1.0, 1.0};
    double waypoints_theta[3] = {0.0, 0.5, 1.0};
    lv_trajectory_handle handle = LV_CreateDifferentialDriveTrajectory(
                    0.2,
                    0.1,
                    0.1,
                    10,
                    1,
                    5,
                    10,
                    waypoints_x,
                    waypoints_y,
                    waypoints_theta,
                    3,
                    &totalTime,
                    &bufsize,
                    0 );
    std::cout << "Handle: " << handle << " totalTime (s): " << totalTime << " bufsize: " << bufsize << std::endl;

    lv_trajectory_state* states = new lv_trajectory_state[bufsize];

    LV_GetTrajectoryStates(handle,states, bufsize);
    LV_FreeTrajectory(handle);

    for (int i = 0; i < (int)bufsize; i++) {
        std::cout << "t: " << states[i].t << " velocity: " << states[i].velocity << " pose.x: " << states[i].pose.x 
        << " pose.y: " << states[i].pose.y << " pose.theta: " << states[i].pose.theta << std::endl;
    }
}

TEST(Trajectory, TrajectoryAPI_reverse) {
    double totalTime = 0;
    size_t bufsize = 0;
    double waypoints_x[3] = {0.0, 1.0, 3.0};
    double waypoints_y[3] = {0.0, 1.0, 1.0};
    double waypoints_theta[3] = {0.0, 0.5, 1.0};
    lv_trajectory_handle handle = LV_CreateDifferentialDriveTrajectory(
                    0.2,
                    0.1,
                    0.1,
                    10,
                    1,
                    5,
                    10,
                    waypoints_x,
                    waypoints_y,
                    waypoints_theta,
                    3,
                    &totalTime,
                    &bufsize,
                    1 );
    std::cout << "Handle: " << handle << " totalTime (s): " << totalTime << " bufsize: " << bufsize << std::endl;

    lv_trajectory_state* states = new lv_trajectory_state[bufsize];

    LV_GetTrajectoryStates(handle,states, bufsize);
    LV_FreeTrajectory(handle);

    for (int i = 0; i < (int)bufsize; i++) {
        std::cout << "t: " << states[i].t << " velocity: " << states[i].velocity << " pose.x: " << states[i].pose.x 
        << " pose.y: " << states[i].pose.y << " pose.theta: " << states[i].pose.theta << std::endl;
    }
}

TEST(Trajectory, TrajectoryAPI2) {
    double totalTime = 0;
    size_t bufsize = 0;
    double control_vectors_x[4] = {0.0, 1.0, 2.0, 5.0};
    double control_vectors_y[4] = {0.0, 0.0, 0.0, 0.0};
    double velocity_vectors_x[4] = {0.0, 3.0, 4.0, 0.0};
    double velocity_vectors_y[4] = {0.0, 0.0, 0.0, 0.0};
    double accel_vectors_x[4] = {0.0, 0.0, 0.0, 0.0};
    double accel_vectors_y[4] = {0.0, 0.0, 0.0, 0.0};
    lv_trajectory_handle handle = LV_CreateDifferentialDriveTrajectory2(
                    0.2,
                    0.1,
                    0.1,
                    10,
                    1,
                    5,
                    10,
                    control_vectors_x,
                    control_vectors_y,
                    velocity_vectors_x,
                    velocity_vectors_y,
                    accel_vectors_x,
                    accel_vectors_y,
                    4,
                    &totalTime,
                    &bufsize );
    std::cout << "Handle: " << handle << " totalTime (s): " << totalTime << " bufsize: " << bufsize << std::endl;

    lv_trajectory_state* states = new lv_trajectory_state[bufsize];

    LV_GetTrajectoryStates(handle,states, bufsize);
    LV_FreeTrajectory(handle);

    for (int i = 0; i < (int)bufsize; i++) {
        std::cout << "t: " << states[i].t << " velocity: " << states[i].velocity << " pose.x: " << states[i].pose.x 
        << " pose.y: " << states[i].pose.y << " pose.theta: " << states[i].pose.theta << std::endl;
    }
}
#endif