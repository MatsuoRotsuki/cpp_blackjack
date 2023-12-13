#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include <QPushButton>
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

    void on_playAloneBtn_clicked();

    void on_playGroupBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
