#include "carditem.h"
#include "ui_carditem.h"

CardItem::CardItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CardItem)
{
    ui->setupUi(this);
}

CardItem::~CardItem()
{
    delete ui;
}


void CardItem::setImage(const CardData data)
{
    QString image = "";
    QString additionalString = ".png";
    QString ten_num = "10";
    switch (data.rank)
    {
    case Rank::ACE:
        image += 'A';
        break;
    case Rank::TWO:
        image += '2';
        break;
    case Rank::THREE:
        image += '3';
        break;
    case Rank::FOUR:
        image += '4';
        break;
    case Rank::FIVE:
        image += '5';
        break;
    case Rank::SIX:
        image += '6';
        break;
    case Rank::SEVEN:
        image += '7';
        break;
    case Rank::EIGHT:
        image += '8';
        break;
    case Rank::NINE:
        image += '9';
        break;
    case Rank::TEN:
        image = image + ten_num;
        break;
    case Rank::JACK:
        image += 'J';
        break;
    case Rank::QUEEN:
        image += 'Q';
        break;
    case Rank::KING:
        image += 'K';
        break;
    default:
        break;
    }

    image += '_';

    switch (data.suit)
    {
    case Suit::CLUB:
        image += 'c';
        break;
    case Suit:: DIAMOND:
        image += 'd';
        break;
    case Suit :: HEART:
        image += 'd';
        break;
    case Suit::SPADE:
        image += 's';
    default : break;
    }

    image = image + additionalString;
    QPixmap pixmap(image);
    ui->Card_Item->setPixmap(pixmap);
}
