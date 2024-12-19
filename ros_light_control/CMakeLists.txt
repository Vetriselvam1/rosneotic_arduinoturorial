cmake_minimum_required(VERSION 3.0.2)
project(ros_light_control)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## Declare a catkin package
catkin_package()

## Include directories
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# Add the executable
add_executable(singlecmdtoledonn_node src/singlecmdtoledonn.cpp)

# Link against necessary libraries
target_link_libraries(singlecmdtoledonn_node ${catkin_LIBRARIES})

# Add dependencies (if needed)
add_dependencies(singlecmdtoledonn_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ros_ledcontrol_node src/led_control.cpp)

# Link against necessary libraries
target_link_libraries(ros_ledcontrol_node ${catkin_LIBRARIES})

# Add dependencies (if needed)
add_dependencies(ros_ledcontrol_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(rviz_ledcontrol_node src/rviz_led_control.cpp)

# Link against necessary libraries
target_link_libraries(rviz_ledcontrol_node ${catkin_LIBRARIES})

# Add dependencies (if needed)
add_dependencies(rviz_ledcontrol_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(test_marker_node src/test_marker.cpp)

# Link against necessary libraries
target_link_libraries(test_marker_node ${catkin_LIBRARIES})

# Add dependencies (if needed)
add_dependencies(test_marker_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

