#include "roomitemwidget.h"
#include "ui_roomitemwidget.h"
#include "screencontroller.h"
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
    ScreenController::instance().switchToScreen(2);
}

