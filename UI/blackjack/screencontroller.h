#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class QStackedWidget;

class ScreenController : public QObject
{
    Q_OBJECT
public:
    // static ScreenController* getInstance();
    static ScreenController& instance();
    void setStackedWidget(QStackedWidget* stackedWidget_main);
    int getStackedWidgetIndex();
    QStackedWidget* getStackedWidget() const;

signals:
    // Thêm các signals dùng để điều hướng giữa các màn hình
    // void back_to_home_screen();

public slots:
    // Thêm các slots dùng để xử lý điều hướng giữa các màn hình
    // void signal_to_back_to_home_screen();
    void switchToScreen(int screenIndex);

private:
    explicit ScreenController(QObject *parent = nullptr);

    QStackedWidget* m_stackedWidget;
    Q_DISABLE_COPY(ScreenController)
    // static ScreenController* instance;
};

#endif // SCREENCONTROLLER_H
