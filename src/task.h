//
// Created by jgss9 on 11/1/2023.
//

#ifndef VFTPCLIENT_TASK_H
#define VFTPCLIENT_TASK_H

#include<QObject>
#include<QQueue>
#include<QMutex>
#include<QWaitCondition>
#include<QPointer>
enum TaskType {
    Download,
    Upload,
    List
};

class Task:public QObject{
Q_OBJECT
public:
    quint32 id;
    TaskType type;
    quint64 size;
    QString fileName;
    QString localPath;
    QString remotePath;
    Task(const Task& that);
};


class TaskQueue:public QObject{
    Q_OBJECT
private:
    QQueue<QPointer<Task>> taskQueue_;
    QMutex mutex_;
public:
    explicit TaskQueue(QObject* parent= nullptr);
    void addTask(QPointer<Task> task);
    void popTask();
    bool isEmpty();
    QPointer<Task> front();
};

#endif //VFTPCLIENT_TASK_H
