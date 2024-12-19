#include <ros/ros.h>
#include <std_msgs/String.h>
#include <visualization_msgs/Marker.h>
#include <string>

// Marker Publisher
ros::Publisher marker_pub;

// Function to update the marker based on the LED state
void updateMarker(const std_msgs::String::ConstPtr& msg)
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = "map"; // Fixed Frame in RViz
    marker.header.stamp = ros::Time::now();
    marker.ns = "led_control";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::SPHERE; // Example: Sphere marker
    marker.action = visualization_msgs::Marker::ADD;

    // Common marker properties
    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 1.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set color based on the LED state
    if (msg->data == "ON") {
        marker.color.r = 0.0f;
        marker.color.g = 1.0f; // Green for ON
        marker.color.b = 0.0f;
        marker.color.a = 1.0f;
    } else if (msg->data == "OFF") {
        marker.color.r = 1.0f;
        marker.color.g = 0.0f;
        marker.color.b = 0.0f; // Red for OFF
        marker.color.a = 1.0f;
    } else if (msg->data == "BLINK") {
        static bool blink_state = true; // Toggle blink state
        marker.color.r = 1.0f;
        marker.color.g = 1.0f; // Yellow for BLINK
        marker.color.b = 0.0f;
        marker.color.a = blink_state ? 1.0f : 0.0f; // Toggle visibility
        blink_state = !blink_state;
    } else {
        ROS_WARN("Unknown command: %s", msg->data.c_str());
        return;
    }

    marker_pub.publish(marker);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "led_marker_visualizer");
    ros::NodeHandle nh;

    // Advertise the marker topic
    marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10);

    // Subscribe to the LED command topic
    ros::Subscriber sub = nh.subscribe("character_topic", 10, updateMarker);

    ros::Rate loop_rate(1); // Update rate for markers

    while (ros::ok()) {
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
