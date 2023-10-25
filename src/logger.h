//
// Created by jgss9 on 10/16/2023.
//

#ifndef VCHATSERVER_LOGGER_H
#define VCHATSERVER_LOGGER_H


#include<QObject>
#include<QPointer>
#include<QDateTime>


class Logger : public QObject {
Q_OBJECT
public:
    enum LogType {
        StartListen,
        EndListen,
        NewConnection,
        EndConnection,
    };
private:

public:
    static const QMap<LogType,QString> logPrefix;
    explicit Logger(QObject *parent = nullptr);
    ~Logger() override;

    void log(const QString &logMsg);
    void log(LogType logType,const QString& logMsg);

signals:
    void newLog(const QString &newMsg);


};

#endif //VCHATSERVER_LOGGER_H
