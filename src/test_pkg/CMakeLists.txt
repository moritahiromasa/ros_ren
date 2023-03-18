project(test_pkg)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

include_directories(
	${catkin_INCLUDE_DIRS}	
)

add_executable(test_pkg src/publisher.cpp)
#add_executable(test_pkg src/subscriber.cpp)


target_link_libraries(test_pkg ${catkin_LIBRARIES})

