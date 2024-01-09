#include "player.h"
#include "ui_player.h"
#include "card.h"
player::player(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::player)
{
    ui->setupUi(this);
}

player::~player()
{
    delete ui;
}

// get username
QString player::getUsername() const
{
    return ui->username->text();
}

void player::setUsername(const QString &username)
{
    ui->username->setText(username);
}

void player::setCurrentMoney(const QString &currentMoney){
    ui->money->setText(currentMoney);
}

void player::setStatus(const QString &status){
    ui->status->setText(status);
}

void player::setCard(const Card *card){
    // do something
}
