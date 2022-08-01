"""Image Publisher node in Ros"""
#!/usr/bin/python3

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

        # cv2.namedWindow("Stream", cv2.WINDOW_NORMAL)
        # cv2.resizeWindow("Stream", 640, 480)
        # cv2.imshow("Stream", frame)
        if val:
            rospy.loginfo("Video Streaming...")

            pub.publish(bridge.cv2_to_imgmsg(frame))

        rate.sleep()
    #    key = cv2.waitKey(20)

    #    if key == 27 or key == 1048603:
    #        break
    # cv2.destroyWindow("Preveiw")
    # except Exception as e:
    #    pass

if __name__ == "__main__":
    #port_id = "/dev/video0"
    try:
        image_capture(0)
    except rospy.ROSInterruptException:
        pass
