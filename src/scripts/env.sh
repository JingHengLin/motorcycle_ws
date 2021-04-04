#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source ${DIR}/../../devel/setup.bash
# My_Gazebo_Model_Path="$( cd "${DIR}/../models" && pwd )"
# export GAZEBO_MODEL_PATH=${My_Gazebo_Model_Path}

gnome-terminal \
--window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
--tab -e 'bash -c "sleep 1; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_world.launch"' \
--tab -e 'bash -c "sleep 5; source devel/setup.bash; rosrun motorcycle_gz p_controller"'



# ------------------------------------------------Record------------------------------------------------------------------------------------------
# # Gazebo Constant Speed 60 PD Controller
# gnome-terminal \
# --window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
# --tab -e 'bash -c "sleep 1; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_world.launch"' \
# --tab -e 'bash -c "sleep 5; source devel/setup.bash; rosrun motorcycle_gz p_controller"'

# # PID Template
# gnome-terminal \
# --window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
#  rosrun motorcycle_gz pid_example"' #******* open another terminal use rosrun to execute*******


# # GazeboReadFileForce
# gnome-terminal \
# --window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
# --tab -e 'bash -c "sleep 1; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_world.launch"' \
# --tab -e 'bash -c "sleep 3; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_force.launch"' \

# # nodePub
# gnome-terminal \
# --window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
# --tab -e 'bash -c "sleep 3; source devel/setup.bash; rosrun motorcycle_gz velocity_goal"' 

# # GazeboVelocitySub
# gnome-terminal \
# --window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
# --tab -e 'bash -c "sleep 1; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_world.launch"' \
# --tab -e 'bash -c "sleep 3; source devel/setup.bash; rosrun motorcycle_gz velocity_sub"' \

# # webPub nodeSub
# gnome-terminal \
# --window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
# --tab -e 'bash -c "sleep 1; source devel/setup.bash; roslaunch rosbridge_server rosbridge_websocket.launch"' \
# --tab -e 'bash -c "sleep 3; source devel/setup.bash; rosrun motorcycle_gz velocity_goal_web"' 

