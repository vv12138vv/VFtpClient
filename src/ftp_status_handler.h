//
// Created by jgss9 on 10/25/2023.
//

#ifndef VFTPCLIENT_FTP_STATUS_HANDLER_H
#define VFTPCLIENT_FTP_STATUS_HANDLER_H

#include<QObject>
#include<QHash>
#include"common.h"

class FtpStatusHandler {
private:
        QHash<quint16,std::function<void()>> handler;
        FtpStatusHandler();
public:
        FtpStatusHandler& getInstance();
        FtpStatusHandler& operator=(const FtpStatusHandler&)=delete;
        FtpStatusHandler(const FtpStatusHandler&)=delete;
};


#endif //VFTPCLIENT_FTP_STATUS_HANDLER_H
