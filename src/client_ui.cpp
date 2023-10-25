//
// Created by jgss9 on 10/25/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_client_ui.h" resolved

#include "client_ui.h"
#include "ui_client_ui.h"


ClientUi::ClientUi(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClientUi) {
    ui->setupUi(this);
    client_=new Client(this);
    initSlots();
}

ClientUi::~ClientUi() {
    delete ui;
}

void ClientUi::initSlots() {
    connect(ui->connectBtn,&QPushButton::clicked,this,&ClientUi::onConnectBtnClicked);
    connect(ui->loginBtn,&QPushButton::clicked,this,&ClientUi::onLoginBtnClicked);
    connect(ui->portInputBar,&QLineEdit::editingFinished,this,&ClientUi::onPortBarEdited);
    connect(ui->hostInputBar,&QLineEdit::editingFinished,this,&ClientUi::onHostBarEdited);
    connect(ui->usernameInputBar,&QLineEdit::editingFinished,this,&ClientUi::onUsernameBarEdited);
    connect(ui->passwordInputBar,&QLineEdit::editingFinished,this,&ClientUi::onPasswordBarEdited);
    connect(client_->getLogger(),&Logger::newLog,this,&ClientUi::onNewLog);
    //for test
    connect(ui->PWDtestBtn,&QPushButton::clicked,this, &ClientUi::onPWDtestBtnClicked);
    connect(ui->LISTtestBtn,&QPushButton::clicked,this,&ClientUi::onLISTtestBtnClicked);
    connect(ui->PASVtestBtn,&QPushButton::clicked,this,&ClientUi::onPASVtestBtnClicked);
}

void ClientUi::onConnectBtnClicked() {
//    if(targetHost_.isNull()||targetPort_==0||username_.isNull()||password_.isNull()){
//        return;
//    }
    client_->connectTo(host,port);
}

void ClientUi::onPortBarEdited() {
//    qDebug()<<"port edited"<<"\n";
    QString text=ui->portInputBar->text();
    QRegularExpression regExp("^[0-9]+$");
    auto match=regExp.match(text);
    bool isNumber=match.hasMatch();
    if(!isNumber){
        return;
    }
    quint32 port=text.toUInt();
//    qDebug()<<"port: "<<port<<"\n";
    this->targetPort_=port;
}

void ClientUi::onHostBarEdited() {
//    qDebug()<<"host edit"<<"\n";
    QString text=ui->hostInputBar->text();
//    qDebug()<<"host:"<<text;
    this->targetHost_=QHostAddress(text);
}

void ClientUi::onUsernameBarEdited() {
//    qDebug()<<"username edit"<<"\n";
    QString text=ui->usernameInputBar->text();
//    qDebug()<<"username:"<<text<<"\n";
    this->username_=text;
}

void ClientUi::onPasswordBarEdited() {
//    qDebug()<<"password edit"<<"\n";
    QString text=ui->passwordInputBar->text();
//    qDebug()<<"password:"<<text<<"\n";
    this->password_=text;
}

void ClientUi::onNewLog(const QString &logMsg) {
    ui->systemMsgBrowser->setText(ui->systemMsgBrowser->toPlainText()+logMsg+'\n');
    ui->systemMsgBrowser->textCursor().movePosition(QTextCursor::End);
}

void ClientUi::onLoginBtnClicked() {
    client_->login(username_,password_);
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



