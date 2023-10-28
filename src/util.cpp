//
// Created by jgss9 on 10/26/2023.
//

#include "util.h"
QPair <QString, quint32> Util::parsePasvResp(const QString &resp) {
    QRegularExpression regex(R"(\((\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\))");
    QRegularExpressionMatch match = regex.match(resp);
    if (!match.hasMatch()) {
        return qMakePair(QString(), 0);
    }
    QString host = match.captured(1) + '.' + match.captured(2) + '.' + match.captured(3) + '.' + match.captured(4);
    quint32 port = match.captured(5).toUInt() * 256 + match.captured(6).toUInt();
    return qMakePair(host, port);
}


QVector<FtpFileInfo> Util::parseFtpList(const QString &ftpList) {
    QVector<FtpFileInfo> fileList;
    QStringList lines=ftpList.split("\r\n",Qt::SkipEmptyParts);
    QRegularExpression regex(R"(([d-])([r-][w-][x-][r-][w-][x-][r-][w-][x-])\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+([A-Za-z][A-Za-z][A-Za-z])\s+(\d+)\s+(\d+:\d+|\d\d\d\d)\s+(.*))");
    for(const QString& line:lines){
        qDebug()<<"line"<<line<<"\n";
        QRegularExpressionMatch match = regex.match(line);
        if(match.hasMatch()){
            FtpFileInfo fileInfo;
            fileInfo.isDir= match.captured(1) == 'd';
            fileInfo.permissions=match.captured(2);
            fileInfo.owner=match.captured(4);
            fileInfo.group=match.captured(5);
            fileInfo.size=match.captured(6).toInt();
            fileInfo.month=match.captured(7);
            fileInfo.day=match.captured(8);
            fileInfo.time=match.captured(9);
            fileInfo.name=match.captured(10);
            fileList.append(qMove(fileInfo));
        }
    }
    return fileList;
}

QString Util::parsePath(const QString &msg) {
    QRegularExpression regex("\"([^\"]*)\"");
    QRegularExpressionMatch match=regex.match(msg);
    if(match.hasMatch()){

        return match.captured(0);
    }
    return "";
}

QPair<QString, quint64> Util::parseDownloadInfo(const QString &info) {
    qDebug()<<"info"<<info<<"\n";
    QPair<QString,quint64> res{"",1};
    QRegularExpression regex1(R"(for\s+(\/\S+))");
    QRegularExpressionMatch match1=regex1.match(info);
    if(match1.hasMatch()){
        QString filePath=match1.captured(0);
        filePath.remove(0,3);
        filePath=filePath.trimmed();
        res.first=filePath;
    }
    QRegularExpression regex2(R"(\((\d+)\s+bytes\))");
    QRegularExpressionMatch match2=regex2.match(info);
    if(match2.hasMatch()){
        QString sizeStr=match2.captured(1);
        quint64 size=sizeStr.toUInt();
        res.second=size;
    }
    return res;
}

QString Util::parseFileName(const QString &filePath) {
    QFileInfo fileInfo(filePath);
    return fileInfo.fileName();
}

