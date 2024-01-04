#include "inviteplayerpopup.h"
#include "ui_inviteplayerpopup.h"

InvitePlayerPopup::InvitePlayerPopup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InvitePlayerPopup)
{
    ui->setupUi(this);
}

InvitePlayerPopup::~InvitePlayerPopup()
{
    delete ui;
}
