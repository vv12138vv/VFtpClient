//
// Created by jgss9 on 10/25/2023.
//

#ifndef VFTPCLIENT_COMMON_H
#define VFTPCLIENT_COMMON_H

#include<QObject>
#include<QDebug>
enum FtpCode {
    FTP_CONNECT_SUCCESS = 220,
    FTP_LOGIN_SUCCESS = 230,
    FTP_FILE_ACTION_COMPLETED = 226,
    FTP_COMMAND_OK = 250,
    FTP_PATHNAME_CREATED = 257,
    FTP_NEED_PASSWORD = 331,
    FTP_FILE_NOT_FOUND = 550,
    FTP_PERMISSION_DENIED = 550,
    FTP_COMMAND_FAILED = 500,
    FTP_SERVICE_UNAVAILABLE = 421,
    FTP_LOGIN_INCORRECT = 530,
    FTP_END=221,
    FTP_CONNECTION_ERROR=425,
    FTP_TIME_OUT=421,
    FTP_LIST_DIR=150,
    FTP_PASV=227,
    FTP_RECV_DIR=150
};

struct FtpResp {
    quint16 statusCode_;
    QString statusMsg_;

    explicit FtpResp(const QString &responseMsg) {
        statusCode_ = responseMsg.left(3).toUInt();
        statusMsg_ = responseMsg.mid(4).trimmed();
    }

    FtpResp(quint16 statusCode, const QString &statusMsg) : statusCode_(statusCode), statusMsg_(statusMsg) {}
};

struct FtpFileInfo{
    bool isDir;
    QString permissions;
    QString owner;
    QString group;
    int size;
    QString month;
    QString day;
    QString time;
    QString name;
    void print(){

        char flag=isDir?'d':'-';
//        QString str=flag+' '+permissions+' '+owner+' '+group+' '+QString::number(size)+' '+month+' '+day+' '+time+' '+name;
//        qDebug()<<str<<"\n";
        qDebug()<<flag<<' '<<permissions<<' '<<owner<<' '<<group<<' '<<QString::number(size)<<' '<<month<<' '<<day<<' '<<time<<' '<<name<<'\n';
    }
};

#endif //VFTPCLIENT_COMMON_H
