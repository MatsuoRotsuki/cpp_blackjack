#ifndef QUITPOPUP_H
#define QUITPOPUP_H

#include <QWidget>

namespace Ui {
class QuitPopup;
}

class QuitPopup : public QWidget
{
    Q_OBJECT

public:
    explicit QuitPopup(QWidget *parent = nullptr);
    ~QuitPopup();

private:
    Ui::QuitPopup *ui;
};

#endif // QUITPOPUP_H
