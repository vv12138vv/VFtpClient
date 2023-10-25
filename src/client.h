//
// Created by jgss9 on 10/25/2023.
//

#ifndef VFTPCLIENT_CLIENT_H
#define VFTPCLIENT_CLIENT_H

#include<QObject>
#include<QTcpSocket>
#include<QPointer>
#include<QHostAddress>
#include"logger.h"
#include"common.h"
class Client : public QObject {
Q_OBJECT

private:
    QPointer<QTcpSocket> controlSocket_;
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
    void handleFtpResp(const FtpResp&);
public slots:

    void onControlSocketConnected();

    void onControlSocketDisconnected();

    void onControlSocketReadyRead();

    void onControlSocketWritten();

};


#endif //VFTPCLIENT_CLIENT_H
