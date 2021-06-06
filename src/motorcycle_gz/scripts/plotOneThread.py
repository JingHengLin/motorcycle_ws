#!/usr/bin/env python3 
import sys
sys.path.insert(1, '/home/user_name/.local/lib/python3.6/site-packages/')
sys.path.insert(0, '/opt/installer/open_cv/cv_bridge/lib/python3/dist-packages/')
import rospy
from cv_bridge import CvBridge
from cv_bridge.boost.cv_bridge_boost import getCvType
from sensor_msgs.msg import Image
from std_msgs.msg import String
from motorcycle_gz.msg import driveJoint
from sensor_msgs.msg import JointState
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import warnings
warnings.simplefilter("ignore", DeprecationWarning)

global vGoal 
global vCurrent 
global vGoal_list
global vCurrent_list
global time
global tmpvGoal_list
global tmpvCurrent_list
global tmptime
global count
global fig
global pub
global imgMsg
global _flag
global _flag2
vGoal = 15
vCurrent = -1
vGoal_list = []
vCurrent_list = []
time = []
tmpvGoal_list = []
tmpvCurrent_list = []
tmptime = []
count = 0
fig = plt.figure()
imgMsg = -1
_flag = False
_flag2 = True

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
    global tmpvGoal_list
    global tmpvCurrent_list
    global tmptime
    global time
    global count
    global _flag
    global _flag2
    if count%200 == 0:
        _flag = False

        vCurrent = data.velocity[0]
        tmpvCurrent_list.append(vCurrent)
        tmpvGoal_list.append(vGoal)
        if count == 0:
            tmptime.append(count)
        else:
            tmptime.append(count/1000)
        
        if count >= 20000:
            del tmpvGoal_list[0]
            del tmpvCurrent_list[0]
            del tmptime[0]

        if len(tmptime)==len(tmpvGoal_list) and len(tmptime)==len(tmpvCurrent_list):
            while(_flag2==False):
                continue
            vGoal_list = list(tmpvGoal_list)
            vCurrent_list = list(tmpvCurrent_list)
            time = list(tmptime)
            _flag = True
    count = count + 1

def listener():
    global pub
    global imgMsg
    global _flag
    global _flag2
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('/velocity_goal', driveJoint, callback)
    rospy.Subscriber('/motorcycle/joint_states', JointState, callback2)
    pub = rospy.Publisher('/image', Image, queue_size=1000)
    # rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        if _flag == True:
            _flag2 = False
            if count >= 20000:
                plt.xlim(xmin =  (count/1000)-20 , xmax = (count/1000))
                # rospy.loginfo(count)
            else:
                plt.xlim(xmin =  0 , xmax = 20);
                # rospy.loginfo(count)
            plt.ylim(ymin =  0 , ymax = 40);
            plt.title("Speed of Vehicle", fontsize=24)
            plt.xlabel("Times", fontsize=14)
            plt.ylabel("Velocity(m/s)", fontsize=14)
            plt.tick_params(axis='both', labelsize=12, color='red')
            plt.plot(time, vGoal_list, color='red') 
            plt.plot(time, vCurrent_list, color='blue') 
            _flag2 = True
            fig.canvas.draw()
            img = np.fromstring(fig.canvas.tostring_rgb(), dtype=np.uint8, sep='')
            img = img.reshape(fig.canvas.get_width_height()[::-1] + (3,))
            bridge = CvBridge()
            imgMsg = bridge.cv2_to_imgmsg(img, "bgr8")
            pub.publish(imgMsg)
        # plt.show()
        # plt.savefig('plot.png')
        # rate.sleep()

if __name__ == '__main__':
    listener()






