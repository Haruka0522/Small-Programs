import os
import cv2

path = "/home/haruka/RMRC/negative"
save_path = "/home/haruka/RMRC/neg"

file_list = os.listdir(path)

if not os.path.exists(save_path):
    os.mkdir(save_path)

for index,file_name in enumerate(file_list):
    img = cv2.imread(path+"/"+str(file_name))
    cv2.imwrite(save_path+"/"+str(index)+".jpg",img)
