#ifndef PATH_DLL_H
#define PATH_DLL_H

extern "C" {

__declspec(dllexport) void __stdcall HermitePath(double initial_x, double initial_y, double initial_theta,
            double final_x, double final_y, double final_theta,
            double initial_velocity, double final_velocity, unsigned char backwards,
            double extra_distance_initial, double extra_distance_final,
            double initial_angular_velocity, double final_angular_velocity,
            double s_min, double s_max, unsigned int array_len,
            double* path_x, double* path_y, double* path_theta);

} //extern "C"

#endif  // PATH_DLL_H
