#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/Float64.h>

ros::Publisher wheel_front_pub;
ros::Publisher wheel_back_pub;

void set_velocity(float front_wheel, float back_wheel)
{
	std_msgs::Float64 msg;
	msg.data = front_wheel;
	wheel_front_pub.publish(msg);
	msg.data = back_wheel;
	wheel_back_pub.publish(msg);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "motorcycle");
	ros::NodeHandle nh;

	wheel_front_pub = nh.advertise<std_msgs::Float64>("/motorcycle/wheel_front_joint_velocity_controller/command", 10);
	wheel_back_pub = nh.advertise<std_msgs::Float64>("/motorcycle/wheel_back_joint_velocity_controller/command", 10);


	float front_wheel = 0,
          back_wheel = 0;

	std::printf("Set front_wheel velocity: ");
	std::scanf("%f", &front_wheel);
	std::printf("Set back_wheel velocity: ");
	std::scanf("%f", &back_wheel);
	set_velocity( front_wheel, back_wheel);

	return 0;
}
