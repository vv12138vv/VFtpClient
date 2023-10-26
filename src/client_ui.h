//
// Created by jgss9 on 10/25/2023.
//

#ifndef VFTPCLIENT_CLIENT_UI_H
#define VFTPCLIENT_CLIENT_UI_H

#include <QWidget>
#include<QPointer>
#include<QRegularExpression>
#include<QDebug>
#include "client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class ClientUi; }
QT_END_NAMESPACE

class ClientUi : public QWidget {
Q_OBJECT

private:
    Ui::ClientUi *ui;
    QPointer<Client> client_;
    QHostAddress targetHost_;
    quint16 targetPort_;
    QString username_;
    QString password_;
public:
    explicit ClientUi(QWidget *parent = nullptr);
    void initSlots();
    ~ClientUi() override;

public slots:
    void onConnectBtnClicked();
    void onLoginBtnClicked();
    void onPortBarEdited();
    void onHostBarEdited();
    void onUsernameBarEdited();
    void onPasswordBarEdited();
    void onNewLog(const QString& logMsg);
    void onFileTableUpdate(const QVector<FtpFileInfo>&);
    void onServerPathUpdate(const QString&);
    void onPWDtestBtnClicked();
    void onLISTtestBtnClicked();
    void onPASVtestBtnClicked();
    void onMKDtestBtnClicked();
    void onRMDtestBtnClicked();
};


#endif //VFTPCLIENT_CLIENT_UI_H
