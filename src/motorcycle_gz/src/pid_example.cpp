#include <ros/ros.h>
#include "pid.h"
#include <stdio.h>

int main() {
    // PID( double dt, double max, double min, double Kp, double Kd, double Ki );
    PID pid = PID(5, 100, -100, 0.1, 0, 0);

    double val = 20;
    for (int i = 0; i < 50; i++) {
        double inc = pid.calculate(0, val);
        printf("times: %d val:% 7.3f inc:% 7.3f\n", i, val, inc);
        val += inc;
    }

    return 0;
}
