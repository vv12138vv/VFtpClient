#include <QApplication>
#include <QPushButton>
#include"client_ui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ClientUi clientUi;
    clientUi.show();
    return QApplication::exec();
}
