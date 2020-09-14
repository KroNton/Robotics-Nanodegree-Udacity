
#ROS&&Gazebo simulation
Gazebo Components
There are six components involved in running an instance of a Gazebo simulation:
Gazebo Server
Gazebo Client
World Files
Model Files
Environment Variables
Plugins
---------
1- Gazebo Server:It is responsible for parsing the description files related to the scene we are trying to simulate"$ gzserver"

2- Gazebo Client:on the other hand provides the very essential Graphical Client that connects to the gzserver "$ gzclient"

It is a common practice to run gzserver first, followed by gzclient, allowing some time to initialize the simulation scene or run "$ gazebo"To interact with a world, model, or sensor in Gazebo, you can write plugins. These plugins can be either loaded from the command line or added to your SDF world file.

3- World Files: A world file in Gazebo contains all the elements in the simulated environment. These elements are your robot model, its environment, lighting, sensors, and other objects,usually has a ".world" extension. 
-The world file is formatted using the SDF(Simulation Description Format):

4- Model Files: you must create a separate SDF file of your robot with exactly the same format as your world file. This model file should only represent a single model (ex: a robot) and can be imported by your world file.

5-Environment Variables:There are many environment variables that Gazebo uses, primarily to locate files (world, model, …) and set up communications between gzserver and gzclient. 

6- Plugins: To interact with a world, model, or sensor in Gazebo, you can write plugins. These plugins can be either loaded from the command line or added to your SDF world file.
--------------------
###Build the cpp plugin file:
1- Create a directory for scripts inside “myrobot” to store a hello.cpp file
2- Create a CMakeLists.txt file out of the dir
3-$ cd /home/workspace/myrobot
  $ mkdir build
  $ cd build/
  $ cmake ../
  $ make # You might get errors if your system is not up to date!
   --------------------
###How to set gazebo plugin path:
site: "https://answers.gazebosim.org//question/13391/how-to-set-gazebo_plugin_path-correctly-and-add-the-plugin-into-gazebo_ros/"

--->>>you can see your current GAZEBO_PLUGIN_PATH by the command
>>>>>"$echo GAZEBO_PLUGIN_PATH"
The path should point directly to the folder where the .so file is located (for example the build folder).
--->>>To clean the variable use 
>>>>>"$unset GAZEBO_PLUGIN_PATH" , then check again the variable: echo $GAZEBO_PLUGIN_PATH (no nothing should be returned)

--->>>Now you have to navigate in terminal to the folder where the .so file is located (since pwd is the current folder). After using :
>>>>>"$export GAZEBO_PLUGIN_PATH=$PWD" 
your variable should be set correctly. (overwrites existing values)
   -------------------
4- Open your world file and attach the plugin to it
   $ cd /home/workspace/myrobot/world/
   $ gedit myworld
     add this line to myworld file "<plugin name="hello" filename="libhello.so"/>"

5-Launch the world file in Gazebo to load both the world and the plugin
$ cd /home/workspace/myrobot/world/
$ gazebo myworld
$ gazebo myworld --verbose #in case of errors to declear it


