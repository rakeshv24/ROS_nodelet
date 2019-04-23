# ROS_nodelet

Nodelets are ROS nodes designed to run multiple algorithms within the same process in an efficient manner. Each process is executed as threads. Threaded nodes communicate efficiently without overloading the network by using zero copy transport between two nodes. Nodelets are used when the volume of data to be transferred between nodes are very high. 

## 1. Installation of cv_camera package

`sudo apt-get install ros-kinetic-cv-camera`

## 2. Clone this repository

## 3. Run the program

`cd ~/{PATH_to_repo}`

`source install/setup.bash`

`roslaunch nodelet_webcam nodelet_samp.launch`
