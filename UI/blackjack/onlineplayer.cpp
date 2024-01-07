#include "onlineplayer.h"
#include "ui_onlineplayer.h"
#include "screencontroller.h"
OnlinePlayer::OnlinePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnlinePlayer)
{
    ui->setupUi(this);

    int index = ScreenController::instance().getStackedWidgetIndex();

    if (index == 1) {
        ui->invitePlayBtn->setVisible(true);
    } else {
        ui->invitePlayBtn->setVisible(false);
    }
}

OnlinePlayer::~OnlinePlayer()
{
    delete ui;
}

