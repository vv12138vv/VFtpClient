//
// Created by jgss9 on 10/16/2023.
//

#include "logger.h"
//Todo logger的格式化，map尚未构造。

Logger::Logger(QObject *parent) : QObject(parent) {
}

void Logger::log(const QString &logMsg) {
    QDateTime nowTime=QDateTime::currentDateTime();
    QString outputLogMsg = "[" + nowTime.toString() + "] :" + logMsg;
    emit newLog(outputLogMsg);
}

void Logger::log(Logger::LogType logType,const QString& logMsg) {
    QDateTime nowTime=QDateTime::currentDateTime();
    QString outputLogMsg="["+nowTime.toString()+"]: ";
    switch (logType) {
        case (LogType::StartListen):
            outputLogMsg+=logMsg;
            break;
        case (LogType::EndListen):
            outputLogMsg+=logMsg;
            break;
        case(LogType::NewConnection):
            outputLogMsg+=logMsg;
            break;
        case (LogType::EndConnection):
            outputLogMsg+= logMsg;
            break;
        default:
            break;
    }
    emit newLog(outputLogMsg);
}


Logger::~Logger() = default;




