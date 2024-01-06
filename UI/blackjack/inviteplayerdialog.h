#ifndef INVITEPLAYERDIALOG_H
#define INVITEPLAYERDIALOG_H

#include <QDialog>

namespace Ui {
class InvitePlayerDialog;
}

class InvitePlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InvitePlayerDialog(QWidget *parent = nullptr);
    ~InvitePlayerDialog();

private:
    Ui::InvitePlayerDialog *ui;
};

#endif // INVITEPLAYERDIALOG_H
