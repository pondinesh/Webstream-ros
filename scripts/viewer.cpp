// Copyright @2022 The Dinesh Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <string>
#include <iostream>
#include <ros/package.h>

using namespace std;
using namespace cv;

void Callback(const sensor_msgs::ImageConstPtr& msg) {
  try {
    string trained_classifier = ros::package::getPath("webstream_ros") +
                                "/scripts/haarcascade_frontalface_default.xml";

    CascadeClassifier faceDetector;

    faceDetector.load(trained_classifier);

    vector<Rect>faces;

    faceDetector.detectMultiScale((cv_bridge::toCvShare(msg, "bgr8")->image),
                                  faces,
                                  1.1,
                                  4,
                                  CASCADE_SCALE_IMAGE,
                                  Size(30, 30));

    for (int i = 0; i < faces.size(); i++) {
         // for locating the face
         Mat faceROI = cv_bridge::toCvShare(msg, "bgr8")->image(faces[i]);
         // Storing face in the matrix//
         int x = faces[i].x;
         // Getting the initial row value of face rectangle's starting point
         int y = faces[i].y;
         // Getting the initial col value of face rectangle's starting point
         int h = y + faces[i].height;
         // Calculating the height of the rectangle//
         int w = x + faces[i].width;
         // Calculating the width of the rectangle//
         rectangle(cv_bridge::toCvShare(msg, "bgr8")->image,
                   Point(x, y),
                   Point(w, h),
                   Scalar(255, 0, 255),
                   2,
                   8,
                   0);
         // Drawing a rectangle using around the faces//
      }
    imshow("stream", cv_bridge::toCvShare(msg, "bgr8")->image);
    // cv_bridge::toCvShare(msg, "bgr8")->image);
    ROS_INFO("Live Playing...");
    waitKey(30);
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "viewer");

  ros::NodeHandle n;

  namedWindow("stream", WINDOW_NORMAL);

  resizeWindow("stream", 640, 480);

  image_transport::ImageTransport t(n);

  image_transport::Subscriber sub = t.subscribe("image", 1, Callback);

  ros::spin();

  destroyWindow("stream");

  return 0;
}
