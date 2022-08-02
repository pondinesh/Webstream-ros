#!/usr/bin/python3
"""Image Subscriber node in Ros"""

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import rospkg

#pylint: disable=no-member, broad-except
def callback(video):
    """Image Stream"""
    bridge = CvBridge()
    rospack = rospkg.RosPack()
    facecascade = cv2.CascadeClassifier(rospack.get_path('webstream_ros') +
                                        '/scripts/haarcascade_frontalface_default.xml')
    rospy.loginfo("Playing Live...")
    frame = bridge.imgmsg_to_cv2(video)
    try:
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = facecascade.detectMultiScale(gray,
                                             scaleFactor=1.1,
                                             minNeighbors=5,
                                             minSize=(30, 30),
                                             flags=cv2.CASCADE_SCALE_IMAGE
                                            )
        for (xframe, yframe, wframe, hframe) in faces:
            cv2.rectangle(frame,
                          (xframe, yframe),
                          (xframe+wframe, yframe+hframe),
                          (0, 255, 0),
                          2)
    except Exception as error:
        print(error)

    cv2.imshow("Live", frame)
    cv2.waitKey(1)

def live():
    """Image Subcriber"""
    rospy.init_node("Live_WebCam", anonymous=True)
    rospy.Subscriber("Streamer", Image, callback)
    rospy.spin()

if __name__ == "__main__":
    try:
        live()
    except Exception as e:
        print(e)
