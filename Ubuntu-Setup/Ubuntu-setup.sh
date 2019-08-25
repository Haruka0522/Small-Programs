#!/bin/sh
sudo apt update

#Gitの設定
sudo apt install git
git config --global user.name Haruka0522
git config --global user.email harukapc1@gmail.com
git config --global color.ui "auto"

#dotfileの設定
git clone https://github.com/Haruka0522/dotfiles/
cd dotfile
./setup.sh
cd ~

#ターミナルにSLを走らせたい
sudo apt install sl

#pipのインストール
sudo apt install pip
sudo apt install pip3

#OpenCV3.2.4.16+contribのインストール
pip3 install opencv-python==3.4.2.16
pip3 install opencv-contrib-python==3.4.2.16

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

#bashからzshに変更
sudo apt install zsh
chsh

#自分でやることを表示
echo "Tweaksからテーマのアプリケーション、カーソル、アイコンを選択してね"
echo "ターミナルにの色や透過度を設定してね"

