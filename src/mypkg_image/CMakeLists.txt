cmake_minimum_required(VERSION 3.0.2)
project(mypkg_image)

find_package(OpenCV REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(mypkg_image src/detectFace.cpp)
add_executable(detectFace src/detectFace.cpp)

#target_link_libraries(detectFace ${catkin_LIBRALIES})
#target_link_libraries(detectFace ${OpenCV_LIBRALIES})

target_link_libraries(mypkg_image ${catkin_LIBRALIES})
target_link_libraries(mypkg_image ${OpenCV_LIBRALIES})
