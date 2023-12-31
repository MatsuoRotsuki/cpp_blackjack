/********************************************************************************
** Form generated from reading UI file 'roomitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMITEMWIDGET_H
#define UI_ROOMITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomItemWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *RoomItemWidget)
    {
        if (RoomItemWidget->objectName().isEmpty())
            RoomItemWidget->setObjectName("RoomItemWidget");
        RoomItemWidget->resize(400, 102);
        gridLayout = new QGridLayout(RoomItemWidget);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(RoomItemWidget);
        widget->setObjectName("widget");
        widget->setEnabled(true);
        widget->setMinimumSize(QSize(0, 0));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 10px;\n"
""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 169, 17);\n"
"border-radius: 4px;"));

        gridLayout_2->addWidget(pushButton, 1, 1, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(RoomItemWidget);

        QMetaObject::connectSlotsByName(RoomItemWidget);
    } // setupUi

    void retranslateUi(QWidget *RoomItemWidget)
    {
        RoomItemWidget->setWindowTitle(QCoreApplication::translate("RoomItemWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("RoomItemWidget", "ROOM 1", nullptr));
        label_2->setText(QCoreApplication::translate("RoomItemWidget", "2 Players", nullptr));
        label_3->setText(QCoreApplication::translate("RoomItemWidget", "Min Credit: 5k", nullptr));
        pushButton->setText(QCoreApplication::translate("RoomItemWidget", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomItemWidget: public Ui_RoomItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMITEMWIDGET_H
