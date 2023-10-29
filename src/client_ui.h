//
// Created by jgss9 on 10/25/2023.
//

#ifndef VFTPCLIENT_CLIENT_UI_H
#define VFTPCLIENT_CLIENT_UI_H

#include <QWidget>
#include<QPointer>
#include<QRegularExpression>
#include<QDebug>
#include<QDir>

#include "client.h"
#include<QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class ClientUi; }
QT_END_NAMESPACE

class ClientUi : public QWidget {
Q_OBJECT

private:
    Ui::ClientUi *ui;
    QPointer<Client> client_;
    QHostAddress targetHost_;
    quint16 targetPort_;
    QString username_;
    QString password_;
    QString serverNextPath_;
    QPair<int,int> selectedClientItem_;
    QPair<int,int> selectedServerItem_;
    QString mkDirInput_;
    QString rmDirInput_;
public:
    explicit ClientUi(QWidget *parent = nullptr);

    void initSlots();

    ~ClientUi() override;

signals:

    void clientTableUpdate(const QString& path);

public slots:

    void onConnectBtnClicked();

    void onLoginBtnClicked();

    void onPortBarEdited();

    void onHostBarEdited();

    void onUsernameBarEdited();

    void onPasswordBarEdited();

    void onNewLog(const QString &logMsg);

    void onServerFileTableUpdate(const QVector<FtpFileInfo> &);

    void onServerPathUpdate(const QString &);

    void onServerFileTableCellClicked(int row, int column);

    void onServerFileTableCell2Clicked(int row, int column);

    void onClientFileTableUpdate(const QString& path);

    void onClientPathUpdate(const QString &);

    void onClientFileTableCellClicked(int row,int column);

    void onClientFileTableCell2Clicked(int row,int column);

    void onUploadBtnClicked();
    void onDownloadBtnClicked();

    void onMkDirBarEdited();
    void onRmDirBarEdited();
    void onMkDirBtnClicked();
    void onRmDirBtnClicked();


    void onPWDtestBtnClicked();

    void onLISTtestBtnClicked();

    void onPASVtestBtnClicked();

//    void onMKDtestBtnClicked();
//
//    void onRMDtestBtnClicked();

    void onCWDtestBtnClicked();

    void onRETRtestBtnClicked();

    void onSTORtestBtnClicked();
};


#endif //VFTPCLIENT_CLIENT_UI_H
