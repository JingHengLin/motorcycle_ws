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
#include "motorcycle_gz/input.h"
using namespace std;

// check input
// --------------------------
#define parameterData 2
// --------------------------
string force = "force";
string v = "velocity";
string d = "direction";
string t = "time";
string e = "=";
double parameter_force[100];
int parameter_v[100];
double parameter_d[100];
double parameter_t[100];
// void readvalue(string v, string d, string t);
void readvalue(string force, string d, string t);

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

void readvalue(string force, string d, string t)
{
	ifstream in("/home/iclab/motorcycle_ws/src/motorcycle_gz/src/parameter_force.txt");
	string line;
	char buffer[100];
	int ans = atoi(buffer);
	double ansf = atof(buffer);
	int i = 0;
	int j = 0;
	int k = 0;
	if (in)
	{
		while (getline(in, line, ' '))
		{
			// if (line == v)
			// {
			// 	++i;
			// 	getline(in, line, ' ');
			// 	if (line == e)
			// 	{
			// 		getline(in, line, '\n');
			// 		strcpy(buffer, line.c_str());
			// 		ans = atoi(buffer);
			// 		parameter_v[i] = ans;
			// 		ROS_INFO("read from data (velocity) : %d", parameter_v[i]);
			// 	}
			// }
			if (line == force)
			{
				++i;
				getline(in, line, ' ');
				if (line == e)
				{
					getline(in, line, '\n');
					strcpy(buffer, line.c_str());
					ansf = atof(buffer);
					parameter_force[i] = ansf;
					ROS_INFO("read from data (force) : %f", parameter_force[i]);
				}
			}
			if (line == d)
			{
				++j;
				getline(in, line, ' ');
				if (line == e)
				{
					getline(in, line, '\n');
					strcpy(buffer, line.c_str());
					ansf = atof(buffer);
					parameter_d[j] = ansf;
					ROS_INFO("read from data (direction) : %f", parameter_d[j]);
				}
			}
			if (line == t)
			{
				++k;
				getline(in, line, ' ');
				if (line == e)
				{
					getline(in, line, '\n');
					strcpy(buffer, line.c_str());
					ansf = atof(buffer);
					parameter_t[k] = ansf;
					ROS_INFO("read from data (time) : %f", parameter_t[k]);
				}
			}
		}
	}
	else
	{
		cout << "no such file" << endl;
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "loadparameter");
	ros::NodeHandle nh;
	ros::Publisher Bwheel_pub;
	ros::Publisher FrontFork_pub;
	ros::Publisher force_time;
	Bwheel_pub = nh.advertise<motorcycle_gz::input>("/loadparameter/inputdata", 1000);
	FrontFork_pub = nh.advertise<motorcycle_gz::input>("/loadparameter/inputdata", 1000);
	force_time = nh.advertise<motorcycle_gz::input>("/loadparameter/inputdata", 1000);
	ros::Rate loop_rate(30);

	readvalue(force, d, t);
	Delay(500);
	for (int i = 1; i <= parameterData; i++)
	{
		motorcycle_gz::input msg;
		msg.force = parameter_force[i];
		msg.d = parameter_d[i];
		msg.t = parameter_t[i];
		ROS_INFO("msg.force = %f", msg.force);
		ROS_INFO("msg.d = %f", msg.d);
		ROS_INFO("msg.t = %f", msg.t);
		Bwheel_pub.publish(msg);
		FrontFork_pub.publish(msg);
		force_time.publish(msg);
		Delay(1000);
		loop_rate.sleep();
	}
	return 0;
}
