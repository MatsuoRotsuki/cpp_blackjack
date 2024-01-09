#include "inviteplayerdialog.h"
#include "ui_inviteplayerdialog.h"
#include "onlineplayer.h"
#include "screencontroller.h"

InvitePlayerDialog::InvitePlayerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InvitePlayerDialog)
{
    ui->setupUi(this);

    ScreenController::instance().m_readyList = ui->readyList;
}

InvitePlayerDialog::~InvitePlayerDialog()
{
    delete ui;
}
