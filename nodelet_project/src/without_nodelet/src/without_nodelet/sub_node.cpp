#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/String.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//image_transport::Publisher pub1;
image_transport::Subscriber sub1;

class sub_webcam
{
	public:
		sub_webcam()
		{
			ros::NodeHandle n;
			image_transport::ImageTransport it(n);
			//pub1 = it.advertise("camera/image", 1);
			sub1 = it.subscribe("/camera/image", 1, &sub_webcam::callback, this);
			
		}
	private:

		void callback(const sensor_msgs::ImageConstPtr& msg)
		{
			try
			{
				cv::Mat image = cv_bridge::toCvShare(msg, "bgr8")->image;
				cv::imshow("output",image);
				cv::waitKey(1);
				//sensor_msgs::ImagePtr output = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
				//pub1.publish(output);				
			}
			catch(cv_bridge::Exception& e)
			{
				ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
			}
		}
};
int main(int argc, char** argv) 
{
  ros::init(argc, argv, "subscriber_node");
  sub_webcam obj;
  ros::spin();
  ros::waitForShutdown();
  return 0;
}

