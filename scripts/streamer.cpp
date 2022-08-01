#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "streamer");

  ros::NodeHandle n;

  image_transport::ImageTransport t(n);

  image_transport::Publisher pub = t.advertise("image", 1); // <std_msgs::String>("live", 1000);

  ros::Rate loop_rate(10);

  Mat Image;
  VideoCapture cap(0);
  // int count = 0;
  while (ros::ok())
  {
    cap >> Image;
    
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", Image).toImageMsg();
    // std_msgs::String msg;

    // std::stringstream ss;
    // ss << "hello world " << count;
    // msg.data = ss.str();

    ROS_INFO("Video Streaming...");

    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    // ++count;
  }
  cap.release();
  return 0;
}
