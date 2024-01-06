#include "onlineplayer.h"
#include "ui_onlineplayer.h"

OnlinePlayer::OnlinePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnlinePlayer)
{
    ui->setupUi(this);
}

OnlinePlayer::~OnlinePlayer()
{
    delete ui;
}
