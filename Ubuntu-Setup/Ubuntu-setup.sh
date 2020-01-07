#!/bin/sh
sudo apt update

#Gitの設定
sudo apt install git
git config --global user.name Haruka0522
git config --global user.email harukapc1@gmail.com
git config --global color.ui "auto"

#Vim
sudo apt update
sudo apt install vim
wget https://raw.githubusercontent.com/Shougo/dein.vim/master/bin/installer.sh
mkdir ./.vim/
chmod +x ./installer.sh
./installer.sh ~/.vim/

#dotfileの設定
cd ~
git clone https://github.com/Haruka0522/dotfiles/
cd dotfile
chmod +x ./setup.sh
./setup.sh
cd ~

#ターミナルにSLを走らせたい
sudo apt install sl

#pipのインストール
sudo apt install python3-pip

#OpenCV3.2.4.16+contribのインストール
pip3 install opencv-python==3.4.2.16
pip3 install opencv-contrib-python==3.4.2.16

#PythonのライブラリRequestsのインストール
pip3 install requests

#Pythonのライブラリbeautifulsoup4のインストール
pip3 install beautifulsoup4

#Pythonのライブラリgmpyのインストール
sudo apt install python-dev libgmp3-dev
pip3 install gmpy

#Pythonのライブラリsympyのインストール
pip3 install sympy

#Pythonのライブラリmatplotlibのインストール
pip3 install matplotlib

#Pythonのライブラリseleniumのインストール
pip3 install selenium

#Jupyter Notebook系のインストール(python3のみ)
pip3 install pandas
pip3 install sklearn
sudo apt install jupyter-notebook -y
pip3 install chainer
pip3 install tensorflow
pip3 install pandas-ml

#neofetchのインストール
sudo apt install neofetch

#テーマ、アイコンを変更
sudo add-apt-repository ppa:dyatlov-igor/materia-theme
sudo apt update
sudo apt install materia-gtk-theme
sudo add-apt-repository ppa:papirus/papirus
sudo apt update
sudo apt install papirus-icon-theme
sudo add-apt-repository ppa:snwh/pulp
sudo apt update
sudo apt install paper-cursor-theme
sudo apt install gnome-tweaks

#Google Chrome
sudo sh -c 'echo "deb http://dl.google.com/linux/chrome/deb/ stable main" >> /etc/apt/sources.list.d/google.list'
sudo wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add -
sudo apt update
sudo apt install google-chrome-stable

#ChromeDriverのインストール
cd /tmp/
curl -O https://chromedriver.storage.googleapis.com/80.0.3987.16/chromedriver_linux64.zip
unzip chromedriver_linux64.zip
sudo mv chromedriver /usr/local/bin/
rm chromedriver

#Arduino IDE 1.8.9
cd ~/ダウンロード
wget https://www.arduino.cc/download_handler.php?f=/arduino-1.8.9-linux64.tar.xz
tar Jxvf arduino-1.8.9-linux64.tar.xz
sudo mv arduino-1.8.9 /opt/
cd /opt/arduino-1.8.9/
sudo ./install.sh

#Teensyduino
cd ~/ダウンロード
wget http://www.pjrc.com/teensy/49-teensy.rules
sudo mv 49-teensy.rules /etc/udev/rules.d
wget https://www.pjrc.com/teensy/td_147/TeensyduinoInstall.linux64
chmod +x TeensyduinoInstall.linux64
./TeensyduinoInstall.linux64

#VSCode
sudo apt install curl
curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" > /etc/apt/sources.list.d/vscode.list'
sudo apt install apt-transport-https
sudo apt update
sudo apt install code

#bashからzshに変更
sudo apt install zsh
chsh

#自分でやることを表示
echo "Tweaksからテーマのアプリケーション、カーソル、アイコンを選択してね"
echo "ターミナルにの色や透過度を設定してね"

