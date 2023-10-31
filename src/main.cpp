#include <QApplication>
#include"client_ui.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ClientUi clientUi;
    clientUi.setFixedSize(1000,750);
    clientUi.setWindowTitle("VFtp");
    clientUi.show();
    return QApplication::exec();
}
