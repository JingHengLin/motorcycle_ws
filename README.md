# motorcycle_ws

## How to use:
20210205 (3 edition):
```
ctrl+alt+t:
	cd ~/motorcycle_ws
	catkin_make
	source src/scripts/env.sh 
```

---
Old Version (Hide):
<!-- 20210203 (2 edition):
```
1. ctrl+alt+t:
	cd ~/motorcycle_ws
	catkin_make
	source src/scripts/env.sh (DIR: /home/iclab/motorcycle_ws/src/scripts)  
	source src/scripts/motorcycle_world_launch.sh  
2. ctrl+shift+t:
	source src/scripts/rosbridge_websocket_launch.sh  
3. ctrl+shift+t:
	source src/scripts/motorcycle_launch.sh  
``` -->
<!-- 
(1 edition):
* terminal 1:
```
	cd motorcycle_ws
	catkin_make
	source devel/setup.bash
	roslaunch motorcycle_gz motorcycle_world.launch
```
press space in Gazebo

* terminal 2:(crtl+shift+T)
```
	source devel/setup.bash
	roslaunch rosbridge_server rosbridge_websocket.launch
```
double click computer.html check whether it is connected

* terminal 3:(crtl+shift+T)
```
	source devel/setup.bash
	roslaunch motorcycle_gz motorcycle.launch
``` -->
---




---
## tool_gz
	/src/add_model.cpp : not sure how to use

---
## Add model in Gazebo base : 
* Method 1 :
pull model in /home/iclab/.gazebo/models.
We can see model show in Gazebo "insert".
* Method 2 :
pull model in /usr/share/gazebo-9/models
We can see model show in Gazebo "insert".
	* if you want remove:
	```
	cd /usr/share/gazebo-9
	sudo chmod 777 models/
	cd models/
	rm -r TestGazeboPlaneMax2016/
	cd ..
	sudo chmod 755 models/
	```


