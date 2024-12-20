#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "character_publisher");
  ros::NodeHandle nh;

  // Create a publisher to send a string message
  ros::Publisher pub = nh.advertise<std_msgs::String>("character_topic", 1000);

  ros::Rate loop_rate(1);  // Publish rate (1 Hz)

  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "A";  // Character to send (can change as needed)

    pub.publish(msg);  // Publish the message

    ros::spinOnce();  // Handle ROS communication
    loop_rate.sleep();  // Wait for the next cycle
  }

  return 0;
}
