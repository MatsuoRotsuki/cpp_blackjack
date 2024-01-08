#include "screencontroller.h"
#include <QStackedWidget>

ScreenController::ScreenController(QObject *parent) : QObject(parent),m_stackedWidget(nullptr)
{
    // KHởi tạo các giá trị mặc định và xử lý khởi động ứng dụng
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



int ScreenController::getStackedWidgetIndex()
{
    if (m_stackedWidget){
        return m_stackedWidget->currentIndex();
    }else{
        return 0;
    }

}

