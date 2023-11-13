//
// Created by jgss9 on 11/3/2023.
//

#include "thread.h"


Thread::Thread(QByteArray* dataBuffer, QTcpSocket* dataSocket, QMutex* mutex,
               QWaitCondition* cv) : dataBuffer_(dataBuffer),
                                              dataSocket_(dataSocket),
                                              mutex_(mutex),
                                              cv_(cv) {}

void Thread::run() {
    forever{
        mutex_->lock();
        cv_->wait(mutex_);
        QByteArray data=dataSocket_->readAll();
        quint64 downloadedSize=data.length();
        dataBuffer_->append(qMove(data));
        mutex_->unlock();
//        qDebug()<<"downloadedSize:"<<downloadedSize<<'\n';
        emit downloadProcess(downloadedSize);
    }
}

