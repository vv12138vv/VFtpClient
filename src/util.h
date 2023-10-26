//
// Created by jgss9 on 10/26/2023.
//

#ifndef VFTPCLIENT_UTIL_H
#define VFTPCLIENT_UTIL_H
#include<QObject>
#include<QRegularExpression>
#include <QRegularExpressionMatch>
#include"common.h"

class Util {
public:
    static QPair<QString,quint32> parsePasvResp(const QString& resp);
    static QVector<FtpFileInfo> parseFtpList(const QString& ftpList);
    static QString parsePath(const QString& path);
};


#endif //VFTPCLIENT_UTIL_H
