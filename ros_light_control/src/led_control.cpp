#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_ledcontrol");
  ros::NodeHandle nh;

  if (argc < 2) {
    ROS_ERROR("Usage: rosrun ros_light_control ros_ledcontrol_node <command>");
    return 1;
  }

  // Command-line argument for the message
  std::string command = argv[1];

  // Create a publisher to send a string message
  ros::Publisher pub = nh.advertise<std_msgs::String>("character_topic", 1000);

  ros::Rate loop_rate(1);  // Publish rate (1 Hz)

  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = command;  // Use the command as the message data

    ROS_INFO("Publishing: %s", command.c_str());
    pub.publish(msg);  // Publish the message

    ros::spinOnce();  // Handle ROS communication
    loop_rate.sleep();  // Wait for the next cycle
  }

  return 0;
}
