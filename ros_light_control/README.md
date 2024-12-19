
# ros_light_control Package

This package demonstrates how to control an LED using ROS Noetic and Arduino through serial communication. The package includes a publisher node that sends commands via ROS messages, and an Arduino program to control the LED based on these messages.

## Setup

### 1. Clone the Repository
Clone the repository to your ROS workspace:

```bash
cd ~/catkin_ws/src
git clone https://github.com/Vetriselvam1/rosneoticarduino_tutorials.git

### 2. Install Dependencies

Make sure you have the necessary ROS packages installed:

sudo apt-get install ros-noetic-rosserial-arduino ros-noetic-rosserial

### 3. Compile the Workspace

Navigate to your workspace and compile:

cd ~/catkin_ws
catkin_make
source devel/setup.bash

 ### 4.Arduino Setup

Upload the Arduino code from the led.ino file to your Arduino. Make sure the correct port and board type are selected in the Arduino IDE.
### 5. Running the Code
On the Raspberry Pi or PC:

    Start the ROS serial node to establish the connection:

rosrun rosserial_python serial_node.py /dev/ttyUSB0

Run the character_publisher node to publish messages that control the LED:

    rosrun ros_light_control character_publisher_node

On the Arduino:

Make sure the Arduino is connected via USB, and it is running the led.ino code uploaded from the Arduino IDE.
### 6. Testing

Once everything is set up, the LED connected to the Arduino will turn on or off based on the messages sent from the character_publisher node. You can change the character sent from the publisher to control the LED as per the defined logic.
Troubleshooting

    Ensure the correct serial port (/dev/ttyUSB0) is used when running the serial node.
    Check that the Arduino is connected properly and the code is uploaded without errors.
