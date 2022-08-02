// Copyright @2022 The Dinesh Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ros/ros.hpp>
#include <image_transport/image_transport.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
  ros::init(argc, argv, "streamer");

  ros::NodeHandle n;

  image_transport::ImageTransport t(n);

  image_transport::Publisher pub = t.advertise("image", 1);

  ros::Rate loop_rate(10);

  Mat Image;
  VideoCapture cap(0);

  while (ros::ok()) {
    cap >> Image;

    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(),
                                                   "bgr8",
                                                   Image).toImageMsg();

    ROS_INFO("Video Streaming...");

    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }
  cap.release();
  return 0;
}
