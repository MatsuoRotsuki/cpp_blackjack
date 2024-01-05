#include "inviteplayerdialog.h"
#include "ui_inviteplayerdialog.h"

InvitePlayerDialog::InvitePlayerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InvitePlayerDialog)
{
    ui->setupUi(this);
}

InvitePlayerDialog::~InvitePlayerDialog()
{
    delete ui;
}
