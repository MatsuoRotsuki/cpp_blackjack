#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>
#include <QDebug>
#include "mainwindow.h"
#include "socketmanager.h"
#include "message.h"

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = nullptr );
    ~PlayWindow();

private slots:
    void on_hit_btn_clicked();

    void on_stand_btn_clicked();

    void on_cashout_btn_clicked();

    void on_inviteBtn_clicked();

    void on_quitBtn_clicked();

    void back_to_home_screen();

    // read flag from server
    // void on_readFlag();

    // void update_game_state(Message msg);

private:
    Ui::PlayWindow *ui;
    bool isInvitePopupShown;
    bool isQuitPopupShown;
    // MainWindow *mainWindow;
};

#endif // PLAYWINDOW_H
