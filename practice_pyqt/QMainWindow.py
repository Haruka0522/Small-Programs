import sys

from PyQt5.QtWidgets import QMainWindow, QApplication,QAction,qApp
from PyQt5.QtCore import QTimer

import datetime


class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.title = "This is a QMainWindow"
        self.width = 640
        self.height = 480
        self.initUI()

    def initUI(self):
        # メニューバー
        exitAction = QAction("&終了",self)
        exitAction.setShortcut("Ctrl+Q")
        exitAction.setStatusTip("close the GUI window")
        exitAction.triggered.connect(qApp.quit)
        
        menubar = self.menuBar()
        fileMenu = menubar.addMenu("&ファイル")
        fileMenu.addAction(exitAction)


        # windowの作成
        self.setWindowTitle(self.title)
        self.setGeometry(0, 0, self.width, self.height)
        self.statusBar().showMessage("here is a status bar")
        self.show()

        # ステータスバー用のタイマー
        timer = QTimer(self)
        timer.timeout.connect(self.getDateTime)
        timer.start(1000)



    def getDateTime(self):
        dt = datetime.datetime.today()
        dt_str = dt.strftime("%Yねん%mがつ%dにち、%Hじ%Mふん%Sびょう")
        self.statusBar().showMessage(
            "ステータスバーに野生の時計が現れた " + dt_str)


def main():
    app = QApplication(sys.argv)
    gui = MyWindow()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
