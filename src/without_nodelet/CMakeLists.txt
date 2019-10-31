cmake_minimum_required(VERSION 2.8.3)
project(without_nodelet)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  std_msgs
)

find_package(OpenCV REQUIRED)

catkin_package(
  #INCLUDE_DIRS include
  #LIBRARIES 
  CATKIN_DEPENDS roscpp std_msgs
  #DEPENDS system_lib
)

include_directories(
 #include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(webcam_node1 src/without_nodelet/webcam_node1.cpp)
add_dependencies(webcam_node1 ${catkin_EXPORTED_TARGETS})
target_link_libraries(webcam_node1
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

add_executable(webcam_node2 src/without_nodelet/webcam_node2.cpp)
add_dependencies(webcam_node2 ${catkin_EXPORTED_TARGETS})
target_link_libraries(webcam_node2
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

install(TARGETS webcam_node1 webcam_node2
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES
   launch/just_nodes.launch
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )
