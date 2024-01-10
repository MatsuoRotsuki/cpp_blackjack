#include "player.h"
#include "ui_player.h"
#include "message.h"
#include "carditem.h"
player::player(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::player)
{
    ui->setupUi(this);
}

player::~player()
{
    delete ui;
}

// get username
QString player::getUsername() const
{
    return ui->username->text();
}

void player::setUsername(const QString &username)
{
    ui->username->setText(username);
}


void player::setCurrentMoney(const QString &currentMoney){
    ui->money->setText(currentMoney);
}

void player::setStatus(const int status){
    if(status == 1){
        ui->status->setText("Your turn");
    }else{
        ui->status->setText("Betted");
    }
    ui->status->setStyleSheet("background-color: #FFFFFF ;");
}

// void player::setCard(const Card *card){
//     // do something
// }

void player::setScore(const int score){
    ui->score->setText(QString::number(score));
}

void player::setBetting(const int bet){
    ui->betting->setText(QString::number(bet));
}

void player::setCards(const CardData cards[], int num_of_cards){
    // reset all list card;
    // for(int i = 0; i< num_of_cards;i++){
        CardItem *cardItem = new CardItem();
        cardItem->setImage(cards[num_of_cards-1]);
        ui->list_card->addWidget(cardItem);
    // }
}

// std::string MessageTypeToString(MessageType type)
// {
//     switch(type)
//     {
//         case MessageType::CLT_DISCONNECT: return "CLT_DISCONNECT";
//         case MessageType::SRV_DISCONNECT: return "SRV_DISCONNECT";
//         case MessageType::SRV_INVALID_REQUEST: return "SRV_INVALID_REQUEST";
//         case MessageType::CLT_SIGNUP_REQ: return "CLT_SIGNUP_REQ";
//         case MessageType::CLT_LOGIN_REQ: return "CLT_LOGIN_REQ";
//         case MessageType::SRV_SIGNUP_RES: return "SRV_SIGNUP_RES";
//         case MessageType::SRV_LOGIN_RES: return "SRV_LOGIN_RES";
//         case MessageType::CLT_READYLIST_REQ: return "CLT_READYLIST_REQ";
//         case MessageType::SRV_READYLIST_RES: return "SRV_READYLIST_RES";
//         case MessageType::CLT_ROOMLIST_REQ: return "CLT_ROOMLIST_REQ";
//         case MessageType::SRV_ROOMLIST_RES: return "SRV_ROOMLIST_RES";
//         case MessageType::CLT_JOIN_ROOM_REQ: return "CLT_JOIN_ROOM_REQ";
//         case MessageType::CLT_CREATE_ROOM_REQ: return "CLT_CREATE_ROOM_REQ";
//         case MessageType::SRV_ADDTOROOM: return "SRV_ADDTOROOM";
//         case MessageType::SRV_START_ROUND: return "SRV_START_ROUND";
//         case MessageType::SRV_BET_REQUEST: return "SRV_BET_REQUEST";
//         case MessageType::CLT_PLAYER_BET: return "CLT_PLAYER_BET";
//         case MessageType::SRV_PLAYER_BET: return "SRV_PLAYER_BET";
//         case MessageType::SRV_GAME_STATE: return "SRV_GAME_STATE";
//         case MessageType::SRV_ACTION_REQUEST: return "SRV_ACTION_REQUEST";
//         case MessageType::CLT_PLAYER_ACTION: return "CLT_PLAYER_ACTION";
//         case MessageType::SRV_OUTCOME: return "SRV_OUTCOME";
//         case MessageType::SRV_READY_REQUEST: return "SRV_READY_REQUEST";
//         case MessageType::CLT_PLAYER_READY: return "CLT_PLAYER_READY";
//         case MessageType::CLT_LEAVE_ROOM: return "CLT_LEAVE_ROOM";
//         case MessageType::CLT_INVITE: return "CLT_INVITE";
//         case MessageType::SRV_INVITE: return "SRV_INVITE";
//         case MessageType::CLT_INVITE_REPLY: return "CLT_INVITE_REPLY";
//         case MessageType::SRV_INVITE_OUTCOME: return "SRV_INVITE_OUTCOME";
//         default: return "Unknown";
//     }
// }
