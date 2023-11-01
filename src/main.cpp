#include <QApplication>
#include<QPixmap>
#include"client_ui.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ClientUi clientUi;
    clientUi.setFixedSize(1000,750);
    clientUi.setWindowTitle("VFtp");
    QPixmap image;
    image.load(":/res/V.png");
    QIcon windowIcon(image);
    clientUi.setWindowIcon(windowIcon);
    clientUi.show();
    return QApplication::exec();
}
