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
#include<QStandardPaths>
#include<QMutex>

#include"thread.h"
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
    QMutex mutex_;
    QWaitCondition cv_;
    Thread *workerThread_;

    bool ifStartReceiveTransfer_{false};
    bool ifReceiveTransferFinished_{false};
    bool ifStartSendTransfer_{false};
    bool ifSendTransferFinished_{false};

    bool ifStartList_{false};
    bool ifListFinished_{false};
    quint64 downloadSize_{0};
    QString uploadFilePath_;
    float transferPercentage_{0};
public:
    explicit Client(QObject *parent = nullptr);
    QString downloadFileName_;

    ~Client() override;

    QString curServerPath_;
    QString curClientPath_;
    bool isControlSocketConnected{false};

    void connectTo(const QHostAddress &, quint16);
    void disconnectFrom();

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

    void STOR(const QString &);

    void DELE(const QString &);

    void RNFR(const QString &);

    void RNTO(const QString &);

    void handleFtpResp(const FtpResp &);

    void handle257(const FtpResp &ftpResp);

    void handle550(const FtpResp &ftpResp);

    void handle150(const FtpResp &ftpResp);

    void handle226(const FtpResp &ftpResp);

    void handle425(const FtpResp &ftpResp);

    void handle250(const FtpResp &ftpResp);
    void handle350(const FtpResp &fptResp);
signals:

    void fileTableUpdate(const QVector<FtpFileInfo> &);

    void serverPathUpdate(const QString &);

    void clientPathUpdate(const QString &);

    void controlSocketConnected();

    void controlSocketDisconnected();

    void startTransfer();
    void processTransfer(float downloadPercentage);
    void finishTransfer();

public slots:

    void onControlSocketConnected();

    void onControlSocketDisconnected();

    void onControlSocketReadyRead();

    void onControlSocketWritten();

    void onDataSocketConnected();

    void onDataSocketDisconnected();

    void onDataSocketReadyRead();

    void onDataSocketWritten();
    void onDownloadProcessUpdate(quint64 downloadedSize);
};


#endif //VFTPCLIENT_CLIENT_H
