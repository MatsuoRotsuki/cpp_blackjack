#include "roomitemwidget.h"
#include "ui_roomitemwidget.h"

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
