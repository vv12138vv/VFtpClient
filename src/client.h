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
#include<QFile>
#include"logger.h"
#include"common.h"
#include"util.h"

class Client : public QObject {
Q_OBJECT

private:
    QPointer<QTcpSocket> controlSocket_;
    QPointer<QTcpSocket> dataSocket_;
    QPointer<Logger> logger_;
    QByteArray controlReadBuffer_;
    QByteArray dataReadBuffer_;
    QString curServerPath_;
    bool ifStartTransfer_{false};
    bool ifTransferFinished_{false};
    bool ifStartList_{false};
    bool ifListFinished_{false};
    quint64 downloadSize_{0};
    QString downloadFileName_;
public:
    explicit Client(QObject *parent = nullptr);

    ~Client() override;

    void connectTo(const QHostAddress &, quint16);

    void sendCmd();

    Logger *getLogger();

    void USER(const QString &username);

    void PASS(const QString &password);

    void PWD();

    void LIST();

    void PASV();

    void MKD(const QString &);

    void RMD(const QString &);

    void CWD(const QString &);

    void RETR(const QString &);

    void STOR(const QString&);

    void handleFtpResp(const FtpResp &);

    void handle257(const FtpResp &ftpResp);

    void handle550(const FtpResp &ftpResp);

    void handle150(const FtpResp &ftpResp);

    void handle226(const FtpResp &ftpResp);

    void handle425(const FtpResp& ftpResp);
signals:

    void fileTableUpdate(const QVector<FtpFileInfo> &);

    void serverPathUpdate(const QString &);

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
