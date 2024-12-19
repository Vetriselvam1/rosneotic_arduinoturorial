#include <ros/ros.h>
#include <visualization_msgs/Marker.h> // Correct header for Marker messages

int main(int argc, char** argv)
{
  ros::init(argc, argv, "test_marker_publisher");
  ros::NodeHandle nh;

  // Advertise the visualization_marker topic
  ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10); 

  ros::Rate loop_rate(1); // Publish rate of 1 Hz
  
  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    marker.header.frame_id = "map"; // Make sure this matches the Fixed Frame in RViz
    marker.header.stamp = ros::Time::now();
    marker.ns = "test_marker";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::SPHERE; // Example: Sphere marker
    marker.action = visualization_msgs::Marker::ADD;

    // Position of the marker
    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 1.0;

    // Orientation of the marker
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Scale of the marker
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Color of the marker
    marker.color.r = 1.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0f; // Alpha for visibility

    marker_pub.publish(marker); // Publish the marker

    ros::spinOnce(); // Handle ROS communication
    loop_rate.sleep(); // Wait for the next cycle
  }

  return 0;
}
