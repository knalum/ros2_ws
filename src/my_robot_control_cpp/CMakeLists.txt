cmake_minimum_required(VERSION 3.8)
project(my_robot_control_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(publisher src/mypublisher.cpp)
ament_target_dependencies(publisher rclcpp std_msgs)

add_executable(subscriber src/mysubscriber.cpp)
ament_target_dependencies(subscriber rclcpp std_msgs)

add_executable(pose_subscriber src/pose_subscriber.cpp)
ament_target_dependencies(pose_subscriber rclcpp std_msgs turtlesim )

add_executable(draw_circle src/draw_circle.cpp)
ament_target_dependencies(draw_circle rclcpp std_msgs turtlesim geometry_msgs)


install(TARGETS publisher subscriber pose_subscriber  draw_circle DESTINATION lib/${PROJECT_NAME})


ament_package()
