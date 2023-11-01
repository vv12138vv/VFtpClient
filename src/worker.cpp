//
// Created by jgss9 on 11/1/2023.
//

#include "worker.h"

Worker::Worker(QPointer<TaskQueue> taskQueue, QObject *parent):taskQueue_(taskQueue), QObject(parent) {

}

void Worker::startWorking() {
    while(true){
        if(taskQueue_->isEmpty()){
            continue;
        }
        auto task=taskQueue_->front();
        if(task.isNull()){
            continue;
        }
        switch (task->type) {
            case TaskType::Download:{
                break;
            }
            case TaskType::Upload:{
                break;
            }
            case TaskType::List:{
                break;
            }
        }
        emit taskFinished(*task);
    }
}
