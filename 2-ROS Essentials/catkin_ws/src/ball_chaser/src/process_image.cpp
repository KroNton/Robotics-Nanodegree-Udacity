#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x  = lin_x;
    srv.request.angular_z = ang_z;

     
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
    float lin_x = 0.0, ang_z = 0.0;
    int img_left= (img.step / 3) ;
    int img_right = 2* img.step / 3;
    for (int pixel_num = 0; pixel_num < img.height * img.step; pixel_num+=3)
    {
       if (img.data[pixel_num]== white_pixel )
       {    
        
           int step_num = pixel_num % img.step;
           

           if (step_num < img_left )
           {
            //Left
           lin_x =0;
           ang_z =0.5; 
           }
           else if (step_num > img_left && step_num < img_right)
           {
            //Forward
           lin_x =0.5;
           ang_z =0; 
           }
           else if (step_num > img_right )
           {
            //Right
           lin_x=0;
           ang_z=-0.5; 
           }   
        }

     else
        {
            //Stop
           lin_x=0;
           ang_z=0; 
 
        }   
    
     drive_robot(0,0); 
    }
    
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
