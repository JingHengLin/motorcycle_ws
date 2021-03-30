#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source ${DIR}/../../devel/setup.bash
# My_Gazebo_Model_Path="$( cd "${DIR}/../models" && pwd )"
# export GAZEBO_MODEL_PATH=${My_Gazebo_Model_Path}

gnome-terminal \
--window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
--tab -e 'bash -c "sleep 5; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_world.launch"'

