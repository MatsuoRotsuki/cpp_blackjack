/********************************************************************************
** Form generated from reading UI file 'roomitemclass.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMITEMCLASS_H
#define UI_ROOMITEMCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomItemClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *RoomItemClass)
    {
        if (RoomItemClass->objectName().isEmpty())
            RoomItemClass->setObjectName("RoomItemClass");
        RoomItemClass->resize(513, 112);
        RoomItemClass->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));
        gridLayout = new QGridLayout(RoomItemClass);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(RoomItemClass);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(RoomItemClass);

        QMetaObject::connectSlotsByName(RoomItemClass);
    } // setupUi

    void retranslateUi(QWidget *RoomItemClass)
    {
        RoomItemClass->setWindowTitle(QCoreApplication::translate("RoomItemClass", "Form", nullptr));
        label->setText(QCoreApplication::translate("RoomItemClass", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomItemClass: public Ui_RoomItemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMITEMCLASS_H
