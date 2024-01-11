#ifndef CARDITEM_H
#define CARDITEM_H

#include <QWidget>
#include "message.h"
namespace Ui {
class CardItem;
}

class CardItem : public QWidget
{
    Q_OBJECT

public:
    // Hàm để đặt ảnh từ đường dẫn tệp hình ảnh
    void setImagePath(const QString &path);

    // Hàm để đặt ảnh từ QPixmap
    void setImage(const CardData cardItem);
    // void setImage(const CardData data )

    explicit CardItem(QWidget *parent = nullptr);
    ~CardItem();

private:
    Ui::CardItem *ui;
};

#endif // CARDITEM_H
