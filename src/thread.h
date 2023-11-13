//
// Created by jgss9 on 11/3/2023.
//

#ifndef VFTPCLIENT_THREAD_H
#define VFTPCLIENT_THREAD_H

#include<QThread>
#include<QObject>
#include<QTcpSocket>
#include<QPointer>
#include<QMutex>
#include<QWaitCondition>
#include<QMutexLocker>
#include<QByteArray>
#include<QMutexLocker>

class Thread:public QThread {
    Q_OBJECT
private:
    QByteArray* dataBuffer_;
    QTcpSocket* dataSocket_;
    QMutex* mutex_;
    QWaitCondition* cv_;
public:
    Thread(QByteArray* dataBuffer,QTcpSocket* dataSocket,QMutex* mutex,QWaitCondition* cv);
    ~Thread()=default;
    void run() override;
signals:
    void downloadProcess(quint64 downloadedSize);
};


#endif //VFTPCLIENT_THREAD_H
