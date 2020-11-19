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

void readvalue(string v);
string v = "velocity";
string e = "=";
int parameter[100]; 

void Delay(int timedelay)
{
    double timeuse;
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);
    gettimeofday(&tend, NULL);
    timeuse = (1000000*(tend.tv_sec - tstart.tv_sec) + (tend.tv_usec - tstart.tv_usec))/1000;
    while (timeuse <= timedelay) {
        gettimeofday(&tend, NULL);
        timeuse = (1000000*(tend.tv_sec - tstart.tv_sec) + (tend.tv_usec - tstart.tv_usec))/1000;
    }
}

void readvalue(string v)
{
	ifstream in("/home/iclab/motorcycle_ws/src/motorcycle_gz/src/parameter.txt");

	string line;
	char buffer[100];
	int ans = atoi(buffer);
	int i = 0;
	if(in) 
	{
		while (getline (in, line, ' ')) 
		{ 	
			++i;	
			if(line == v){
				getline (in, line, ' ');
				if(line == e){
					getline (in, line, '\n');
					strcpy(buffer, line.c_str());
					ans = atoi(buffer);
					parameter[i] = ans;
					ROS_INFO("test 1111111");
					ROS_INFO("test %d", parameter[i]);
					// cout << parameter[i] << endl;
				}
			}
		}
	}
	else 
	{
		cout <<"no such file" << endl;
	}	
}

int main(int argc, char** argv){
	int data = 2;
	
	ros::init(argc, argv, "loadparameter");
	ros::NodeHandle nh;
	ros::Publisher wheel_back_pub;
	wheel_back_pub = nh.advertise<motorcycle_gz::input>("/loadparameter/inputdata", 1000);
	ros::Rate loop_rate(10);
	readvalue(v);
	ROS_INFO("test 2222222");
	// wheel_back_pub.publish(msg);
	// loop_rate.sleep();
	int i;
	Delay(500);
	for(i=1; i<=data; i++){
		motorcycle_gz::input msg;
		msg.y = parameter[i];
		ROS_INFO("msg.y = %d", msg.y);
		wheel_back_pub.publish(msg);
		ROS_INFO("test 333333333");
		Delay(1000);
		loop_rate.sleep();
    	// ros::spinOnce();
	}
	return 0;
}

	
	
	
			


