#include <ros/ros.h>
#include <stdlib.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include "motorcycle_gz/input.h"

int input_v;
int input_d;
int input_t;
ros::Publisher wheel_back_pub;
ros::Publisher direction_pub;

void GetInputValue(const motorcycle_gz::input &msg)
{
	input_v = msg.v;
	input_d = msg.d;
	input_t = msg.t;
}

void set_velocity(float back_wheel)
{
	std_msgs::Float64 msg;
	msg.data = back_wheel;
	wheel_back_pub.publish(msg);
}
void set_position(float direction)
{
	std_msgs::Float64 msg;
	msg.data = direction;
	direction_pub.publish(msg);
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
	wheel_back_pub = nh.advertise<std_msgs::Float64>("/motorcycle/wheel_back_joint_velocity_controller/command", 1000);
	direction_pub = nh.advertise<std_msgs::Float64>("/motorcycle/direction_joint_position_controller/command", 1000);

	int back_wheel = 0;
	float direction = 0;
	int velocity_time = 0;

	while (nh.ok())
	{
		ros::spinOnce();
		back_wheel = input_v;
		set_velocity(back_wheel);
		direction = input_d;
		set_position(direction);
		velocity_time = input_t * 1000;
		Delay(velocity_time);
		loop_rate.sleep();
	}
	return 0;
}
