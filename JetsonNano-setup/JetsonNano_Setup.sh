sudo apt update -y
sudo apt upgrade -y
cd ~

#swap領域の作成
git clone https://github.com/JetsonHacksNano/installSwapfile
cd installSwapfile
./installSwapfile.sh

#OverClock
sudo nvpmodel -m 0
sudo jetson_clocks

#Install Opencv-python 3.4.6
git clone https://github.com/jkjung-avt/jetson_nano.git
cd jetson_nano/
./install_opencv-3.4.6.sh

#Install(Adding) Opencv-conrib 3.4.6
cd ~/src/
wget https://github.com/opencv/opencv_contrib/archive/3.4.6.zip
unzip 3.4.6.zip
cd opencv_contrib-3.4.6/
mkdir build
cd build
cmake -DOPENCV_ENABLE_NONFREE:BOOL=ON -DOPENCV_EXTRA_MODULES_PATH=../modules ../../opencv-3.4.6/
make -j3
sudo make install

#set up git
cd ~
git config --global user.email harukapc1@gmail.com
git config --global user.name Haruka0522
