//
// Created by jgss9 on 10/25/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_client_ui.h" resolved

#include "client_ui.h"
#include "ui_client_ui.h"


ClientUi::ClientUi(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::ClientUi) {
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
    connect(client_, &Client::fileTableUpdate, this, &ClientUi::onServerFileTableUpdate);
    connect(client_, &Client::serverPathUpdate, this, &ClientUi::onServerPathUpdate);
    connect(ui->serverFileTable, &QTableWidget::cellClicked, this, &ClientUi::onServerFileTableCellClicked);
    connect(ui->serverFileTable, &QTableWidget::cellDoubleClicked, this, &ClientUi::onServerFileTableCell2Clicked);
    connect(client_, &Client::clientPathUpdate, this, &ClientUi::onClientPathUpdate);
    connect(this, &ClientUi::clientTableUpdate, this, &ClientUi::onClientFileTableUpdate);
    connect(ui->clientFileTable, &QTableWidget::cellClicked, this, &ClientUi::onClientFileTableCellClicked);
    connect(ui->clientFileTable, &QTableWidget::cellDoubleClicked, this, &ClientUi::onClientFileTableCell2Clicked);
    connect(ui->uploadBtn, &QPushButton::clicked, this, &ClientUi::onUploadBtnClicked);
    connect(ui->downloadBtn, &QPushButton::clicked, this, &ClientUi::onDownloadBtnClicked);
    connect(ui->mkdirInputBar, &QLineEdit::editingFinished, this, &ClientUi::onMkDirBarEdited);
    connect(ui->mkdirBtn, &QPushButton::clicked, this, &ClientUi::onMkDirBtnClicked);
    connect(ui->serverFileTable, &QTableWidget::customContextMenuRequested, this, &ClientUi::onShowServerContextMenu);
    connect(ui->clientFileTable, &QTableWidget::customContextMenuRequested, this, &ClientUi::onShowClientContextMenu);
    connect(client_,&Client::controlSocketConnected,this,&ClientUi::onControlSocketConnected);
    connect(client_,&Client::controlSocketDisconnected,this,&ClientUi::onControlSocketDisconnected);
    //for test
//    connect(ui->PWDtestBtn, &QPushButton::clicked, this, &ClientUi::onPWDtestBtnClicked);
//    connect(ui->LISTtestBtn, &QPushButton::clicked, this, &ClientUi::onLISTtestBtnClicked);
//    connect(ui->PASVtestBtn, &QPushButton::clicked, this, &ClientUi::onPASVtestBtnClicked);
//    connect(ui->DELEtestBtn, &QPushButton::clicked, this, &ClientUi::onDeleteBtnClicked);
}

void ClientUi::onConnectBtnClicked() {
//    if(targetHost_.isNull()||targetPort_==0||username_.isNull()||password_.isNull()){
//        return;
//    }
//    QHostAddress host("124.223.65.182");
//    quint32 port = 21;
    client_->connectTo(targetHost_, targetPort_);
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
    client_->PASS(password_);
}

//void ClientUi::onPWDtestBtnClicked() {
//    client_->PWD();
//}
//
//void ClientUi::onLISTtestBtnClicked() {
//    client_->LIST();
//}
//
//void ClientUi::onPASVtestBtnClicked() {
//    client_->PASV();
//}

void ClientUi::onServerFileTableUpdate(const QVector<FtpFileInfo> &fileInfoList) {
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
    ui->serverFileTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

void ClientUi::onServerPathUpdate(const QString &path) {
    QString outputPath = path;
    if (outputPath.startsWith('\"') && outputPath.endsWith('\"')) {
        outputPath = outputPath.remove(0, 1);
        outputPath = outputPath.remove(outputPath.length() - 1, 1);
    }
    ui->serverPathBar->setText(outputPath);
}

void ClientUi::onServerFileTableCellClicked(int row, int column) {
    selectedServerItem_.first = row;
    selectedServerItem_.second = column;
    qDebug() << selectedServerItem_ << '\n';
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
    serverNextPath_ = ui->serverPathBar->text() + '/' + item->text();
    qDebug() << "nextPath:" << serverNextPath_ << '\n';
    client_->CWD(serverNextPath_);
    client_->LIST();
}


void ClientUi::onClientPathUpdate(const QString &path) {
    ui->clientPathBar->setText(path);
    client_->curClientPath_ = path;
    emit clientTableUpdate(path);
}


void ClientUi::onClientFileTableUpdate(const QString &path) {
    QDir directory(path);
    if (!directory.exists()) {
        return;
    }
    QStringList folders = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QStringList files = directory.entryList(QDir::Files);
    ui->clientFileTable->setRowCount(folders.size() + files.size() + 1);
    const quint32 col = 4;
    ui->clientFileTable->setColumnCount(col);
    QStringList headerLabels = {"Name", "Type", "Size", "Time"};
    ui->clientFileTable->setHorizontalHeaderLabels(headerLabels);
    ui->clientFileTable->setItem(0, 0, new QTableWidgetItem(".."));
    ui->clientFileTable->setItem(0, 1, new QTableWidgetItem("Folder"));
    int row = 1;
    for (int i = 0; i < folders.size(); i++, row++) {
        QString dirPath = directory.absoluteFilePath(folders.at(i));
        QFileInfo folderInfo(dirPath);
        ui->clientFileTable->setItem(row, 0, new QTableWidgetItem(folderInfo.fileName()));
        ui->clientFileTable->setItem(row, 1, new QTableWidgetItem("Folder"));
        ui->clientFileTable->setItem(row, 2, new QTableWidgetItem(nullptr));
        ui->clientFileTable->setItem(row, 3,
                                     new QTableWidgetItem(folderInfo.fileTime(QFile::FileModificationTime).toString()));
    }

    for (int i = 0; i < files.size(); i++, row++) {
        QString filePath = directory.absoluteFilePath(files.at(i));
        QFileInfo fileInfo(filePath);
        ui->clientFileTable->setItem(row, 0, new QTableWidgetItem(fileInfo.fileName()));
        ui->clientFileTable->setItem(row, 1, new QTableWidgetItem("File"));
        ui->clientFileTable->setItem(row, 2, new QTableWidgetItem(QString::number(fileInfo.size())));
        ui->clientFileTable->setItem(row, 3,
                                     new QTableWidgetItem(fileInfo.fileTime(QFile::FileModificationTime).toString()));
    }

    ui->clientFileTable->resizeColumnsToContents();
    ui->clientFileTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->clientFileTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->clientFileTable->horizontalHeader()->setStretchLastSection(true);
    ui->clientFileTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

void ClientUi::onClientFileTableCellClicked(int row, int column) {
    selectedClientItem_.first = row;
    selectedClientItem_.second = column;
    qDebug() << selectedClientItem_ << '\n';
}

void ClientUi::onClientFileTableCell2Clicked(int row, int column) {
    auto item = ui->clientFileTable->item(row, column);
    if (column != 0) {
        return;
    }
    auto typeItem = ui->clientFileTable->item(row, column + 1);
    if (typeItem->text() != "Folder") {
        return;
    }
    QFileInfo folderInfo(client_->curClientPath_);
    QString simplifiedPath = folderInfo.canonicalFilePath();
    QString nextPath = simplifiedPath + '/' + item->text();
    QFileInfo folderInfo2(nextPath);
    nextPath = folderInfo2.canonicalFilePath();
    emit onClientPathUpdate(nextPath);
}

void ClientUi::onUploadBtnClicked() {
    auto item = ui->clientFileTable->item(selectedClientItem_.first, 0);
    if (ui->clientFileTable->item(selectedClientItem_.first, 0 + 1)->text() == "Folder") {
        return;
    }
    QString filePath = client_->curClientPath_ + '/' + item->text();
    client_->STOR(filePath);
}

void ClientUi::onDownloadBtnClicked() {
    auto item = ui->serverFileTable->item(selectedServerItem_.first, 0);
    if (ui->serverFileTable->item(selectedServerItem_.first, 0 + 1)->text() == "Folder") {
        return;
    }
    QString filePath = client_->curServerPath_ + '/' + item->text();
//    qDebug()<<client_->curServerPath_<<'\n';
//    qDebug()<<filePath<<'\n';
    client_->RETR(filePath);
}

void ClientUi::onMkDirBarEdited() {
    mkDirInput_ = ui->mkdirInputBar->text();
}

//void ClientUi::onRmDirBarEdited() {
//    rmDirInput_ = ui->rmdirInputBar->text();
//}

void ClientUi::onMkDirBtnClicked() {
    QString folderPath = client_->curServerPath_ + '/' + mkDirInput_;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "确认执行该操作吗？", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        client_->MKD(folderPath);
        ui->mkdirInputBar->clear();
    }
}

void ClientUi::onRmDirBtnClicked() {
    QString folderPath = client_->curServerPath_ + '/' + rmDirInput_;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "确认执行该操作吗？", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        client_->RMD(folderPath);
//        ui->rmdirInputBar->clear();
    }
}

void ClientUi::onDeleteBtnClicked() {
    auto item = ui->serverFileTable->item(selectedServerItem_.first, 0);
    if (ui->serverFileTable->item(selectedServerItem_.first, 0 + 1)->text() == "Folder") {
        return;
    }
    QString filePath = client_->curServerPath_ + '/' + item->text();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "确认执行该操作吗？", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        client_->DELE(filePath);
    }
}

void ClientUi::onShowServerContextMenu(const QPoint &pos) {
    int row = ui->serverFileTable->rowAt(pos.y());
    if (row == -1) {
        return;
    }

    selectedServerItem_ = {row, 0};
    QMenu menu(this);
    auto item=ui->serverFileTable->item(row,1);
    if(item->text()=="Folder"){
        QPointer<QAction> openAction = menu.addAction("open");
        QPointer<QAction> rmDirAction=menu.addAction("delete");
        QAction *selectedAction = menu.exec(ui->serverFileTable->viewport()->mapToGlobal(pos));
        if (selectedAction == openAction) {
            qDebug() << "open" << "\n";
            onServerFileTableCell2Clicked(row, 0);
        }else if(selectedAction==rmDirAction){
            qDebug()<<"rmdir"<<'\n';
            auto item1 =ui->serverFileTable->item(row,0);
            rmDirInput_=item1->text();
            onRmDirBtnClicked();
        }
    }else if(item->text()=="File"){
        QPointer<QAction> downloadAction=menu.addAction("download");
        QPointer<QAction> deleteAction=menu.addAction("delete");
        QAction *selectedAction = menu.exec(ui->serverFileTable->viewport()->mapToGlobal(pos));
        if (selectedAction == downloadAction) {
            qDebug() << "download" << "\n";
            onDownloadBtnClicked();
        }else if(selectedAction==deleteAction){
            qDebug()<<"delete file"<<'\n';
            onDeleteBtnClicked();
        }
    }


}

void ClientUi::onShowClientContextMenu(const QPoint &pos) {
}

void ClientUi::onControlSocketConnected() {
    QString connectionStatus("Connected");
    ui->connectionStatus->setText(connectionStatus);
    ui->connectionStatus->setStyleSheet("color: green;");
}

void ClientUi::onControlSocketDisconnected() {
    QString connectionStatus("Disconnected");
    ui->connectionStatus->setText(connectionStatus);
    ui->connectionStatus->setStyleSheet("color: red;");
}



