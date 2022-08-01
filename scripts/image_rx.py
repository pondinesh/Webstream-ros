#!/usr/bin/python3

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

def callback(video):
    br = CvBridge()
    
    faceCascade = cv2.CascadeClassifier('/home/pon-dinesh/dinesh_ws/src/image_view/scripts/haarcascade_frontalface_default.xml')
    
    rospy.loginfo("Playing Live...")

    frame = br.imgmsg_to_cv2(video)

    try:
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) 
        
        faces = faceCascade.detectMultiScale(
            gray,
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(30, 30),
            flags=cv2.CASCADE_SCALE_IMAGE
        )

        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
    
    except Exception as e:
        pass

    cv2.imshow("Live", frame)

    cv2.waitKey(1)

def live():
    rospy.init_node("Live_WebCam", anonymous=True)

    rospy.Subscriber("Streamer", Image, callback)

    rospy.spin()

    # cv2.destroyAllWindows()

if __name__ == "__main__":
    try:
        live()
    except Exception as e:
        print(e)
