#include "onlineplayer.h"
#include "ui_onlineplayer.h"
#include "screencontroller.h"
OnlinePlayer::OnlinePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnlinePlayer)
{
    ui->setupUi(this);

    int index = ScreenController::instance().getStackedWidgetIndex();
}

OnlinePlayer::~OnlinePlayer()
{
    delete ui;
}

void OnlinePlayer::setUsername(QString username)
{
    ui->username->setText(username);
}

void OnlinePlayer::setStatusLabel(QString status)
{
    ui->statusLabel->setText(status);
}
