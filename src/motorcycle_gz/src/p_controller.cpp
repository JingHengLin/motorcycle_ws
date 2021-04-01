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
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>
#include "motorcycle_gz/driveJoint.h"
#include "pid.h"
using namespace std;


float v_goal = 60, v_current = 0; 
float drive_force = 0;
float drive_direction = 0;
ros::Publisher force_pub;
ros::Publisher direction_pub;

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

void set_force(float force)
{
	std_msgs::Float64 msg;
	msg.data = force;
	force_pub.publish(msg);
}
void set_position(float direction)
{
	std_msgs::Float64 msg;
	msg.data = direction;
	direction_pub.publish(msg);
}
void GetInputValue(const sensor_msgs::JointState &msg)
{
	v_current = msg.velocity[0];
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "p_controller");
	ros::NodeHandle nh;
	ros::Subscriber velocity_sub;
	velocity_sub = nh.subscribe("/motorcycle/joint_states", 1000, GetInputValue);
	direction_pub = nh.advertise<std_msgs::Float64>("/motorcycle/FrontFork_Joint_position_controller/command", 1000);
	force_pub = nh.advertise<std_msgs::Float64>("/motorcycle/Bwheel_Joint_effort_controller/command", 1000);
	ros::Rate loop_rate(1000);
	PID pid = PID(0.001, 100000, -100000, 800, 0, 20);

	int time_ROSINFO = 0;
	float inc = 0;
	while (nh.ok())
	{
		ros::spinOnce();
		inc = pid.calculate(v_goal, v_current);
		drive_force += inc;
		set_force(drive_force);
		set_position(drive_direction);
		if ((++time_ROSINFO) == 500){
			time_ROSINFO = 0;
			ROS_INFO("direction, v_goal, force, v_current : %f %f %f %f", drive_direction, v_goal, drive_force, v_current);
		}

		loop_rate.sleep();
	}
	return 0;
}
