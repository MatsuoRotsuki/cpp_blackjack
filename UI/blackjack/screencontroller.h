#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QObject>
#include <QStackedWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include "message.h"

class ScreenController : public QObject
{
    Q_OBJECT
public:
    // static ScreenController* getInstance();
    static ScreenController& instance();
    void setStackedWidget(QStackedWidget* stackedWidget_main);
    int getStackedWidgetIndex();
    QStackedWidget* getStackedWidget() const;
    QVBoxLayout* m_readyList;
    QHBoxLayout* allPlayers;
    QHBoxLayout* dealer;
    QLabel* dealerScore;
    QLabel* playerSscore;
    void UpdateReadyList(Message message);
    void UpdateRoomList(Message message);
    void UpdateGameState(Message message);
    void StartRound(Message message);
    void BetRequest(Message message);
    void PlayerBet(Message message);
    void ActionRequest(Message message);
    void CreateRoom(Message message);
    void UpdateDealer(Message message);

signals:
    // Thêm các signals dùng để điều hướng giữa các màn hình
    // void back_to_home_screen();

public slots:
    // Thêm các slots dùng để xử lý điều hướng giữa các màn hình
    // void signal_to_back_to_home_screen();
    void switchToScreen(int screenIndex);

private:
    explicit ScreenController(QObject *parent = nullptr);
    ~ScreenController();
    QStackedWidget* m_stackedWidget;
    Q_DISABLE_COPY(ScreenController)
    // static ScreenController* instance;
};

#endif // SCREENCONTROLLER_H
