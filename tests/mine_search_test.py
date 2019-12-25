import serial
import cv2 as cv
import numpy as np
import math

ser = serial.Serial("/dev/cu.usbmodem14102", 9600)

# 3.0875 pixel/cm
calibration = 3.0875
# table = cv.imread("/Users/karenpoon/Pictures/idptable_non_distort2.jpg")
table = cv.imread("/Users/karenpoon/Pictures/idp_table4.jpg")

table = table[:, 35:773]
table_grey = cv.cvtColor(table, cv.COLOR_BGR2GRAY)
table_enhanced = cv.equalizeHist(table_grey)
# [y direction, x direction]
mine_area_enhanced = table_enhanced[:, 70:510]
mine_area_blurred = cv.medianBlur(mine_area_enhanced, 3)

thresVal, thresh_mine_area = cv.threshold(mine_area_blurred, 10, 250, cv.THRESH_BINARY_INV)
# thresh_mine_area = cv.medianBlur(thresh_mine_area, 3)
kernel = np.ones((5,5),np.uint8)
dilation = cv.dilate(thresh_mine_area,kernel,iterations = 1)
# cv.imshow("thresh", dilation)
# cv.waitKey(0)
contours, hie = cv.findContours(dilation, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
blank_image = np.zeros(table.shape[:2], dtype="uint8") * 255
contours = contours[:]
# mine_as_contours = cv.drawContours(table, cnts, -1, (30,30,30), 6)
# areas = [cv.contourArea(c) for c in cnts]
cnts = []
for cnt in contours:
    area = cv.contourArea(cnt)
    print(area)
    if area > 2 and area < 500:
        cnts.append(cnt)

areas = [cv.contourArea(c) for c in cnts]
# print("contour areas: " + areas)

dist_list = []
home_x = 584
home_y = 515

for c in cnts:
    M = cv.moments(c)
    cx = int(M['m10']/M['m00']) + 70
    cy = int(M['m01']/M['m00'])
    print(cx, cy)
    cv.circle(table, (cx, cy), 7, (0, 0, 255), -1)
    dist = math.sqrt((abs(cx - home_x))**2 + abs((cy - home_y))**2)
    x_diff = home_x - cx
    calibrated_x = x_diff/calibration
    tup = (calibrated_x, dist)
    dist_list.append(tup)

sorted_dist_list = sorted(dist_list, key=lambda x: x[1])
mine_dist = []

# for i in range(sorted_dist_list):
#     for j in range(sorted_dist_list)-1:
#         x_diff = abs(sorted_dist_list[i][0]-sorted_dist_list[j+1][0])
#         y_diff = abs(sorted_dist_list[i][1]-sorted_dist_list[j+1][1])
#         dist_between = math.sqrt((x_diff)**2 + (y_diff)**2)
#         if dist_between

for tup in sorted_dist_list:
    mine_dist.append(tup[0])


print(mine_dist)

# a = str(mine_dist[0])+'\n'
# b = str(mine_dist[1])

# ser.write(a.encode())
# ser.write(b.encode())

cv.imshow("contours on table", table)
cv.waitKey(0)

for mine_distance in mine_dist:
    mine_dist_serial = str(int(mine_distance)) + 'n'
    ser.write(mine_dist_serial.encode())

end = 'o'
ser.write(end.encode())

while True:
    if (ser.inWaiting()>0):
        data1= ser.readline().decode()
        print(data1)

# print(ser.readline().decode())

ser.close()
