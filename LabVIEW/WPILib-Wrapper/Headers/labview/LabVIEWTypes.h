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

extern "C" {
    
// Note: This is dependant on __attribute__((PACKED)) and processor is
// little-endian
// Packing it required for LabVIEW structs see here 
// https://knowledge.ni.com/KnowledgeArticleDetails?id=kA00Z0000019YsYSAU&l=en-US

#define __USE_LABVIEW_CINTOOLS
#ifdef __USE_LABVIEW_CINTOOLS

#include "platdefines.h"
#include "lv_prolog.h"

#define PACKED

#else
#ifdef _WIN32
#define PACKED
#pragma pack(push, 1)
#else
#define PACKED __attribute__((__packed__))
#endif
#endif

typedef struct PACKED {
    double x;
    double y;
    double theta;
} lv_pose2d;

typedef struct PACKED { 
    // The time elapsed since the beginning of the trajectory. 
    double t;
    // The speed at that point of the trajectory.
    double velocity;
    // The acceleration at that point of the trajectory.
    double acceleration;
    // The pose at that point of the trajectory.
    lv_pose2d pose;
    // The curvature at that point of the trajectory.
    double curvature;
} lv_trajectory_state;

#ifdef __USE_LABVIEW_CINTOOLS

#include "lv_epilog.h"

#else
#ifdef _WIN32
#pragma pack(pop)
#endif
#endif

#undef PACKED

}
