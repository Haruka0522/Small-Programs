import sys

from PyQt5.QtWidgets import QWidget,QApplication

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.title = "なにも表示されないただのWindow"
        self.width = 640
        self.height = 480
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(0,0,self.width,self.height)
        self.show()

def main():
    app = QApplication(sys.argv)
    gui = MyWindow()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
