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
#include <QtWidgets/QProgressBar>
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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *clientInfoLayout;
    QLineEdit *clientPathBar;
    QTableWidget *clientFileTable;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *serverInfoLayout;
    QLineEdit *serverPathBar;
    QTableWidget *serverFileTable;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mkdirLayout;
    QLineEdit *mkdirInputBar;
    QPushButton *mkdirBtn;
    QPushButton *uploadBtn;
    QPushButton *downloadBtn;
    QLabel *connectionStatusLabel;
    QLabel *connectionStatus;
    QPushButton *updateListBtn;
    QPushButton *clientUpdateListBtn;
    QProgressBar *transferProgressBar;
    QLabel *transferFileInfo;
    QLabel *transferType;

    void setupUi(QWidget *ClientUi)
    {
        if (ClientUi->objectName().isEmpty())
            ClientUi->setObjectName("ClientUi");
        ClientUi->resize(1000, 750);
        ClientUi->setWindowOpacity(1.000000000000000);
        connectBtn = new QPushButton(ClientUi);
        connectBtn->setObjectName("connectBtn");
        connectBtn->setGeometry(QRect(590, 20, 91, 31));
        connectBtn->setCursor(QCursor(Qt::PointingHandCursor));
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
        usernameLabel->setGeometry(QRect(60, 70, 81, 21));
        usernameLabel->setFont(font);
        usernameInputBar = new QLineEdit(ClientUi);
        usernameInputBar->setObjectName("usernameInputBar");
        usernameInputBar->setGeometry(QRect(150, 70, 121, 21));
        passwordLabe = new QLabel(ClientUi);
        passwordLabe->setObjectName("passwordLabe");
        passwordLabe->setGeometry(QRect(320, 70, 81, 21));
        passwordLabe->setFont(font);
        passwordInputBar = new QLineEdit(ClientUi);
        passwordInputBar->setObjectName("passwordInputBar");
        passwordInputBar->setGeometry(QRect(420, 70, 121, 21));
        passwordInputBar->setEchoMode(QLineEdit::Password);
        systemMsgBrowser = new QTextBrowser(ClientUi);
        systemMsgBrowser->setObjectName("systemMsgBrowser");
        systemMsgBrowser->setGeometry(QRect(10, 140, 451, 181));
        loginBtn = new QPushButton(ClientUi);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setGeometry(QRect(590, 70, 91, 31));
        loginBtn->setCursor(QCursor(Qt::PointingHandCursor));
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
        clientFileTable->setContextMenuPolicy(Qt::CustomContextMenu);

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
        serverFileTable->setContextMenuPolicy(Qt::CustomContextMenu);

        serverInfoLayout->addWidget(serverFileTable);

        horizontalLayoutWidget = new QWidget(ClientUi);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(530, 330, 231, 31));
        mkdirLayout = new QHBoxLayout(horizontalLayoutWidget);
        mkdirLayout->setObjectName("mkdirLayout");
        mkdirLayout->setContentsMargins(0, 0, 0, 0);
        mkdirInputBar = new QLineEdit(horizontalLayoutWidget);
        mkdirInputBar->setObjectName("mkdirInputBar");

        mkdirLayout->addWidget(mkdirInputBar);

        mkdirBtn = new QPushButton(horizontalLayoutWidget);
        mkdirBtn->setObjectName("mkdirBtn");
        mkdirBtn->setCursor(QCursor(Qt::PointingHandCursor));

        mkdirLayout->addWidget(mkdirBtn);

        uploadBtn = new QPushButton(ClientUi);
        uploadBtn->setObjectName("uploadBtn");
        uploadBtn->setGeometry(QRect(470, 600, 51, 28));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Mono SemiBold")});
        font1.setPointSize(13);
        uploadBtn->setFont(font1);
        uploadBtn->setCursor(QCursor(Qt::PointingHandCursor));
        downloadBtn = new QPushButton(ClientUi);
        downloadBtn->setObjectName("downloadBtn");
        downloadBtn->setGeometry(QRect(470, 460, 51, 28));
        downloadBtn->setFont(font1);
        downloadBtn->setCursor(QCursor(Qt::PointingHandCursor));
        connectionStatusLabel = new QLabel(ClientUi);
        connectionStatusLabel->setObjectName("connectionStatusLabel");
        connectionStatusLabel->setGeometry(QRect(730, 20, 121, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cascadia Code")});
        font2.setPointSize(8);
        connectionStatusLabel->setFont(font2);
        connectionStatus = new QLabel(ClientUi);
        connectionStatus->setObjectName("connectionStatus");
        connectionStatus->setGeometry(QRect(850, 20, 101, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cascadia Code")});
        font3.setPointSize(10);
        connectionStatus->setFont(font3);
        connectionStatus->setStyleSheet(QString::fromUtf8("color: red;"));
        updateListBtn = new QPushButton(ClientUi);
        updateListBtn->setObjectName("updateListBtn");
        updateListBtn->setGeometry(QRect(960, 330, 30, 30));
        updateListBtn->setCursor(QCursor(Qt::PointingHandCursor));
        clientUpdateListBtn = new QPushButton(ClientUi);
        clientUpdateListBtn->setObjectName("clientUpdateListBtn");
        clientUpdateListBtn->setGeometry(QRect(430, 330, 30, 30));
        clientUpdateListBtn->setCursor(QCursor(Qt::PointingHandCursor));
        transferProgressBar = new QProgressBar(ClientUi);
        transferProgressBar->setObjectName("transferProgressBar");
        transferProgressBar->setGeometry(QRect(530, 200, 291, 21));
        transferProgressBar->setValue(24);
        transferFileInfo = new QLabel(ClientUi);
        transferFileInfo->setObjectName("transferFileInfo");
        transferFileInfo->setGeometry(QRect(660, 170, 70, 20));
        transferType = new QLabel(ClientUi);
        transferType->setObjectName("transferType");
        transferType->setGeometry(QRect(530, 170, 70, 20));

        retranslateUi(ClientUi);

        QMetaObject::connectSlotsByName(ClientUi);
    } // setupUi

    void retranslateUi(QWidget *ClientUi)
    {
        ClientUi->setWindowTitle(QCoreApplication::translate("ClientUi", "VFtp", nullptr));
        connectBtn->setText(QCoreApplication::translate("ClientUi", "Connect", nullptr));
        hostLabel->setText(QCoreApplication::translate("ClientUi", "Host\357\274\232", nullptr));
        portLabel->setText(QCoreApplication::translate("ClientUi", "Port\357\274\232", nullptr));
        usernameLabel->setText(QCoreApplication::translate("ClientUi", "Username:", nullptr));
        passwordLabe->setText(QCoreApplication::translate("ClientUi", "Password:", nullptr));
        loginBtn->setText(QCoreApplication::translate("ClientUi", "Login", nullptr));
        mkdirBtn->setText(QCoreApplication::translate("ClientUi", "MKD", nullptr));
        uploadBtn->setText(QCoreApplication::translate("ClientUi", ">>", nullptr));
        downloadBtn->setText(QCoreApplication::translate("ClientUi", "<<", nullptr));
        connectionStatusLabel->setText(QCoreApplication::translate("ClientUi", "Connection Status\357\274\232", nullptr));
        connectionStatus->setText(QCoreApplication::translate("ClientUi", "Disconnected", nullptr));
        updateListBtn->setText(QString());
        clientUpdateListBtn->setText(QString());
        transferFileInfo->setText(QCoreApplication::translate("ClientUi", "fileName", nullptr));
        transferType->setText(QCoreApplication::translate("ClientUi", "taskType", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientUi: public Ui_ClientUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_UI_H
