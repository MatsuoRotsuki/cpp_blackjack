/********************************************************************************
** Form generated from reading UI file 'roomItem.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMITEM_H
#define UI_ROOMITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roomitem
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *roomitem)
    {
        if (roomitem->objectName().isEmpty())
            roomitem->setObjectName("roomitem");
        roomitem->resize(421, 112);
        roomitem->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 5px;"));
        gridLayout = new QGridLayout(roomitem);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(roomitem);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(roomitem);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_2 = new QLabel(roomitem);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton = new QPushButton(roomitem);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(60, 25));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 169, 17);\n"
"border-radius: 4px;"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(roomitem);

        QMetaObject::connectSlotsByName(roomitem);
    } // setupUi

    void retranslateUi(QWidget *roomitem)
    {
        roomitem->setWindowTitle(QCoreApplication::translate("roomitem", "Form", nullptr));
        label->setText(QCoreApplication::translate("roomitem", "ROOM 1", nullptr));
        label_3->setText(QCoreApplication::translate("roomitem", "2 players", nullptr));
        label_2->setText(QCoreApplication::translate("roomitem", "Min Credit: 5K", nullptr));
        pushButton->setText(QCoreApplication::translate("roomitem", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roomitem: public Ui_roomitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMITEM_H
