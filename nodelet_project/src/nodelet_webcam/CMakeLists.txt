cmake_minimum_required(VERSION 2.8.3)
project(nodelet_webcam)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  nodelet
  roscpp
  std_msgs
)

find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS nodelet roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_library(nodelet_webcam src/nodelet_webcam/nodelet_cam.cpp src/nodelet_webcam/nodelet_cam1.cpp)

target_link_libraries(nodelet_webcam
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

install(FILES
   launch/nodelet_samp.launch
   nodelet_samp.xml
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )

#if(catkin_EXPORTED_LIBRARIES)
#  add_dependencies(nodelet_webcam ${catkin_EXPORTED_LIBRARIES})
#endif()