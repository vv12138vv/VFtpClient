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
    delete dataSocket_;
}

void Client::connectTo(const QHostAddress &host, quint16 port) {
    controlSocket_->connectToHost(host, port);
    //初始化客户端路径
    QStringList desktopPaths=QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    if(!desktopPaths.empty()){
        curClientPath_=desktopPaths.first();
        emit clientPathUpdate(curClientPath_);
    }
}


void Client::onControlSocketConnected() {
    emit controlSocketConnected();
}

void Client::onControlSocketDisconnected() {
    emit controlSocketDisconnected();
}

void Client::onControlSocketReadyRead() {
    QByteArray data = controlSocket_->readAll();
//    qDebug() << "data:" << data << '\n';
    controlReadBuffer_.append(qMove(data));
    QStringList respList;
    while (controlReadBuffer_.contains("\r\n")) {//读取并分割指令
        qsizetype respEnd = controlReadBuffer_.indexOf("\r\n");
        QString resp = controlReadBuffer_.left(respEnd + 2);
        controlReadBuffer_.remove(0, respEnd + 2);
        respList.append(resp);
    }
    for (auto &respStr: respList) {//处理每一条指令
        qDebug() << "respTest:" << respStr << "\n";
        FtpResp ftpResp(respStr);
        handleFtpResp(ftpResp);
    }
}

void Client::onControlSocketWritten() {
}


Logger *Client::getLogger() {
    return logger_;
}


void Client::handleFtpResp(const FtpResp &ftpResp) {
    switch (ftpResp.statusCode_) {
        case FTP_NEED_PASSWORD: {
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
            LIST();
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
            handle226(ftpResp);
//            logger_->log("文件操作成功");
            break;
        }
        case FTP_LIST_DIR: {
            handle150(ftpResp);
//            logger_->log("成功获取文件目录");
            break;
        }
        case FTP_PATHNAME_CREATED: {
            handle257(ftpResp);
            break;
        }
        default: {
            break;
        }
    }
}


void Client::onDataSocketConnected() {
    qDebug() << "dataSocket connected" << "\n";
}

void Client::onDataSocketDisconnected() {
    qDebug() << "dataSocket disconnected" << "\n";
}

void Client::onDataSocketReadyRead() {
    QByteArray data = dataSocket_->readAll();
    dataReadBuffer_.append(qMove(data));
}

void Client::onDataSocketWritten() {

}

void Client::USER(const QString &username) {
    QString cmd = "USER " + username + "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::PASS(const QString &password) {
    QString cmd = "PASS " + password + "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::PWD() {
    QString cmd = "PWD\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::LIST() {
    PWD();
    if(dataSocket_->state()!=QAbstractSocket::ConnectedState){
        PASV();
    }
    QString cmd = "LIST\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::PASV() {
    QString cmd = "PASV\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::MKD(const QString &dirPath) {
    QString cmd = "MKD " + dirPath + "\r\n";
    controlSocket_->write(cmd.toUtf8());
    LIST();
}

void Client::RMD(const QString &dirPath) {
    QString cmd = "RMD " + dirPath + "\r\n";
    controlSocket_->write(cmd.toUtf8());
    LIST();
}

void Client::RETR(const QString &filePath) {
    if(dataSocket_->state()!=QAbstractSocket::ConnectedState){
        PASV();
    }
    QString cmd = "RETR " + filePath + "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::CWD(const QString &path) {
    QString cmd = "CWD " + path + "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::STOR(const QString &filePath) {
    uploadFilePath_=filePath;
    qDebug()<<"filePath"<<Util::parseFileName(uploadFilePath_)<<'\n';
    if(dataSocket_->state()!=QAbstractSocket::ConnectedState){
        PASV();
    }
    QString cmd = "STOR " +Util::parseFileName(uploadFilePath_)+ "\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::DELE(const QString &filePath) {
    QString cmd="DELE "+filePath+"\r\n";
    controlSocket_->write(cmd.toUtf8());
}

void Client::handle257(const FtpResp &ftpResp) {
    QString statusMsg = ftpResp.statusMsg_;
    QString path = qMove(Util::parsePath(ftpResp.statusMsg_));
    if (statusMsg.contains("created") && !statusMsg.contains("is the current directory")) {
        logger_->log("创建新文件夹:" + path);
    } else if (statusMsg.contains("is the current directory")) {
        curServerPath_ = path;
        emit serverPathUpdate(curServerPath_);
    }
};

void Client::handle550(const FtpResp &ftpResp) {

}

void Client::handle150(const FtpResp &ftpResp) {
    QString statusMsg = ftpResp.statusMsg_;
    if (statusMsg.contains("Opening BINARY mode data connection")) {
        ifStartReceiveTransfer_ = true;
        ifReceiveTransferFinished_ = false;
        QPair<QString, quint64> downLoadInfo = Util::parseDownloadInfo(ftpResp.statusMsg_);
        downloadSize_ = downLoadInfo.second;
        downloadFileName_ = Util::parseFileName(downLoadInfo.first);

    } else if (statusMsg.contains("Here comes the directory listing")) {
        qDebug() << "update list state: startList" << "\n";
        ifStartList_ = true;
        ifListFinished_ = false;
    } else if (statusMsg.contains("Ok to send data")) {
        ifStartSendTransfer_ = true;
        ifSendTransferFinished_ = false;
        QString filePath = uploadFilePath_;
        QFile file(filePath);
        file.open(QIODevice::ReadOnly);
        QByteArray data = file.readAll();
        qDebug() << "upload size" << data.size() << '\n';
        dataSocket_->write(data);
        dataSocket_->close();
    }
}

void Client::handle226(const FtpResp &ftpResp) {
    QString statusMsg = ftpResp.statusMsg_;
    if (statusMsg.contains("Transfer complete")) {
        if (!ifReceiveTransferFinished_ && ifStartReceiveTransfer_) {
            ifReceiveTransferFinished_ = true;
            ifStartReceiveTransfer_ = false;
            QString savePath(curClientPath_+'/'+downloadFileName_);
            qDebug() << "savePath:" << savePath << '\n';
            QFile file(savePath);
            file.open(QIODevice::Append);
            file.write(qMove(dataReadBuffer_.left(downloadSize_)));
            dataReadBuffer_.remove(0, downloadSize_);
            file.close();
            logger_->log("文件下载成功");
            qDebug() << "dataBuffer size" << dataReadBuffer_.size() << '\n';
        } else if (ifStartSendTransfer_ && !ifSendTransferFinished_) {
            ifSendTransferFinished_ = true;
            ifStartSendTransfer_ = false;
            LIST();
            logger_->log("文件上传成功");
        }
    } else if (statusMsg.contains("Directory send OK")) {
        ifListFinished_ = true;
        ifStartList_ = false;
        QByteArray fileListData = dataReadBuffer_.left(dataReadBuffer_.size());
        qDebug() << "fileListData" << fileListData << '\n';
        dataReadBuffer_.remove(0, dataReadBuffer_.size());
//        qDebug() << "removed dataReadBuffer:" << dataReadBuffer_.size() << '\n';
        QString fileListStr(fileListData);
        auto fileInfoList = Util::parseFtpList(fileListStr);
        for (auto i: fileInfoList) {
            i.print();
        }
        emit fileTableUpdate(fileInfoList);
        logger_->log("文件列表更新成功");
    }
}

void Client::handle425(const FtpResp &ftpResp) {

}