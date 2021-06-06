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
#include <sensor_msgs/Imu.h>
#include "motorcycle_gz/driveJoint.h"
#include "pid.h"
using namespace std;

// ROS Subscribe : Velocity
float v_goal = 10, v_current = 0; 
// ROS Subscribe : Get current quaternion from Gazebo parameter
float orientation_x = 0;
float orientation_y = 0;
float orientation_z = 0;
float orientation_w = 0;
// ROS Subscribe : Euler-Angles
float rpy_angle_rad[3] = {0.0, 0.0, 0.0};
float rpy_angle_deg[3] = {0.0, 0.0, 0.0};

// ROS Publisher : Force
float drive_force = 0;
ros::Publisher force_pub;
// ROS Publisher : Direction
float drive_direction = 0;
ros::Publisher direction_pub;

void Delay(int timedelay);
void GetGoalVelocity(const motorcycle_gz::driveJoint &msg);
void GetCurrentVelocity(const sensor_msgs::JointState &msg);
void GetQuaternion(const sensor_msgs::Imu &imu_data);
void QuaternionEuler();
void RadiusDegree();
void set_force(float force);
void set_position(float direction);


int main(int argc, char **argv)
{
	ros::init(argc, argv, "motorcycle_state");
	ros::NodeHandle nh;

	// ROS Subscribe : Get input velocity from web
	ros::Subscriber velocity_goal_sub;
	velocity_goal_sub = nh.subscribe("/velocity_goal", 1000, GetGoalVelocity);
	// ROS Subscribe : Get current velocity from Gazebo
	ros::Subscriber velocity_current_sub;
	velocity_current_sub = nh.subscribe("/motorcycle/joint_states", 1000, GetCurrentVelocity);
	// ROS Subscribe : Get current quaternion from Gazebo 
	ros::Subscriber quaternion_sub;
	quaternion_sub = nh.subscribe("/imu", 1000, GetQuaternion);
	
	// ROS Publisher : force to back wheel, pid force
	PID pid_force = PID(0.001, 1, -1, 8, 3, 1);
	float inc_force = 0;
	force_pub = nh.advertise<std_msgs::Float64>("/motorcycle/Bwheel_Joint_effort_controller/command", 1000);
	// ROS Publisher : direction, pid direction
	PID pid_dir = PID(0.001, 1, -1, 0.001, 0, 0);
	float inc_direction = 0;
	direction_pub = nh.advertise<std_msgs::Float64>("/motorcycle/FrontFork_Joint_position_controller/command", 1000);

	// loop rate
	ros::Rate loop_rate(1000);
	
	// Print Value In Terminal : time counter
	int time_ROSINFO = 0;
	int counter = 0;

	while (nh.ok())
	{
		ros::spinOnce();
		//////////////// PID Drive Force ////////////////
		inc_force = pid_force.calculate(v_goal, v_current);
		drive_force += inc_force;
		set_force(drive_force);
		//////////////// PID Drive Force ////////////////

		//////////////// Set Drive Direction ////////////////
		QuaternionEuler();
		RadiusDegree();
		inc_direction = pid_dir.calculate(0, rpy_angle_deg[0]) * (-1);
		drive_direction += inc_direction;
		if (drive_direction>5){
			drive_direction = 5;
		}
		else if(drive_direction<-5){
			drive_direction = -5;
		}
		set_position(drive_direction);
		//////////////// Set Drive Direction ////////////////

		//////////////// Print Value In Terminal ////////////////
		if (counter<1000 && (++time_ROSINFO) == 2){
			counter++;
			time_ROSINFO = 0;
			// ROS_INFO("direction, v_goal, force, v_current : %f %f %f %f", drive_direction, v_goal, drive_force, v_current);
			// ROS_INFO("quaternion (x, y, z, w): %f,%f,%f,%f", orientation_x, orientation_y, orientation_z, orientation_w);
			// ROS_INFO("rpy_angle_deg : %f,%f,%f", rpy_angle_deg[0], rpy_angle_deg[1], rpy_angle_deg[2]);
			ROS_INFO("v_current : %f, lean degree : %f, drive_direction : %f", v_current, rpy_angle_deg[0], drive_direction);
		}
		//////////////// Print Value In Terminal ////////////////

		loop_rate.sleep();
	}
	return 0;
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
void GetGoalVelocity(const motorcycle_gz::driveJoint &msg)
{
	v_goal = msg.velocity_goal;
}
void GetCurrentVelocity(const sensor_msgs::JointState &msg)
{
	v_current = msg.velocity[0];
}
void GetQuaternion(const sensor_msgs::Imu &imu_data)
{
	orientation_x = imu_data.orientation.x;
    orientation_y = imu_data.orientation.y;
    orientation_z = imu_data.orientation.z;
    orientation_w = imu_data.orientation.w;
}
// Convert Quaternions to Euler-Angles
void QuaternionEuler()
{
    rpy_angle_rad[0] = atan2(2 * (orientation_w * orientation_x + orientation_y * orientation_z), 1 - 2 * (orientation_x * orientation_x + orientation_y * orientation_y));
    rpy_angle_rad[1] = asin(2 * (orientation_w * orientation_y - orientation_z * orientation_x));
    rpy_angle_rad[2] = atan2(2 * (orientation_w * orientation_z + orientation_x * orientation_y), 1 - 2 * (orientation_y * orientation_y + orientation_z * orientation_z));
}
// radius to degree
void RadiusDegree()
{	
	int i=0;
	for(i=0; i<3; i++){
		rpy_angle_deg[i]=(rpy_angle_rad[i])*180/M_PI;
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



