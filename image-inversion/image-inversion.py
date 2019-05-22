import cv2
import os

path = "/home/haruka/RMRC/neg"
save_path = "/home/haruka/RMRC/neg"
serial_number = 500

file_list = os.listdir(path)

if not os.path.exists(save_path):
    os.mkdir(save_path)

for file_name in file_list:
    img = cv2.imread(path+"/"+str(file_name))
    flip_img = cv2.flip(img,1)
    cv2.imwrite(save_path+"/"+str(serial_number)+".jpg",flip_img)
    serial_number += 1

