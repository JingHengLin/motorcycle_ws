#include <ros/ros.h>
#include "pid.h"
#include <stdio.h>

// int main() {
//     // PID( double dt, double max, double min, double Kp, double Kd, double Ki );
//     PID pid = PID(0.0001, 10000, -10000, 30000, 0, 0);

//     double val = 1800000;
//     for (int i = 0; i < 500; i++) {
//         double inc = pid.calculate(270000, val);
//         printf("times: %d val:% 7.3f inc:% 7.3f\n", i, val, inc);
//         val += inc;
//     }

//     return 0;
// }

// Origin Code
// #include "pid.h"
// #include <stdio.h>

int main() {

    PID pid = PID(0.1, 100, -100, 0.1, 0.01, 0.5);

    double val = 20;
    for (int i = 0; i < 100; i++) {
        double inc = pid.calculate(0, val);
        printf("val:% 7.3f inc:% 7.3f\n", val, inc);
        val += inc;
    }
    return 0;
}
