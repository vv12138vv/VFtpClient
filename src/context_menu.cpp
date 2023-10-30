//
// Created by jgss9 on 10/30/2023.
//

#include "context_menu.h"

ContextMenu::ContextMenu(QWidget *parent): QMenu(parent) {
    QPointer<QAction> openAction= addAction("open");
    QPointer<QAction> downloadAction= addAction("download");
    QPointer<QAction> deleteAction= addAction("delete");
    connect(openAction,&QAction::triggered,this,&ContextMenu::onOpenClicked);
    connect(downloadAction,&QAction::triggered,this,&ContextMenu::onDownloadClicked);
    connect(deleteAction,&QAction::triggered,this,&ContextMenu::onDeleteClicked);

}

void ContextMenu::onOpenClicked() {
    qDebug()<<"open clicked"<<'\n';
}

void ContextMenu::onDownloadClicked() {
    qDebug()<<"download clicked"<<'\n';

}

void ContextMenu::onDeleteClicked() {
    qDebug()<<"delete clicked"<<'\n';
}
