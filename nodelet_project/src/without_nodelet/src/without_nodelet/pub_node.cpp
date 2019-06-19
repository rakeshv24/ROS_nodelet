#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/String.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

image_transport::Publisher pub;
image_transport::Subscriber sub;

class pub_webcam
{
	public:
		pub_webcam()
		{
			ros::NodeHandle n;
			image_transport::ImageTransport it(n);
			pub = it.advertise("camera/image", 1);
			sub = it.subscribe("/cv_camera_node/image_raw", 1, &pub_webcam::callback, this);
			//ros::spin();
		}

	private:
		void callback(const sensor_msgs::ImageConstPtr& msg)
		{
			try
			{
				cv::Mat image = cv_bridge::toCvShare(msg, "bgr8")->image;
				//cv::imshow("output",image);
				//cv::waitKey(50);
				sensor_msgs::ImagePtr output = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
				pub.publish(output);				
			}
			catch(cv_bridge::Exception& e)
			{
				ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
			}
		}
};
int main(int argc, char** argv) 
{
  ros::init(argc, argv, "publisher_node");
  pub_webcam obj;
  ros::spin();
  ros::waitForShutdown();
  return 0;
}

