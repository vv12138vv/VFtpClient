//
// Created by jgss9 on 10/25/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_client_ui.h" resolved

#include "client_ui.h"
#include "ui_client_ui.h"


ClientUi::ClientUi(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClientUi) {
    ui->setupUi(this);
    client_ = new Client(this);
    initSlots();
}

ClientUi::~ClientUi() {
    delete ui;
}

void ClientUi::initSlots() {
    connect(ui->connectBtn, &QPushButton::clicked, this, &ClientUi::onConnectBtnClicked);
    connect(ui->loginBtn, &QPushButton::clicked, this, &ClientUi::onLoginBtnClicked);
    connect(ui->portInputBar, &QLineEdit::editingFinished, this, &ClientUi::onPortBarEdited);
    connect(ui->hostInputBar, &QLineEdit::editingFinished, this, &ClientUi::onHostBarEdited);
    connect(ui->usernameInputBar, &QLineEdit::editingFinished, this, &ClientUi::onUsernameBarEdited);
    connect(ui->passwordInputBar, &QLineEdit::editingFinished, this, &ClientUi::onPasswordBarEdited);
    connect(client_->getLogger(), &Logger::newLog, this, &ClientUi::onNewLog);
    connect(client_, &Client::fileTableUpdate, this, &ClientUi::onFileTableUpdate);
    connect(client_, &Client::serverPathUpdate, this, &ClientUi::onServerPathUpdate);
    connect(ui->serverFileTable, &QTableWidget::cellClicked, this, &ClientUi::onServerFileTableCellClicked);
    connect(ui->serverFileTable, &QTableWidget::cellDoubleClicked, this, &ClientUi::onServerFileTableCell2Clicked);
    connect(ui->STORtestBtn, &QPushButton::clicked, this, &ClientUi::onSTORtestBtnClicked);
    //for test
    connect(ui->PWDtestBtn, &QPushButton::clicked, this, &ClientUi::onPWDtestBtnClicked);
    connect(ui->LISTtestBtn, &QPushButton::clicked, this, &ClientUi::onLISTtestBtnClicked);
    connect(ui->PASVtestBtn, &QPushButton::clicked, this, &ClientUi::onPASVtestBtnClicked);
    connect(ui->MKDtestBtn, &QPushButton::clicked, this, &ClientUi::onMKDtestBtnClicked);
    connect(ui->RMDtestBtn, &QPushButton::clicked, this, &ClientUi::onRMDtestBtnClicked);
    connect(ui->CWDTestBtn, &QPushButton::clicked, this, &ClientUi::onCWDtestBtnClicked);
    connect(ui->RETRtestBtn, &QPushButton::clicked, this, &ClientUi::onRETRtestBtnClicked);
}

void ClientUi::onConnectBtnClicked() {
//    if(targetHost_.isNull()||targetPort_==0||username_.isNull()||password_.isNull()){
//        return;
//    }
    QHostAddress host("124.223.65.182");
    quint32 port = 21;
    client_->connectTo(host, port);
}

void ClientUi::onPortBarEdited() {
//    qDebug()<<"port edited"<<"\n";
    QString text = ui->portInputBar->text();
    QRegularExpression regExp("^[0-9]+$");
    auto match = regExp.match(text);
    bool isNumber = match.hasMatch();
    if (!isNumber) {
        return;
    }
    quint32 port = text.toUInt();
//    qDebug()<<"port: "<<port<<"\n";
    this->targetPort_ = port;
}

void ClientUi::onHostBarEdited() {
//    qDebug()<<"host edit"<<"\n";
    QString text = ui->hostInputBar->text();
//    qDebug()<<"host:"<<text;
    this->targetHost_ = QHostAddress(text);
}

void ClientUi::onUsernameBarEdited() {
//    qDebug()<<"username edit"<<"\n";
    QString text = ui->usernameInputBar->text();
//    qDebug()<<"username:"<<text<<"\n";
    this->username_ = text;
}

void ClientUi::onPasswordBarEdited() {
//    qDebug()<<"password edit"<<"\n";
    QString text = ui->passwordInputBar->text();
//    qDebug()<<"password:"<<text<<"\n";
    this->password_ = text;
}

void ClientUi::onNewLog(const QString &logMsg) {
    ui->systemMsgBrowser->setText(ui->systemMsgBrowser->toPlainText() + logMsg + '\n');
    ui->systemMsgBrowser->textCursor().movePosition(QTextCursor::End);
}

void ClientUi::onLoginBtnClicked() {
    client_->USER(username_);
}

void ClientUi::onPWDtestBtnClicked() {
    client_->PWD();
}

void ClientUi::onLISTtestBtnClicked() {
    client_->LIST();
}

void ClientUi::onPASVtestBtnClicked() {
    client_->PASV();
}

void ClientUi::onFileTableUpdate(const QVector<FtpFileInfo> &fileInfoList) {
    ui->serverFileTable->setRowCount(fileInfoList.size() + 1);
    const quint32 col = 6;
    ui->serverFileTable->setColumnCount(col);
    QStringList headerLabels = {"Name", "Type", "Size", "Month", "Day", "Time", "Permissions"};
    ui->serverFileTable->setHorizontalHeaderLabels(headerLabels);
    ui->serverFileTable->setItem(0, 0, new QTableWidgetItem(".."));
    ui->serverFileTable->setItem(0, 1, new QTableWidgetItem("Folder"));
    //数据加载
    int row = 1;
    for (int i = 0; i < fileInfoList.size(); i++, row++) {
        const auto &fileInfo = fileInfoList.at(i);
        ui->serverFileTable->setItem(row, 0, new QTableWidgetItem(fileInfo.name));
        if (fileInfo.isDir) {
            ui->serverFileTable->setItem(row, 1, new QTableWidgetItem("Folder"));
        } else {
            ui->serverFileTable->setItem(row, 1, new QTableWidgetItem("File"));
        }
        if (fileInfo.isDir) {
            ui->serverFileTable->setItem(row, 2, new QTableWidgetItem(nullptr));
        } else {
            ui->serverFileTable->setItem(row, 2, new QTableWidgetItem(QString::number(fileInfo.size)));
        }
        ui->serverFileTable->setItem(row, 3, new QTableWidgetItem(fileInfo.month));
        ui->serverFileTable->setItem(row, 4, new QTableWidgetItem(fileInfo.day));
        ui->serverFileTable->setItem(row, 5, new QTableWidgetItem(fileInfo.time));
        ui->serverFileTable->setItem(row, 6, new QTableWidgetItem(fileInfo.permissions));
    }
    //一些显示设置
    ui->serverFileTable->resizeColumnsToContents();
    ui->serverFileTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->serverFileTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->serverFileTable->horizontalHeader()->setStretchLastSection(true);
    ui->serverFileTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void ClientUi::onServerPathUpdate(const QString &path) {
    QString outputPath = path;
    if (outputPath.startsWith('\"') && outputPath.endsWith('\"')) {
        outputPath = outputPath.remove(0, 1);
        outputPath = outputPath.remove(outputPath.length() - 1, 1);
    }
    ui->serverPathBar->setText(outputPath);
}

void ClientUi::onMKDtestBtnClicked() {
    client_->MKD("wdnmd");
}

void ClientUi::onRMDtestBtnClicked() {
    client_->RMD("wdnmd");
}

void ClientUi::onCWDtestBtnClicked() {
    client_->CWD("wdnmd");
}

void ClientUi::onRETRtestBtnClicked() {
    client_->RETR("wdnmd");
}

void ClientUi::onServerFileTableCellClicked(int row, int column) {
    auto item = ui->serverFileTable->item(row, column);
//    qDebug() << "item text: " << item->text() << "\n";
}

void ClientUi::onServerFileTableCell2Clicked(int row, int column) {
    auto item = ui->serverFileTable->item(row, column);
    if (column != 0) {
        return;
    }
    auto typeItem = ui->serverFileTable->item(row, column + 1);
    if (typeItem->text() != "Folder") {
        return;
    }
    nextPath_ = ui->serverPathBar->text() + '/' + item->text();
    qDebug() << "nextPath:" << nextPath_ << '\n';
    client_->CWD(nextPath_);
}

void ClientUi::onSTORtestBtnClicked() {
    client_->STOR("wdnmd");
}





