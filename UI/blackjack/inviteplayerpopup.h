#ifndef INVITEPLAYERPOPUP_H
#define INVITEPLAYERPOPUP_H

#include <QWidget>

namespace Ui {
class InvitePlayerPopup;
}

class InvitePlayerPopup : public QWidget
{
    Q_OBJECT

public:
    explicit InvitePlayerPopup(QWidget *parent = nullptr);
    ~InvitePlayerPopup();

private:
    Ui::InvitePlayerPopup *ui;
};

#endif // INVITEPLAYERPOPUP_H
