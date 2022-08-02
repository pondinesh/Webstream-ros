#!/usr/bin/python3
"""Image Publisher node in Ros"""

import cv2
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

def image_capture(port):
    """Image Publisher"""
    rospy.init_node("Webcam_Pub", anonymous=True)
    pub = rospy.Publisher("/Streamer", Image, queue_size=10)
    rate = rospy.Rate(10)
    cap = cv2.VideoCapture(port) #pylint: disable=no-member
    bridge = CvBridge()

    while not rospy.is_shutdown():
        val, frame = cap.read()

        if val:
            rospy.loginfo("Video Streaming...")

            pub.publish(bridge.cv2_to_imgmsg(frame))

        rate.sleep()

if __name__ == "__main__":
    try:
        image_capture(0)
    except rospy.ROSInterruptException:
        pass
