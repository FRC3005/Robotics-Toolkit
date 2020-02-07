/*
 * Copyright (c) 2020 FRC 3005 RoboChargers
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of FRC 3005 RoboChargers nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "labview/LabVIEWTypes.h"

#include <stdint.h>
#include <stddef.h>

extern "C" {

typedef struct lv_trajectory* lv_trajectory_handle;

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
                    uint8_t reverse);

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
                    size_t* trajectorySize );

void LV_GetTrajectoryStates(lv_trajectory_handle lvTrajectory, lv_trajectory_state* states, size_t bufsize);
void LV_FreeTrajectory(lv_trajectory_handle lvTrajectory);

}
