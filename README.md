# Robotics-Nanodegree-Udacity

-common job titles in Robotics:

Data Scientist, Natural Language Processing
Computer Vision Engineer
NLP (neural-linguistic programming) Scientist
Watson Machine Learning Engineer
Software Engineer
Deep Learning Engineer
Software Engineer - Vision
-----------------------------------------------
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

