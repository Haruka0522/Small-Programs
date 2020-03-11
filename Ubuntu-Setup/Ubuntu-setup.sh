#!/bin/sh
sudo apt update

#curlのインストール
sudo apt install curl

#unzipのインストール
sudo apt install unzip

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

#pythonのコードチェックツール
pip3 install flake8

#pythonの自動修正ツール
pip3 install autopep8

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

#colordiffのインストール
sudo apt install colordiff

#tesseractのインストール
sudo add-apt-repository ppa:alex-p/tesseract-ocr
sudo apt update
sudo apt install -y tesseract-ocr
sudo apt install -y libtesseract-dev
sudo apt install -y tesseract-ocr-jpn  tesseract-ocr-jpn-vert
sudo apt install -y tesseract-ocr-script-jpan tesseract-ocr-script-jpan-vert

#pytesseractのインストール
pip3 install pytesseract

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
curl -O https://chromedriver.storage.googleapis.com/80.0.3987.106/chromedriver_linux64.zip
unzip chromedriver_linux64.zip
sudo mv chromedriver /usr/local/bin/
rm chromedriver_linux64.zip

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

#pyenvのインストール
git clone https://github.com/pyenv/pyenv.git ~/.pyenv
echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.zshrc
echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.zshrc
echo 'eval "$(pyenv init -)"' >> ~/.zshrc
source ~/.bashrc

#pyenv-virtualenvのインストール
git clone https://github.com/pyenv/pyenv-virtualenv.git $(pyenv root)/plugins/pyenv-virtualenv
echo 'eval "$(pyenv virtualenv-init -)"' >> ~/.zshrc
echo export PYENV_VIRTUALENV_DISABLE_PROMPT=1 >> ~/.zshrc
source ~/.zshrc

#protobufのインストール
curl -OL https://github.com/protocolbuffers/protobuf/releases/download/v3.11.3/protoc-3.11.3-linux-x86_64.zip
unzip protoc-3.11.3-linux-x86_64.zip
sudo mv bin/* /usr/local/bin/
sudo mv include/* /usr/local/include/
rm -rf protoc-3.11.3-linux-x86_64.zip bin include

#bashからzshに変更
sudo apt install zsh
chsh

#GNOME Shellの時刻表示の設定
gsettings set org.gnome.desktop.interface clock-show-date true
gsettings set org.gnome.desktop.interface clock-show-seconds true

#Wiresharkのインストール
sudo apt install wireshark

#GTOPのインストール
curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
curl -sL https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
sudo apt update
sudo apt install nodejs yarn build-essential
sudo apt install npm
sudo npm install gtop -g

#IPAフォントのインストール
sudo apt install fonts-ipafont fonts-ipaexfont
sudo fc-cache -fv

#pureプロンプトのインストール
sudo npm install --global pure-prompt --allow-root --unsafe-perm=true

#自分でやることを表示
echo "Tweaksからテーマのアプリケーション、カーソル、アイコンを選択してね"
echo "ターミナルにの色や透過度を設定してね"
echo "設定>オンラインアカウント>Googleを接続してGoogleDriveを同期させてね"
echo "https://karaas.hatenablog.jp/entry/2018/11/29/141733を参考にOnedriveも同期させてね"
echo "sudo visudoを実行して Defaults        badpass_message="あんたに権限をあげるわけないでしょ！このバカっ"を追記してね"
echo "Slack,Skypeのdebファイルをダウンロードしてきてインストールしてね"
echo "ロック画面の背景画像を変更してね"
