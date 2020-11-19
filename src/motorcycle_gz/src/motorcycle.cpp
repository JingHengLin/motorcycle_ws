#include <ros/ros.h>
#include <stdlib.h>
#include <stdio.h>
#include <std_msgs/Float64.h>
#include "motorcycle_gz/input.h"

// ros::Publisher wheel_front_pub;
ros::Publisher wheel_back_pub;

// int input_x;
int input_y;

void GetInputValue(const motorcycle_gz::input &msg)
{
    // input_x = msg.x;
	ROS_INFO("12312313");
    input_y = msg.y;
}

// void set_velocity(float front_wheel, float back_wheel)
// {
// 	std_msgs::Float64 msg;
// 	msg.data = front_wheel;
// 	wheel_front_pub.publish(msg);
// 	msg.data = back_wheel;
// 	wheel_back_pub.publish(msg);
// }
void set_velocity(float back_wheel)
{
	std_msgs::Float64 msg;
	msg.data = back_wheel;
	wheel_back_pub.publish(msg);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "motorcycle");
	ros::NodeHandle nh;
	ros::Subscriber Input_subscribe;
	ros::Rate loop_rate(30);
	// Input_subscribe = nh.subscribe("/web/inputdata", 1000, GetInputValue);
	Input_subscribe = nh.subscribe("/loadparameter/inputdata", 1000, GetInputValue);

	// wheel_front_pub = nh.advertise<std_msgs::Float64>("/motorcycle/wheel_front_joint_velocity_controller/command", 1000);
	wheel_back_pub = nh.advertise<std_msgs::Float64>("/motorcycle/wheel_back_joint_velocity_controller/command", 1000);


	// float front_wheel = 0;
    float back_wheel = 0;

	// std::printf("Set front_wheel velocity: ");
	// std::scanf("%f", &front_wheel);
	// std::printf("Set back_wheel velocity: ");
	// std::scanf("%f", &back_wheel);

	while (nh.ok())
    {
		ros::spinOnce();
        // front_wheel = input_x;
		back_wheel = input_y;
		ROS_INFO("back_wheel test = %d", input_y);
		// set_velocity( front_wheel, back_wheel);
        set_velocity(back_wheel);
		loop_rate.sleep();
    }
	return 0;
}
