#include <ros/ros.h>
#include <stdlib.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>
#include "motorcycle_gz/driveJoint.h"

// float drive_force;
// float drive_direction;
// float drive_time;
// ros::Publisher force_pub;
// ros::Publisher direction_pub;
float feedback_velocity;

void GetInputValue(const sensor_msgs::JointState &msg)
{
	feedback_velocity = msg.velocity[0];
}

// void set_force(float force)
// {
// 	std_msgs::Float64 msg;
// 	msg.data = force;
// 	force_pub.publish(msg);
// }
// void set_position(float direction)
// {
// 	std_msgs::Float64 msg;
// 	msg.data = direction;
// 	direction_pub.publish(msg);
// }

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
	ros::init(argc, argv, "velocity_sub");
	ros::NodeHandle nh;
	ros::Subscriber velocity_sub;
	ros::Rate loop_rate(1000);

	velocity_sub = nh.subscribe("/motorcycle/joint_states", 1000, GetInputValue);
	// force_pub = nh.advertise<std_msgs::Float64>("/motorcycle/Bwheel_Joint_effort_controller/command", 1000);
	// direction_pub = nh.advertise<std_msgs::Float64>("/motorcycle/FrontFork_Joint_position_controller/command", 1000);

	// float timekeep = 0; // time of force and direction keep 
	while (nh.ok())
	{
		ros::spinOnce();
		// if (drive_force!=0){
		// 	ROS_INFO("motorcycle_force : back_wheel = %f", drive_force);
		// }
		// set_force(drive_force);
		// set_position(drive_direction);
		// timekeep = drive_time * 1000;
		// Delay(timekeep);
		ROS_INFO("feedback_velocity = %f", feedback_velocity);
		Delay(1000);
		loop_rate.sleep();
	}
	return 0;
}
