#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    if (!client.call(srv)) {
        ROS_ERROR("Failed to call service /ball_chaser/command_robot");
    }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;

    // Variables to track position of the white ball
    int ball_column = -1;
    bool ball_found = false;

    // Loop through the image, checking RGB values for white
    for (int i = 0; i < img.height * img.step; i += 3) {
        int r = img.data[i];
        int g = img.data[i + 1];
        int b = img.data[i + 2];

        if (r == 255 && g == 255 && b == 255) {
            ball_column = (i % img.step) / 3; // column index of white pixel
            ball_found = true;
            break;
        }
    }

    if (ball_found) {
        int third = img.width / 3;

        if (ball_column < third) {
            // Left section
            drive_robot(0.0, 0.5);
        }
        else if (ball_column < 2 * third) {
            // Center section
            drive_robot(0.5, 0.0);
        }
        else {
            // Right section
            drive_robot(0.0, -0.5);
        }
    } else {
        // Stop the robot if no white ball is found
        drive_robot(0.0, 0.0);
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



