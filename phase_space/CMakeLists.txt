cmake_minimum_required(VERSION 3.5)
project(phase_space)

set(CMAKE_CXX_FLAGS -std=c++14)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

## System dependencies are found with CMake's conventions


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

#######################################
## Declare ROS messages and services ##
#######################################

## Generate messages in the 'msg' folder

## Generate added messages and services with any dependencies listed here

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations

# for the precompiled libraries
link_directories(lib)

add_library(pose_tracking_filter src/PoseTrackingFilter.cpp)

## Declare a cpp executable
add_executable(phase_space_node src/phase_space_node.cpp)

add_executable(phase_space_rviz_publisher src/phase_space_rviz_publisher.cpp)

add_executable(track_body_node src/track_body_node.cpp)
find_package(ament_cmake REQUIRED)
find_package(catkin REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(REQUIRED REQUIRED)
find_package(tf2 REQUIRED)
find_package(cmake_modules REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Eigen REQUIRED)
set(INCLUDE_DIRS ${ament_cmake_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS}
  ${visualization_msgs_INCLUDE_DIRS} ${REQUIRED_INCLUDE_DIRS} ${tf2_INCLUDE_DIRS}
  ${cmake_modules_INCLUDE_DIRS} ${geometry_msgs_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS} ${rosidl_default_generators_INCLUDE_DIRS}
  ${rclcpp_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})
set(LIBRARY_DIRS ${ament_cmake_LIBRARIES} ${catkin_LIBRARIES}
  ${visualization_msgs_LIBRARIES} ${REQUIRED_LIBRARIES} ${tf2_LIBRARIES}
  ${cmake_modules_LIBRARIES} ${geometry_msgs_LIBRARIES} ${std_msgs_LIBRARIES}
  ${rosidl_default_generators_LIBRARIES} ${rclcpp_LIBRARIES} ${Eigen_LIBRARIES})
target_link_libraries(phase_space_node ${LIBRARY_DIRS})
target_link_libraries(phase_space_rviz_publisher ${LIBRARY_DIRS})
target_link_libraries(track_body_node ${LIBRARY_DIRS})
set(LIBS ${ament_cmake_LIBRARIES} ${catkin_LIBRARIES}
  ${visualization_msgs_LIBRARIES} ${REQUIRED_LIBRARIES} ${tf2_LIBRARIES}
  ${cmake_modules_LIBRARIES} ${geometry_msgs_LIBRARIES} ${std_msgs_LIBRARIES}
  ${rosidl_default_generators_LIBRARIES} ${rclcpp_LIBRARIES} ${Eigen_LIBRARIES})
rosidl_generate_interfaces(${PROJECT_NAME} "msg/PhaseSpaceMarker.msg"
  "msg/PhaseSpaceMarkerArray.msg"
  DEPENDENCIES builtin_interfaces visualization_msgs geometry_msgs std_msgs)


## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(phase_space_node phase_space_generate_messages_cpp)
add_dependencies(phase_space_rviz_publisher phase_space_generate_messages_cpp)
add_dependencies(track_body_node phase_space_generate_messages_cpp
  pose_tracking_filter)

## Specify libraries to link a library or executable target against

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION bin
# )

## Mark executables and/or libraries for installation
# install(TARGETS phase_space phase_space_node
#   ARCHIVE DESTINATION lib
#   LIBRARY DESTINATION lib
#   RUNTIME DESTINATION bin
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION include/${PROJECT_NAME}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION share/${PROJECT_NAME}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_phase_space.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
ament_export_include_directories(${INCLUDE_DIRS})
ament_export_libraries(pose_tracking_filter ${LIBS})

ament_export_dependencies(ament_cmake)
ament_export_dependencies(catkin)
ament_export_dependencies(visualization_msgs)
ament_export_dependencies(REQUIRED)
ament_export_dependencies(tf2)
ament_export_dependencies(cmake_modules)
ament_export_dependencies(geometry_msgs)
ament_export_dependencies(std_msgs)
ament_export_dependencies(rosidl_default_generators)
ament_export_dependencies(rclcpp)
ament_export_dependencies(Eigen)

ament_package()
