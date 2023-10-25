//
// Created by jgss9 on 10/25/2023.
//

#include "client.h"

Client::Client(QObject *parent) : QObject(parent) {
    logger_ = new Logger(this);
    controlSocket_ = new QTcpSocket(this);
    connect(controlSocket_, &QTcpSocket::connected, this, &Client::onControlSocketConnected);
    connect(controlSocket_, &QTcpSocket::disconnected, this, &Client::onControlSocketDisconnected);
    connect(controlSocket_, &QTcpSocket::readyRead, this, &Client::onControlSocketReadyRead);
    connect(controlSocket_, &QTcpSocket::bytesWritten, this, &Client::onControlSocketWritten);
}

Client::~Client() {
    delete controlSocket_;
}

void Client::connectTo(const QHostAddress &host, quint16 port) {
    controlSocket_->connectToHost(host, port);
}


void Client::onControlSocketConnected() {
//    logger_->log(QString("成功连接"));
}

void Client::onControlSocketDisconnected() {

}

void Client::onControlSocketReadyRead() {
    QByteArray data = controlSocket_->readAll();
//    qDebug() << "QByteArray:" << data << "\n";
    QString response = QString(data);
    qDebug()<<"QString:"<<response<<'\n';
    FtpResp ftpResp(response);
//    qDebug()<<"statusCode:"<<ftpResp.statusCode_<<"\n";
//    qDebug()<<"statusMsg:"<<ftpResp.statusMsg_<<"\n";
    handleFtpResp(ftpResp);
}

void Client::onControlSocketWritten() {
//    logger_->log(QString("命令成功发送"));
}

void Client::sendCmd() {

}

Logger *Client::getLogger() {
    return logger_;
}

void Client::login(const QString &username, const QString &password) {
    QString cmd = "USER " + username + '\n';
    QByteArray writeData = cmd.toUtf8();
    controlSocket_->write(writeData);
}

void Client::PWD(){
    QString cmd="PWD\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::handleFtpResp(const FtpResp &ftpResp) {
    switch (ftpResp.statusCode_) {
        case FTP_NEED_PASSWORD:{
            QString cmd = "PASS vv12138vv\n";
            QByteArray writeData = cmd.toUtf8();
            controlSocket_->write(writeData);
            break;
        }
        case FTP_CONNECT_SUCCESS:{
            logger_->log("连接成功");
            break;
        }
        case FTP_LOGIN_SUCCESS:{
            logger_->log("登录成功");
            break;
        }
        case FTP_LOGIN_INCORRECT:{
            logger_->log("登陆失败，请重新输入用户名密码");
            break;
        }
        case FTP_END:{
            logger_->log("再见");
            break;
        }
        case FTP_CONNECTION_ERROR:{
            logger_->log("连接错误");
            break;
        }
        case FTP_TIME_OUT:{
            logger_->log("连接超时");
        }
        default:{
            break;
        }
    }
//    qDebug()<<"handle end"<<"\n";
}

void Client::LIST() {
    QString cmd="LIST .\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::PASV() {
    QString cmd="PASV\n";
    controlSocket_->write(cmd.toUtf8());
}

