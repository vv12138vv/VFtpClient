#include <QApplication>
#include<QPixmap>
#include"client_ui.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ClientUi clientUi;
    clientUi.setFixedSize(1000,750);
    clientUi.setWindowTitle("VFtp");
    QPixmap image;
    bool success=image.load("C:/Users/jgss9/Desktop/favicon.ico");
    qDebug()<<"success:"<<success<<'\n';
    QIcon icon(image);
    clientUi.setWindowIcon(icon);
    clientUi.show();
    return QApplication::exec();
}
