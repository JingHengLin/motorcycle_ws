# motorcycle_ws

How to use:
terminal 1:
	cd motorcycle_ws
	catkin_make
	source devel/setup.bash
	roslaunch motorcycle_gz motorcycle_world.launch
	press space in Gazebo
terminal 2:(crtl+shift+T)
	source devel/setup.bash
	roslaunch rosbridge_server rosbridge_websocket.launch
	double click computer.html check whether it is connected
terminal 3:(crtl+shift+T)
	source devel/setup.bash
	roslaunch motorcycle_gz motorcycle.launch


20210203 NEW terminal 1:
cd motorcycle_ws
catkin_make
source src/scripts/env.sh
roslaunch motorcycle_gz motorcycle_world.launch

