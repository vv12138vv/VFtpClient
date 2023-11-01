//
// Created by jgss9 on 11/1/2023.
//

#include "task.h"

TaskQueue::TaskQueue(QObject *parent) : QObject(parent) {

}

void TaskQueue::addTask(QPointer<Task> task) {
    QMutexLocker locker(&mutex_);
    taskQueue_.enqueue(task);
}

void TaskQueue::popTask() {
    QMutexLocker locker(&mutex_);
    auto top = taskQueue_.first();
    delete top;
    taskQueue_.pop_front();
}

bool TaskQueue::isEmpty() {
    QMutexLocker locker(&mutex_);
    return taskQueue_.isEmpty();
}

QPointer<Task> TaskQueue::front() {
    QMutexLocker locker(&mutex_);
    if (!taskQueue_.isEmpty()) {
        return taskQueue_.first();
    }
    return nullptr;
}

Task::Task(const Task &that) : id(that.id), type(that.type), size(that.size), fileName(that.fileName),
                               localPath(that.localPath), remotePath(that.remotePath) {

}
