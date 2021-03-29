#include <ros/ros.h>
#include <stdlib.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include "motorcycle_gz/input.h"

float input_force;
int input_v;
float input_d;
float input_t;
ros::Publisher Bwheel_pub;
ros::Publisher FrontFork_pub;

void GetInputValue(const motorcycle_gz::input &msg)
{
	input_force = msg.force;
	input_d = msg.d;
	input_t = msg.t;
}

void set_force(float back_wheel)
{
	std_msgs::Float64 msg;
	msg.data = back_wheel;
	ROS_INFO("msg.data = %f", msg.data);
	Bwheel_pub.publish(msg);
}
void set_position(float direction)
{
	std_msgs::Float64 msg;
	msg.data = direction;
	FrontFork_pub.publish(msg);
}

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
	ros::init(argc, argv, "motorcycle");
	ros::NodeHandle nh;
	ros::Subscriber Input_subscribe;
	ros::Rate loop_rate(30);

	Input_subscribe = nh.subscribe("/loadparameter/inputdata", 1000, GetInputValue);
	Bwheel_pub = nh.advertise<std_msgs::Float64>("/motorcycle/Bwheel_Joint_effort_controller/command", 1000);
	FrontFork_pub = nh.advertise<std_msgs::Float64>("/motorcycle/FrontFork_Joint_position_controller/command", 1000);

	float back_wheel = 0;
	float direction = 0;
	float time = 0;

	while (nh.ok())
	{
		ros::spinOnce();
		back_wheel = input_force;
		// ROS_INFO("back_wheel = %f", back_wheel);
		set_force(back_wheel);
		direction = input_d;
		// ROS_INFO("direction = %f", direction);
		set_position(direction);
		time = input_t * 1000;
		// ROS_INFO("time = %f", time);
		Delay(time);
		loop_rate.sleep();
	}
	return 0;
}
