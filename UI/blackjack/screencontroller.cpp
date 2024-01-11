#include "screencontroller.h"
#include "onlineplayer.h"
#include "player.h"
ScreenController::ScreenController(QObject *parent) 
    : QObject(parent)
    , m_stackedWidget(nullptr)
{
    // KHởi tạo các giá trị mặc định và xử lý khởi động ứng dụng
}

ScreenController::~ScreenController()
{
    qDebug() << "Screen Controller destroyed";
}

ScreenController& ScreenController::instance()
{
    static ScreenController instance;
    return instance;
}

void ScreenController::setStackedWidget(QStackedWidget* stackedWidget)
{
    m_stackedWidget = stackedWidget;
}

void ScreenController::switchToScreen(int screenIndex)
{
    if (m_stackedWidget)
    {
        m_stackedWidget->setCurrentIndex(screenIndex);
    }
}

QStackedWidget* ScreenController::getStackedWidget() const
{
    return m_stackedWidget;
}

void ScreenController::UpdateReadyList(Message message)
{
    // delete all current ready clients
    if (m_readyList) {
        while(QLayoutItem *item = m_readyList->takeAt(0)) {
            QWidget *widget = item->widget();
            if (widget) {
                m_readyList->removeWidget(widget);
                delete widget;
            }
            delete item;
        }
    }

    int num_of_players = message.payload.readyListResponseData.num_of_players;
    for (int i = 0; i < num_of_players; i++) {
        PlayerData player = message.payload.readyListResponseData.players[i];
        qDebug() << player.id ;
        qDebug() << player.money;
        qDebug() << player.wins;
        qDebug() << player.loses;
        qDebug() << player.pushes;
        OnlinePlayer *readyPlayer = new OnlinePlayer();
        readyPlayer->setUsername(QString::fromStdString(std::string(player.name)));
        m_readyList->addWidget(readyPlayer);
    }
}

void ScreenController::UpdateRoomList(Message message)
{
}

void ScreenController::UpdateGameState(Message message)
{
}

void ScreenController::StartRound(Message message)
{
}

void ScreenController::BetRequest(Message message)
{
}

void ScreenController::PlayerBet(Message message)
{
}

void ScreenController::ActionRequest(Message message)
{
}

int ScreenController::getStackedWidgetIndex()
{
    if (m_stackedWidget){
        return m_stackedWidget->currentIndex();
    }else{
        return 0;
    }

}

//create new room
void ScreenController::CreateRoom(Message message){
    if (allPlayers) {
        while(QLayoutItem *item = allPlayers->takeAt(0)) {
            QWidget *widget = item->widget();
            if (widget) {
                allPlayers->removeWidget(widget);
                delete widget;
            }
            delete item;
        }

        int num_of_players = message.payload.gameStateData.num_of_players;
        for(int i = 0; i< num_of_players;i++){
            player *item = new player();
            // PlayerData playerData = message.payload.gameStateData.players[i];
            // player *currentPlayer = dynamic_cast<player*>(item);
            item->setUsername(QString::fromStdString(std::string(message.payload.gameStateData.players[i].username)));
            item->setCurrentMoney(QString::number(message.payload.gameStateData.players[i].money));

            // neu den luot cua minh ( current = 1) thi hien thi betting
            // item->setStatus(message.payload.gameStateData.players[i].current);
            item->setScore(message.payload.gameStateData.players[i].score);
            item->setBetting(message.payload.gameStateData.players[i].bet);
            item->setCards(message.payload.gameStateData.players[i].cards, message.payload.gameStateData.players[i].num_of_cards);
            allPlayers->addWidget(item);
        }
    }


}

        //     // if(msg.payload.gameStateData.start_round == 1){
        //     //     ui->Notification->setVisible(true);
        //     // }else{
        //     //     ui->Notification->setVisible(false);
        //     // }
        //     ui->dealerScore->setText(QString::number(msg.payload.gameStateData.dealer_score));


