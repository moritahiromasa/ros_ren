# 2023/03/28
# 髪の毛を検出したい

#!/usr/bin/env python3

import cv2 as cv
import numpy as np

img = cv.imread("/home/ubuntu/ros_ren/images/idphoto.jpg")

hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)


# 赤は２つ必要
frame_mask1 = cv.inRange(hsv, np.array([0, 64, 0]), np.array([30, 255, 255]))
frame_mask2 = cv.inRange(hsv, np.array([150, 64, 0]), np.array([180, 255, 255]))

# 緑
frame_mask3 = cv.inRange(hsv, np.array([30, 64, 0]), np.array([90, 255, 255]))

# 青
frame_mask4 = cv.inRange(hsv, np.array([90, 64, 0]), np.array([150, 255, 255]))

# 髪の毛の黒い部分を検出したい
frame_mask = frame_mask1 + frame_mask2 + frame_mask3 + frame_mask4

# 論理演算で色検出
dst = cv.bitwise_and(img, img, mask = frame_mask)

cv.imshow("img", dst)

if cv.waitKey(0) & 0xFF == ord('q') :
	cv.destroyAllWindows()

