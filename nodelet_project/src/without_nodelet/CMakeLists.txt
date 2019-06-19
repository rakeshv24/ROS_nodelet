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

add_executable(sub src/without_nodelet/sub_node.cpp)
add_dependencies(sub ${catkin_EXPORTED_TARGETS})
target_link_libraries(sub
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

add_executable(pub src/without_nodelet/pub_node.cpp)
add_dependencies(pub ${catkin_EXPORTED_TARGETS})
target_link_libraries(pub
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

install(TARGETS sub pub
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES
   launch/just_nodes.launch
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )
