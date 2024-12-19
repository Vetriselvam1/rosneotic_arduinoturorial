#include <ros.h>
#include <std_msgs/String.h>

const int LED_PIN = 13; // Change to your LED pin

ros::NodeHandle nh;

void messageCallback(const std_msgs::String& msg) {
  Serial.println(msg.data); // Directly print the received string
  if (strcmp(msg.data, "A") == 0) { // Compare strings using strcmp
    digitalWrite(LED_PIN, HIGH); // Turn LED on
  } else {
    digitalWrite(LED_PIN, LOW); // Turn LED off
  }
}

ros::Subscriber<std_msgs::String> sub("character_topic", &messageCallback);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  delay(10);
}
