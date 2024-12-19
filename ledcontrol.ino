#include <ros.h>
#include <std_msgs/String.h>

const int LED_PIN = 13; // Change to your LED pin

ros::NodeHandle nh;

void messageCallback(const std_msgs::String& msg) {
  Serial.print("Received: ");
  Serial.println(msg.data); // Print the received message

  if (strcmp(msg.data, "ON") == 0) { 
    digitalWrite(LED_PIN, HIGH); // Turn LED on
    Serial.println("LED is ON");
  } else if (strcmp(msg.data, "OFF") == 0) {
    digitalWrite(LED_PIN, LOW); // Turn LED off
    Serial.println("LED is OFF");
  } else if (strcmp(msg.data, "BLINK") == 0) {
    digitalWrite(LED_PIN, HIGH); // Turn LED off
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
    Serial.println("LED is blink");
  } else {
    Serial.println("Unknown command"); // Handle invalid commands
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
