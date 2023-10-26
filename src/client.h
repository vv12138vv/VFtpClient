//
// Created by jgss9 on 10/25/2023.
//

#ifndef VFTPCLIENT_CLIENT_H
#define VFTPCLIENT_CLIENT_H

#include<QObject>
#include<QTcpSocket>
#include<QPointer>
#include<QHostAddress>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include"logger.h"
#include"common.h"
#include"util.h"

class Client : public QObject {
Q_OBJECT

private:
    QPointer<QTcpSocket> controlSocket_;
    QPointer<QTcpSocket> dataSocket_;
    QPointer<Logger> logger_;
public:
    explicit Client(QObject *parent = nullptr);

    ~Client() override;

    void connectTo(const QHostAddress &, quint16);

    void sendCmd();

    Logger *getLogger();

    void login(const QString &username, const QString &password);

    void PWD();

    void LIST();

    void PASV();

    void MKD(const QString&);

    void RMD(const QString&);
    void RETR(const QString&);

    void handleFtpResp(const FtpResp &);

signals:
    void fileTableUpdate(const QVector<FtpFileInfo>&);
    void serverPathUpdate(const QString&);
public slots:

    void onControlSocketConnected();

    void onControlSocketDisconnected();

    void onControlSocketReadyRead();

    void onControlSocketWritten();

    void onDataSocketConnected();

    void onDataSocketDisconnected();

    void onDataSocketReadyRead();

    void onDataSocketWritten();


};


#endif //VFTPCLIENT_CLIENT_H
