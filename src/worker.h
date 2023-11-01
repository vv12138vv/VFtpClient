//
// Created by jgss9 on 11/1/2023.
//

#ifndef VFTPCLIENT_WORKER_H
#define VFTPCLIENT_WORKER_H
#include<QObject>
#include<QPointer>
#include<QTcpSocket>

#include"task.h"
class Worker:public QObject {
Q_OBJECT
private:
    QPointer<TaskQueue> taskQueue_;
    QPointer<QTcpSocket> dataSocket_;
public:
    Worker(QPointer<TaskQueue> taskQueue,QObject* parent= nullptr);
public slots:
    void startWorking();
signals:
    void taskFinished(Task task);
};


#endif //VFTPCLIENT_WORKER_H
