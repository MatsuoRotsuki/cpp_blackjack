#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include "message.h"

namespace Ui {
class player;
}

class player : public QWidget
{
    Q_OBJECT

public:
    explicit player(QWidget *parent = nullptr);
    ~player();

    QString getUsername() const;

    void setUsername(const QString &username);

    void setCurrentMoney(const QString &currentMoney);

    void setStatus(const int status);

    // void setCard(const Card *card);

    void setScore(const int score);

    void setBetting(const int bet);

    void setCards(const CardData data[],int num_of_cards);

private:
    Ui::player *ui;
};

#endif // PLAYER_H
