/********************************************************************************
** Form generated from reading UI file 'readywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READYWINDOW_H
#define UI_READYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReadyWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *ReadyWindow)
    {
        if (ReadyWindow->objectName().isEmpty())
            ReadyWindow->setObjectName("ReadyWindow");
        ReadyWindow->resize(714, 474);
        ReadyWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 67, 0);"));
        pushButton = new QPushButton(ReadyWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 190, 100, 32));

        retranslateUi(ReadyWindow);

        QMetaObject::connectSlotsByName(ReadyWindow);
    } // setupUi

    void retranslateUi(QWidget *ReadyWindow)
    {
        ReadyWindow->setWindowTitle(QCoreApplication::translate("ReadyWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ReadyWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReadyWindow: public Ui_ReadyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READYWINDOW_H
