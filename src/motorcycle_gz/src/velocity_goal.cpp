#define _CRT_SECURE_NO_WARNINGS
#include <ros/ros.h>
#include <ros/package.h>
#include <sys/time.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include "motorcycle_gz/driveJoint.h"
using namespace std;

void Delay(int timedelay)
{
	double timeuse;
	struct timeval tstart, tend; 
	gettimeofday(&tstart, NULL);
	gettimeofday(&tend, NULL);
	timeuse = (1000000 * (tend.tv_sec - tstart.tv_sec) + (tend.tv_usec - tstart.tv_usec)) / 1000;
	while (timeuse <= timedelay)
	{
		gettimeofday(&tend, NULL);
		timeuse = (1000000 * (tend.tv_sec - tstart.tv_sec) + (tend.tv_usec - tstart.tv_usec)) / 1000;
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "velocity_goal");
	ros::NodeHandle nh;
	ros::Publisher velocity_goal_pub;
	velocity_goal_pub = nh.advertise<motorcycle_gz::driveJoint>("/velocity_goal", 1000);
	ros::Rate loop_rate(1000);
	motorcycle_gz::driveJoint msg;
	float v_goal = 50; 
	int count = 0;
	while (nh.ok())
	{
		msg.velocity_goal = v_goal;
		velocity_goal_pub.publish(msg);
		if((++count)==1000){
			ROS_INFO("msg.velocity_goal = %f", msg.velocity_goal);
			count = 0;
		}
		loop_rate.sleep();
	}
	return 0;
}
