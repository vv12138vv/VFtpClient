/********************************************************************************
** Form generated from reading UI file 'client_ui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_UI_H
#define UI_CLIENT_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientUi
{
public:
    QPushButton *connectBtn;
    QLabel *hostLabel;
    QLineEdit *hostInputBar;
    QLabel *portLabel;
    QLineEdit *portInputBar;
    QLabel *usernameLabel;
    QLineEdit *usernameInputBar;
    QLabel *passwordLabe;
    QLineEdit *passwordInputBar;
    QTextBrowser *systemMsgBrowser;
    QPushButton *loginBtn;
    QPushButton *PWDtestBtn;
    QPushButton *LISTtestBtn;
    QPushButton *PASVtestBtn;
    QTableWidget *serverFileTable;
    QLabel *serverPathLabel;
    QPushButton *MKDtestBtn;
    QPushButton *RMDtestBtn;

    void setupUi(QWidget *ClientUi)
    {
        if (ClientUi->objectName().isEmpty())
            ClientUi->setObjectName("ClientUi");
        ClientUi->resize(900, 750);
        connectBtn = new QPushButton(ClientUi);
        connectBtn->setObjectName("connectBtn");
        connectBtn->setGeometry(QRect(590, 20, 91, 31));
        hostLabel = new QLabel(ClientUi);
        hostLabel->setObjectName("hostLabel");
        hostLabel->setGeometry(QRect(100, 30, 51, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setPointSize(12);
        hostLabel->setFont(font);
        hostInputBar = new QLineEdit(ClientUi);
        hostInputBar->setObjectName("hostInputBar");
        hostInputBar->setGeometry(QRect(150, 30, 121, 21));
        portLabel = new QLabel(ClientUi);
        portLabel->setObjectName("portLabel");
        portLabel->setGeometry(QRect(360, 30, 51, 31));
        portLabel->setFont(font);
        portInputBar = new QLineEdit(ClientUi);
        portInputBar->setObjectName("portInputBar");
        portInputBar->setGeometry(QRect(420, 30, 121, 21));
        usernameLabel = new QLabel(ClientUi);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(60, 60, 81, 31));
        usernameLabel->setFont(font);
        usernameInputBar = new QLineEdit(ClientUi);
        usernameInputBar->setObjectName("usernameInputBar");
        usernameInputBar->setGeometry(QRect(150, 70, 121, 21));
        passwordLabe = new QLabel(ClientUi);
        passwordLabe->setObjectName("passwordLabe");
        passwordLabe->setGeometry(QRect(320, 70, 91, 31));
        passwordLabe->setFont(font);
        passwordInputBar = new QLineEdit(ClientUi);
        passwordInputBar->setObjectName("passwordInputBar");
        passwordInputBar->setGeometry(QRect(420, 70, 121, 21));
        systemMsgBrowser = new QTextBrowser(ClientUi);
        systemMsgBrowser->setObjectName("systemMsgBrowser");
        systemMsgBrowser->setGeometry(QRect(440, 190, 441, 171));
        loginBtn = new QPushButton(ClientUi);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setGeometry(QRect(590, 60, 91, 31));
        PWDtestBtn = new QPushButton(ClientUi);
        PWDtestBtn->setObjectName("PWDtestBtn");
        PWDtestBtn->setGeometry(QRect(440, 110, 75, 24));
        LISTtestBtn = new QPushButton(ClientUi);
        LISTtestBtn->setObjectName("LISTtestBtn");
        LISTtestBtn->setGeometry(QRect(540, 110, 75, 24));
        PASVtestBtn = new QPushButton(ClientUi);
        PASVtestBtn->setObjectName("PASVtestBtn");
        PASVtestBtn->setGeometry(QRect(640, 110, 75, 24));
        serverFileTable = new QTableWidget(ClientUi);
        serverFileTable->setObjectName("serverFileTable");
        serverFileTable->setGeometry(QRect(440, 400, 441, 321));
        serverPathLabel = new QLabel(ClientUi);
        serverPathLabel->setObjectName("serverPathLabel");
        serverPathLabel->setGeometry(QRect(440, 370, 81, 21));
        MKDtestBtn = new QPushButton(ClientUi);
        MKDtestBtn->setObjectName("MKDtestBtn");
        MKDtestBtn->setGeometry(QRect(740, 110, 75, 24));
        RMDtestBtn = new QPushButton(ClientUi);
        RMDtestBtn->setObjectName("RMDtestBtn");
        RMDtestBtn->setGeometry(QRect(440, 150, 75, 24));

        retranslateUi(ClientUi);

        QMetaObject::connectSlotsByName(ClientUi);
    } // setupUi

    void retranslateUi(QWidget *ClientUi)
    {
        ClientUi->setWindowTitle(QCoreApplication::translate("ClientUi", "ClientUi", nullptr));
        connectBtn->setText(QCoreApplication::translate("ClientUi", "Connect", nullptr));
        hostLabel->setText(QCoreApplication::translate("ClientUi", "Host\357\274\232", nullptr));
        portLabel->setText(QCoreApplication::translate("ClientUi", "Port\357\274\232", nullptr));
        usernameLabel->setText(QCoreApplication::translate("ClientUi", "Username:", nullptr));
        passwordLabe->setText(QCoreApplication::translate("ClientUi", "Password:", nullptr));
        loginBtn->setText(QCoreApplication::translate("ClientUi", "Login", nullptr));
        PWDtestBtn->setText(QCoreApplication::translate("ClientUi", "PWD", nullptr));
        LISTtestBtn->setText(QCoreApplication::translate("ClientUi", "LIST", nullptr));
        PASVtestBtn->setText(QCoreApplication::translate("ClientUi", "PASV", nullptr));
        serverPathLabel->setText(QString());
        MKDtestBtn->setText(QCoreApplication::translate("ClientUi", "MKD", nullptr));
        RMDtestBtn->setText(QCoreApplication::translate("ClientUi", "RMD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientUi: public Ui_ClientUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_UI_H
