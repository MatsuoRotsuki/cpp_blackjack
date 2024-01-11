#include "roomitemwidget.h"
#include "ui_roomitemwidget.h"
#include "screencontroller.h"
#include "socketmanager.h"

RoomItemWidget::RoomItemWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::RoomItemWidget)
{
    ui->setupUi(this);
}

RoomItemWidget::~RoomItemWidget()
{
    delete ui;
}

void RoomItemWidget::on_joinRoombtn_clicked()
{
    Message msg;
    msg.type = MessageType::CLT_CREATE_ROOM_REQ;
    QByteArray byteArray;
    byteArray.append(reinterpret_cast<const char*>(&msg), sizeof(Message));
    SocketManager::instance().socket()->write(byteArray);
    ScreenController::instance().switchToScreen(2);
}

