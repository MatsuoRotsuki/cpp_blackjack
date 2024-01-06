#ifndef ROOMITEMWIDGET_H
#define ROOMITEMWIDGET_H

#include <QWidget>
#include <QPushButton>
QT_BEGIN_NAMESPACE

namespace Ui {
class RoomItemWidget;
}

class RoomItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RoomItemWidget(QWidget *parent = nullptr);
    ~RoomItemWidget();


private:
    Ui::RoomItemWidget *ui;

signals:
private slots:
    void on_joinRoombtn_clicked();
};

#endif // ROOMITEMWIDGET_H
