# create workspace
$ mkdir -p catkin_ws/src
$ cd /home/workspace/catkin_ws/src
$ catkin_init_workspace   #to create CMakeLists.txt file#
$ cd /home/workspace/catkin_ws
$ catkin_make

The devel directory does contain something of interest, a file named setup.bash. This setup.bash script must be sourced before using the catkin workspace with source devel/setup.bash

-----------------------
how to choose good queue_size: 
http://wiki.ros.org/rospy/Overview/Publishers%20and%20Subscribers  [1.4]
-----------------------

