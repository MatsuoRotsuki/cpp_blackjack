#include "logoutdialog.h"
#include "ui_logoutdialog.h"

LogoutDialog::LogoutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogoutDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);

}

LogoutDialog::~LogoutDialog()
{
    delete ui;
}
