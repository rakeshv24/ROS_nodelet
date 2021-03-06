#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <stdio.h>
#include <std_msgs/String.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

image_transport::Publisher pub;
image_transport::Subscriber sub;

namespace nodelet_sample_ns
{
	class webcam_nodelet_1 : public nodelet::Nodelet
	{
		virtual void onInit()
		{
			ros::NodeHandle& _nh = getPrivateNodeHandle();
			NODELET_DEBUG("Initialized the Nodelet");
			image_transport::ImageTransport it(_nh);
			pub = it.advertise("camera1/image", 1);
			sub = it.subscribe("cv_camera_node/image_raw", 1, &webcam_nodelet_1::callback, this);
		}
		
		void callback(const sensor_msgs::ImageConstPtr& msg)
		{
			try
			{
				cv::Mat image = cv_bridge::toCvShare(msg, "bgr8")->image;
				cv::imshow("output window 1",image);
				cv::waitKey(1);
				sensor_msgs::ImagePtr output = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
				pub.publish(output);				
			}
			catch(cv_bridge::Exception& e)
			{
				ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
			}
		}
		
  };
}

PLUGINLIB_EXPORT_CLASS(nodelet_sample_ns::webcam_nodelet_1, nodelet::Nodelet)