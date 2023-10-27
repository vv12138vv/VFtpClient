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
    dataSocket_ = new QTcpSocket(this);
    connect(dataSocket_, &QTcpSocket::connected, this, &Client::onDataSocketConnected);
    connect(dataSocket_, &QTcpSocket::disconnected, this, &Client::onDataSocketDisconnected);
    connect(dataSocket_, &QTcpSocket::readyRead, this, &Client::onDataSocketReadyRead);
    connect(dataSocket_, &QTcpSocket::bytesWritten, this, &Client::onDataSocketWritten);
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
    qDebug() << "data:" << data << '\n';
    controlReadBuffer_.append(qMove(data));
    QStringList respList;
    while (controlReadBuffer_.contains("\r\n")) {
        int respEnd = controlReadBuffer_.indexOf("\r\n");
        QString resp = controlReadBuffer_.left(respEnd + 2);
        controlReadBuffer_.remove(0, respEnd + 2);
        respList.append(resp);
    }
    for (auto &respStr: respList) {
        qDebug() << "respTest:" << respStr << "\n";
        FtpResp ftpResp(respStr);
        handleFtpResp(ftpResp);
    }
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
    QString cmd = "USER " + username + "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::PWD() {
    QString cmd = "PWD\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::handleFtpResp(const FtpResp &ftpResp) {
    switch (ftpResp.statusCode_) {
        case FTP_NEED_PASSWORD: {
            QString cmd = "PASS vv12138vv\r\n";
            QByteArray writeData = cmd.toUtf8();
            controlSocket_->write(writeData);
            break;
        }
        case FTP_PASV: {
            auto pair = Util::parsePasvResp(ftpResp.statusMsg_);
            qDebug() << "PASV:" << pair.first << "\n";
            qDebug() << "PASV" << pair.second << "\n";
            dataSocket_->connectToHost(QHostAddress(pair.first), pair.second);
            break;
        }
        case FTP_CONNECT_SUCCESS: {
            logger_->log("连接成功");
            break;
        }
        case FTP_LOGIN_SUCCESS: {
            logger_->log("登录成功");
            break;
        }
        case FTP_LOGIN_INCORRECT: {
            logger_->log("登陆失败，请重新输入用户名密码");
            break;
        }
        case FTP_END: {
            logger_->log("再见");
            break;
        }
        case FTP_CONNECTION_ERROR: {
            logger_->log(ftpResp.statusMsg_);
            break;
        }
        case FTP_TIME_OUT: {
            logger_->log("连接超时");
            break;
        }
        case FTP_FILE_ACTION_COMPLETED: {
            logger_->log("文件操作成功");
            break;
        }
        case FTP_LIST_DIR: {
            logger_->log("成功获取文件目录");
            break;
        }
        case FTP_PATHNAME_CREATED: {
            handle257(ftpResp);
//            logger_->log("成功获取路径");
//            QString path=qMove(Util::parsePath(ftpResp.statusMsg_));
//            emit serverPathUpdate(path);
            break;
        }
        default: {
            break;
        }
    }
}

void Client::LIST() {
    PWD();
    PASV();
    QString cmd = "LIST\r\n";
    controlSocket_->write(cmd.toUtf8());
//    logger_->log(cmd);
}

void Client::PASV() {
    QString cmd = "PASV\r\n";
    controlSocket_->write(cmd.toUtf8());
}


void Client::onDataSocketConnected() {
    qDebug() << "dataSocket connected" << "\n";
}

void Client::onDataSocketDisconnected() {
    qDebug() << "dataSocket disconnected" << "\n";
}

void Client::onDataSocketReadyRead() {
    QByteArray data = dataSocket_->readAll();
    QString fileListStr(data);
    auto fileInfoList = Util::parseFtpList(fileListStr);
    for (auto i: fileInfoList) {
        i.print();
    }
    emit  fileTableUpdate(fileInfoList);
}

void Client::onDataSocketWritten() {

}

void Client::MKD(const QString &dirName) {
    QString testName = "testFolder";
    QString cmd = "MKD " + testName + "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::RMD(const QString &dirName) {
    QString testName = "testFolder";
    QString cmd = "RMD " + testName + "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::RETR(const QString &fileName) {

}


void Client::handle257(const FtpResp &ftpResp) {
    QString statusMsg = ftpResp.statusMsg_;
    QString path = qMove(Util::parsePath(ftpResp.statusMsg_));
    if (statusMsg.contains("created") && !statusMsg.contains("is the current directory")) {
        logger_->log("创建新文件夹:"+path);
    } else if (statusMsg.contains("is the current directory")) {
        emit serverPathUpdate(path);
    }
};