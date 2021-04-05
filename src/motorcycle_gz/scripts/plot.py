#!/usr/bin/env python 
import rospy
from std_msgs.msg import String
from motorcycle_gz.msg import driveJoint
from sensor_msgs.msg import JointState
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

global vGoal 
global vCurrent 
global vGoal_list
global vCurrent_list
global time
global count
vGoal = 60
vCurrent = -1
vGoal_list = []
vCurrent_list = []
time = []
count = 0

def callback(data):
    global vGoal
    global tempvGoal_list
    # rospy.loginfo("velocity_goal : %f", data.velocity_goal)
    vGoal = data.velocity_goal
    # rospy.loginfo("vGoal : %f", vGoal)

def callback2(data):
    global vGoal 
    global vCurrent
    global vGoal_list
    global vCurrent_list
    global time
    global count
    # rospy.loginfo("velocity_current : %f", data.velocity[0])
    vCurrent = data.velocity[0]

    vCurrent_list.append(vCurrent)
    vGoal_list.append(vGoal)
    if count == 0:
        time.append(count)
    else:
        time.append(count/1000)
    count = count + 1

    if count >= 50000:
        del vGoal_list[0]
        del vCurrent_list[0]
        del time[0]
        
    # rospy.loginfo("vCurrent : %f", vCurrent)

def listener():
    global vGoal
    global vCurrent
    
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('/velocity_goal', driveJoint, callback)
    rospy.Subscriber('/motorcycle/joint_states', JointState, callback2)
    # rate = rospy.Rate(1000)
    
    while not rospy.is_shutdown():
        # rospy.loginfo("hello_str")
        # rospy.loginfo("vGoal : %f", vGoal)
        # rospy.loginfo("vCurrent : %f", vCurrent)
        if vCurrent!=-1:
            # rospy.loginfo("hello_str")
            # print(vGoal_list)
            # print(vCurrent_list)
            if count >= 50000:
                plt.xlim(xmin =  0+(count/10000) , xmax = 50+(count/10000))
                rospy.loginfo(count)
            else:
                plt.xlim(xmin =  0 , xmax = 50);
                rospy.loginfo(count)
            plt.ylim(ymin =  0 , ymax = 150);
            plt.plot(time, vGoal_list, color='red') 
            plt.plot(time, vCurrent_list, color='blue') 
            plt.title("Test Chart", fontsize=24)
            plt.xlabel("x-Value", fontsize=14)
            plt.ylabel("y-Value", fontsize=14)
            plt.tick_params(axis='both', labelsize=12, color='red')
            # plt.show()
            plt.savefig('plot.png')

        # rate.sleep()

if __name__ == '__main__':
    listener()






