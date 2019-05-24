import glob
import shutil

directry =  glob.glob("./*")
directry.remove(input("enter except directry"))
save_dir = input("enter save directry")
num = int(input("serial num"))
save_name = input("enter save name")
for i in directry:
    files = glob.glob(directry + "/*.jpg")
    for j in files:
        shutil.copy(i+j,save_dir+"/"+save_name+num+".jpg")
