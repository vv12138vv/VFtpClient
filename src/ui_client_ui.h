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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *CWDTestBtn;
    QPushButton *RETRtestBtn;
    QPushButton *STORtestBtn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *clientInfoLayout;
    QLineEdit *clientPathBar;
    QTableWidget *clientFileTable;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *serverInfoLayout;
    QLineEdit *serverPathBar;
    QTableWidget *serverFileTable;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *loadBtnsLayout;
    QPushButton *uploadBtn;
    QPushButton *downloadBtn;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mkdirLayout;
    QLineEdit *mkdirInputBar;
    QPushButton *mkdirBtn;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *rmdirInputBar;
    QPushButton *rmdirBtn;

    void setupUi(QWidget *ClientUi)
    {
        if (ClientUi->objectName().isEmpty())
            ClientUi->setObjectName("ClientUi");
        ClientUi->resize(1000, 750);
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
        systemMsgBrowser->setGeometry(QRect(10, 120, 441, 171));
        loginBtn = new QPushButton(ClientUi);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setGeometry(QRect(590, 60, 91, 31));
        PWDtestBtn = new QPushButton(ClientUi);
        PWDtestBtn->setObjectName("PWDtestBtn");
        PWDtestBtn->setGeometry(QRect(560, 110, 75, 24));
        LISTtestBtn = new QPushButton(ClientUi);
        LISTtestBtn->setObjectName("LISTtestBtn");
        LISTtestBtn->setGeometry(QRect(660, 110, 75, 24));
        PASVtestBtn = new QPushButton(ClientUi);
        PASVtestBtn->setObjectName("PASVtestBtn");
        PASVtestBtn->setGeometry(QRect(760, 110, 75, 24));
        CWDTestBtn = new QPushButton(ClientUi);
        CWDTestBtn->setObjectName("CWDTestBtn");
        CWDTestBtn->setGeometry(QRect(660, 150, 75, 24));
        RETRtestBtn = new QPushButton(ClientUi);
        RETRtestBtn->setObjectName("RETRtestBtn");
        RETRtestBtn->setGeometry(QRect(760, 150, 75, 24));
        STORtestBtn = new QPushButton(ClientUi);
        STORtestBtn->setObjectName("STORtestBtn");
        STORtestBtn->setGeometry(QRect(860, 150, 75, 24));
        verticalLayoutWidget = new QWidget(ClientUi);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 370, 451, 351));
        clientInfoLayout = new QVBoxLayout(verticalLayoutWidget);
        clientInfoLayout->setObjectName("clientInfoLayout");
        clientInfoLayout->setContentsMargins(0, 0, 0, 0);
        clientPathBar = new QLineEdit(verticalLayoutWidget);
        clientPathBar->setObjectName("clientPathBar");

        clientInfoLayout->addWidget(clientPathBar);

        clientFileTable = new QTableWidget(verticalLayoutWidget);
        clientFileTable->setObjectName("clientFileTable");

        clientInfoLayout->addWidget(clientFileTable);

        verticalLayoutWidget_2 = new QWidget(ClientUi);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(530, 370, 461, 351));
        serverInfoLayout = new QVBoxLayout(verticalLayoutWidget_2);
        serverInfoLayout->setObjectName("serverInfoLayout");
        serverInfoLayout->setContentsMargins(0, 0, 0, 0);
        serverPathBar = new QLineEdit(verticalLayoutWidget_2);
        serverPathBar->setObjectName("serverPathBar");

        serverInfoLayout->addWidget(serverPathBar);

        serverFileTable = new QTableWidget(verticalLayoutWidget_2);
        serverFileTable->setObjectName("serverFileTable");

        serverInfoLayout->addWidget(serverFileTable);

        verticalLayoutWidget_3 = new QWidget(ClientUi);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(470, 430, 77, 241));
        loadBtnsLayout = new QVBoxLayout(verticalLayoutWidget_3);
        loadBtnsLayout->setObjectName("loadBtnsLayout");
        loadBtnsLayout->setContentsMargins(0, 0, 0, 0);
        uploadBtn = new QPushButton(verticalLayoutWidget_3);
        uploadBtn->setObjectName("uploadBtn");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Mono SemiBold")});
        font1.setPointSize(13);
        uploadBtn->setFont(font1);

        loadBtnsLayout->addWidget(uploadBtn);

        downloadBtn = new QPushButton(verticalLayoutWidget_3);
        downloadBtn->setObjectName("downloadBtn");
        downloadBtn->setFont(font1);

        loadBtnsLayout->addWidget(downloadBtn);

        horizontalLayoutWidget = new QWidget(ClientUi);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(520, 330, 231, 31));
        mkdirLayout = new QHBoxLayout(horizontalLayoutWidget);
        mkdirLayout->setObjectName("mkdirLayout");
        mkdirLayout->setContentsMargins(0, 0, 0, 0);
        mkdirInputBar = new QLineEdit(horizontalLayoutWidget);
        mkdirInputBar->setObjectName("mkdirInputBar");

        mkdirLayout->addWidget(mkdirInputBar);

        mkdirBtn = new QPushButton(horizontalLayoutWidget);
        mkdirBtn->setObjectName("mkdirBtn");

        mkdirLayout->addWidget(mkdirBtn);

        horizontalLayoutWidget_2 = new QWidget(ClientUi);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(760, 330, 231, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rmdirInputBar = new QLineEdit(horizontalLayoutWidget_2);
        rmdirInputBar->setObjectName("rmdirInputBar");

        horizontalLayout->addWidget(rmdirInputBar);

        rmdirBtn = new QPushButton(horizontalLayoutWidget_2);
        rmdirBtn->setObjectName("rmdirBtn");

        horizontalLayout->addWidget(rmdirBtn);


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
        CWDTestBtn->setText(QCoreApplication::translate("ClientUi", "CWD", nullptr));
        RETRtestBtn->setText(QCoreApplication::translate("ClientUi", "RETR", nullptr));
        STORtestBtn->setText(QCoreApplication::translate("ClientUi", "STOR", nullptr));
        uploadBtn->setText(QCoreApplication::translate("ClientUi", ">>", nullptr));
        downloadBtn->setText(QCoreApplication::translate("ClientUi", "<<", nullptr));
        mkdirBtn->setText(QCoreApplication::translate("ClientUi", "MKD", nullptr));
        rmdirBtn->setText(QCoreApplication::translate("ClientUi", "RMD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientUi: public Ui_ClientUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_UI_H
