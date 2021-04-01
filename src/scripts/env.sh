#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source ${DIR}/../../devel/setup.bash
# My_Gazebo_Model_Path="$( cd "${DIR}/../models" && pwd )"
# export GAZEBO_MODEL_PATH=${My_Gazebo_Model_Path}

gnome-terminal \
--window -e 'bash -c "cd ~/motorcycle_ws; killall rosmaster; killall gzserver; killall gzclient; roscore"' \
--tab -e 'bash -c "sleep 1; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_world.launch"' \
--tab -e 'bash -c "sleep 3; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_force.launch"' \
--tab -e 'bash -c "sleep 5; source devel/setup.bash; rosrun  motorcycle_gz velocity_sub"' \
--tab -e 'bash -c "sleep 5; source devel/setup.bash; rosrun  motorcycle_gz velocity_goal"'

# gnome-terminal \
# --window -e 'bash -c "cd ~/motorcycle_ws; roscore"' \
# --tab -e 'bash -c "sleep 5; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_world.launch"' \
# --tab -e 'bash -c "sleep 5; source devel/setup.bash; roslaunch rosbridge_server rosbridge_websocket.launch"' \
# --tab -e 'bash -c "sleep 5; source devel/setup.bash; roslaunch motorcycle_gz motorcycle_force.launch"'

# alias motorcycle_world_launch="source devel/setup.bash && roslaunch motorcycle_gz motorcycle_world.launch"
# alias motorcycle_launch="source devel/setup.bash && roslaunch motorcycle_gz motorcycle.launch"

# xdotool type 'source devel/setup.bash' && xdotool key Return
# xdotool type 'roslaunch motorcycle_gz motorcycle.launch' && xdotool key Return