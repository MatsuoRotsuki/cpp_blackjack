#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include "card.h"

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

    void setStatus(const QString &status);

    void setCard(const )

private:
    Ui::player *ui;
};

#endif // PLAYER_H
