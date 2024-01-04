#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = nullptr);
    ~PlayWindow();

private slots:
    void on_hit_btn_clicked();

    void on_stand_btn_clicked();

    void on_cashout_btn_clicked();

    void on_quit_game_btn_clicked();

    void on_invite_player_btn_clicked();

private:
    Ui::PlayWindow *ui;
    bool isInvitePopupShown;
};

#endif // PLAYWINDOW_H
