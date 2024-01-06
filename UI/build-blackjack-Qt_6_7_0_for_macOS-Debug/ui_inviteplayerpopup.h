/********************************************************************************
** Form generated from reading UI file 'inviteplayerpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVITEPLAYERPOPUP_H
#define UI_INVITEPLAYERPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "onlineplayer.h"

QT_BEGIN_NAMESPACE

class Ui_InvitePlayerPopup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *list_player;
    QVBoxLayout *verticalLayout_2;
    OnlinePlayer *widget_2;
    OnlinePlayer *widget_3;

    void setupUi(QWidget *InvitePlayerPopup)
    {
        if (InvitePlayerPopup->objectName().isEmpty())
            InvitePlayerPopup->setObjectName("InvitePlayerPopup");
        InvitePlayerPopup->resize(233, 185);
        InvitePlayerPopup->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));
        verticalLayout = new QVBoxLayout(InvitePlayerPopup);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(InvitePlayerPopup);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label);

        list_player = new QWidget(InvitePlayerPopup);
        list_player->setObjectName("list_player");
        verticalLayout_2 = new QVBoxLayout(list_player);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new OnlinePlayer(list_player);
        widget_2->setObjectName("widget_2");

        verticalLayout_2->addWidget(widget_2);

        widget_3 = new OnlinePlayer(list_player);
        widget_3->setObjectName("widget_3");

        verticalLayout_2->addWidget(widget_3);


        verticalLayout->addWidget(list_player);


        retranslateUi(InvitePlayerPopup);

        QMetaObject::connectSlotsByName(InvitePlayerPopup);
    } // setupUi

    void retranslateUi(QWidget *InvitePlayerPopup)
    {
        InvitePlayerPopup->setWindowTitle(QCoreApplication::translate("InvitePlayerPopup", "Form", nullptr));
        label->setText(QCoreApplication::translate("InvitePlayerPopup", "Online", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvitePlayerPopup: public Ui_InvitePlayerPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVITEPLAYERPOPUP_H
