import serial
import cv2 as cv
import numpy as np

ser = serial.Serial('/dev/tty.usbmodem?',9600')

# table calibration: 3.0875 pixel/cm
table = cv.imread("/Users/karenpoon/Pictures/idptable_non_distort2.jpg")
table = table[:, 35:773]
table_grey = cv.cvtColor(table, cv.COLOR_BGR2GRAY)
table_enhanced = cv.equalizeHist(table_grey)
# [y direction, x direction]
mine_area_enhanced = table_enhanced[:, 70:510]
mine_area_blurred = cv.medianBlur(mine_area_enhanced, 5)

thresVal, thresh_mine_area = cv.threshold(mine_area_blurred, 20, 250, cv.THRESH_BINARY)
cnts, hie = cv.findContours(thresh_mine_area, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
blank_image = np.zeros(table.shape[:2], dtype="uint8") * 255
cnts = cnts[1:]
# mine_as_contours = cv.drawContours(table, cnts, -1, (30,30,30), 6)
areas = [cv.contourArea(c) for c in cnts]
robot_position =
for c in cnts:
    M = cv.moments(c)
    cx = int(M['m10']/M['m00']) + 70
    cy = int(M['m01']/M['m00'])
    print(cx, cy)
    cv.circle(table, (cx, cy), 7, (0, 0, 255), -1)

home_x = 584
home_y = 515


# c = cv.rotate(mine_as_contours, cv.ROTATE_90_CLOCKWISE)

# cv.imshow("mine area", mine_as_contours)
cv.imshow("contours on table", table)

cv.waitKey(0)