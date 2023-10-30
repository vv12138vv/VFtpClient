//
// Created by jgss9 on 10/30/2023.
//

#ifndef VFTPCLIENT_CONTEXT_MENU_H
#define VFTPCLIENT_CONTEXT_MENU_H
#include<QtWidgets>
#include<QPointer>

class ContextMenu: public QMenu{
public:
    explicit ContextMenu(QWidget* parent= nullptr);

private:

public slots:
    void onOpenClicked();
    void onDownloadClicked();
    void onDeleteClicked();
};


#endif //VFTPCLIENT_CONTEXT_MENU_H
