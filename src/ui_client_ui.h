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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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

    void setupUi(QWidget *ClientUi)
    {
        if (ClientUi->objectName().isEmpty())
            ClientUi->setObjectName("ClientUi");
        ClientUi->resize(800, 600);
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
        systemMsgBrowser->setGeometry(QRect(530, 150, 261, 431));
        loginBtn = new QPushButton(ClientUi);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setGeometry(QRect(590, 60, 91, 31));
        PWDtestBtn = new QPushButton(ClientUi);
        PWDtestBtn->setObjectName("PWDtestBtn");
        PWDtestBtn->setGeometry(QRect(420, 150, 75, 24));
        LISTtestBtn = new QPushButton(ClientUi);
        LISTtestBtn->setObjectName("LISTtestBtn");
        LISTtestBtn->setGeometry(QRect(420, 200, 75, 24));
        PASVtestBtn = new QPushButton(ClientUi);
        PASVtestBtn->setObjectName("PASVtestBtn");
        PASVtestBtn->setGeometry(QRect(420, 250, 75, 24));

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
    } // retranslateUi

};

namespace Ui {
    class ClientUi: public Ui_ClientUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_UI_H