#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include <QPushButton>
#include <QTcpSocket>
#include <QByteArray>
#include "message.h"
#include "socketmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_homeBtn_clicked();

    void on_roomBtn_clicked();

    void on_inviteBtn_clicked();

    void setTappedButton(QPushButton *tappedButton, QPushButton *button1, QPushButton *button2);

    void setTappedMode(QPushButton *mode1, QPushButton *mode2);

    // void on_playGame_clicked();

    // void on_cancelBtn_clicked();

    /**
     * Slot for Login button
    */
    void on_login_btn_clicked();

    void on_to_login_page_btn_clicked();

    void on_to_signup_page_btn_clicked();

    void on_readyRead();

    void on_signup_btn_clicked();

    void on_joinRandomBtn_clicked();

    void on_createNewRoomBtn_clicked();

    void on_joinBtn_clicked();

    void on_createRoomBtn_clicked();

public slots:

private:
    Ui::MainWindow *ui;
    SocketManager *socketManager;
};
#endif // MAINWINDOW_H
