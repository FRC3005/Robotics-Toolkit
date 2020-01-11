#include <path.h>

#include <iostream>

extern "C" {

__declspec(dllexport) void __stdcall HermitePath(double initial_x, double initial_y, double initial_theta,
            double final_x, double final_y, double final_theta,
            double initial_velocity, double final_velocity, unsigned char backwards,
            double extra_distance_initial, double extra_distance_final,
            double initial_angular_velocity, double final_angular_velocity,
            double s_min, double s_max, unsigned int array_len,
            double* path_x, double* path_y, double* path_theta)
{
    frc971::Pose Initial(frc971::Position(initial_x, initial_y), initial_theta);
    frc971::Pose Final(frc971::Position(final_x, final_y), final_theta);

    frc971::HermitePath Path(Initial, Final, initial_velocity, final_velocity,
                            backwards != 0, extra_distance_initial, extra_distance_final,
                            initial_angular_velocity,final_angular_velocity);

    frc971::Pose* Output = new frc971::Pose[array_len];

    Path.Populate(s_min, s_max, Output, array_len);

    for(auto i=0;i<array_len;i++) {
        path_x[i] = Output[i].translational()(0);
        path_y[i] = Output[i].translational()(1);
        path_theta[i] = Output[i].heading();
    }

    delete [] Output;
}

int main()
{
    double* x = new double[100];
    double* y = new double[100];
    double* theta = new double[100];

    HermitePath(0,0,0,5,5,0,0,0,false,0,0,0,0,0.0,1.0,100,x,y,theta);

    std::cout << "x,y,theta" << std::endl;
    for(auto i=0;i<100;i++) {
        std::cout << x[i] << "," << y[i] << "," << theta[i] << std::endl;
    }
}

}
