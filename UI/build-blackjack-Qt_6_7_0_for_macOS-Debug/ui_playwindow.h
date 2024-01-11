/********************************************************************************
** Form generated from reading UI file 'playwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWINDOW_H
#define UI_PLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "player.h"

QT_BEGIN_NAMESPACE

class Ui_PlayWindow
{
public:
    QFrame *frame_2;
    QFrame *frame_11;
    QLabel *label_20;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_77;
    QLabel *label_76;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *list_card_11;
    QLabel *label_72;
    QLabel *label_73;
    QLabel *label_74;
    QLabel *label_75;
    QLabel *dealerScore;
    QSpacerItem *horizontalSpacer_26;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *quitBtn;
    QPushButton *inviteBtn;
    QWidget *layoutWidget2;
    QHBoxLayout *listPlayer;
    player *widget;
    QFormLayout *formLayout;
    player *widget_3;
    QFormLayout *formLayout_3;
    player *widget_5;
    QFormLayout *formLayout_6;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_11;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *coin_10;
    QPushButton *coin_25;
    QPushButton *coin_50;
    QPushButton *coin_100;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *cashout_btn;
    QPushButton *bet_btn;
    QLabel *credits;
    QPushButton *stand_btn;
    QPushButton *hit_btn;
    QSpacerItem *horizontalSpacer_12;
    QLabel *Notification;

    void setupUi(QWidget *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName("PlayWindow");
        PlayWindow->resize(1045, 686);
        frame_2 = new QFrame(PlayWindow);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(400, 0, 251, 51));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_11 = new QFrame(frame_2);
        frame_11->setObjectName("frame_11");
        frame_11->setGeometry(QRect(10, 10, 231, 31));
        frame_11->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"border-width: 2px;"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame_11);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(80, 10, 58, 16));
        label_20->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(PlayWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(340, 70, 459, 86));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget);
        horizontalLayout_18->setSpacing(25);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_77 = new QLabel(layoutWidget);
        label_77->setObjectName("label_77");
        label_77->setMinimumSize(QSize(0, 0));
        label_77->setMaximumSize(QSize(50, 70));
        label_77->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_77->setPixmap(QPixmap(QString::fromUtf8(":/resource/back.png")));
        label_77->setScaledContents(true);

        horizontalLayout_2->addWidget(label_77);

        label_76 = new QLabel(layoutWidget);
        label_76->setObjectName("label_76");
        label_76->setMinimumSize(QSize(0, 0));
        label_76->setMaximumSize(QSize(50, 70));
        label_76->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_76->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_76->setScaledContents(true);

        horizontalLayout_2->addWidget(label_76);


        horizontalLayout_18->addLayout(horizontalLayout_2);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(5);
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        list_card_11 = new QHBoxLayout();
        list_card_11->setSpacing(1);
        list_card_11->setObjectName("list_card_11");
        label_72 = new QLabel(layoutWidget);
        label_72->setObjectName("label_72");
        label_72->setMinimumSize(QSize(0, 0));
        label_72->setMaximumSize(QSize(50, 70));
        label_72->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_72->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_72->setScaledContents(true);

        list_card_11->addWidget(label_72);

        label_73 = new QLabel(layoutWidget);
        label_73->setObjectName("label_73");
        label_73->setMinimumSize(QSize(0, 0));
        label_73->setMaximumSize(QSize(50, 70));
        label_73->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_73->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_73->setScaledContents(true);

        list_card_11->addWidget(label_73);

        label_74 = new QLabel(layoutWidget);
        label_74->setObjectName("label_74");
        label_74->setMinimumSize(QSize(0, 0));
        label_74->setMaximumSize(QSize(50, 70));
        label_74->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_74->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_74->setScaledContents(true);

        list_card_11->addWidget(label_74);

        label_75 = new QLabel(layoutWidget);
        label_75->setObjectName("label_75");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_75->sizePolicy().hasHeightForWidth());
        label_75->setSizePolicy(sizePolicy);
        label_75->setMinimumSize(QSize(0, 0));
        label_75->setMaximumSize(QSize(50, 70));
        label_75->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_75->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_75->setScaledContents(true);

        list_card_11->addWidget(label_75);


        horizontalLayout_24->addLayout(list_card_11);

        dealerScore = new QLabel(layoutWidget);
        dealerScore->setObjectName("dealerScore");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        dealerScore->setFont(font);

        horizontalLayout_24->addWidget(dealerScore);

        horizontalSpacer_26 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_26);


        horizontalLayout_18->addLayout(horizontalLayout_24);

        layoutWidget1 = new QWidget(PlayWindow);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(800, 0, 152, 76));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        quitBtn = new QPushButton(layoutWidget1);
        quitBtn->setObjectName("quitBtn");
        quitBtn->setMinimumSize(QSize(100, 30));
        quitBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 15px;\n"
""));

        verticalLayout->addWidget(quitBtn);

        inviteBtn = new QPushButton(layoutWidget1);
        inviteBtn->setObjectName("inviteBtn");
        inviteBtn->setMinimumSize(QSize(100, 30));
        inviteBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 15px;"));

        verticalLayout->addWidget(inviteBtn);

        layoutWidget2 = new QWidget(PlayWindow);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(5, 291, 1061, 271));
        listPlayer = new QHBoxLayout(layoutWidget2);
        listPlayer->setSpacing(0);
        listPlayer->setObjectName("listPlayer");
        listPlayer->setContentsMargins(0, 0, 0, 0);
        widget = new player(layoutWidget2);
        widget->setObjectName("widget");
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);

        listPlayer->addWidget(widget);

        widget_3 = new player(layoutWidget2);
        widget_3->setObjectName("widget_3");
        formLayout_3 = new QFormLayout(widget_3);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_3->setLabelAlignment(Qt::AlignCenter);
        formLayout_3->setVerticalSpacing(10);
        formLayout_3->setContentsMargins(0, 0, 0, 0);

        listPlayer->addWidget(widget_3);

        widget_5 = new player(layoutWidget2);
        widget_5->setObjectName("widget_5");
        formLayout_6 = new QFormLayout(widget_5);
        formLayout_6->setObjectName("formLayout_6");
        formLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_6->setLabelAlignment(Qt::AlignCenter);
        formLayout_6->setVerticalSpacing(10);
        formLayout_6->setContentsMargins(0, 0, 0, 0);

        listPlayer->addWidget(widget_5);

        layoutWidget3 = new QWidget(PlayWindow);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(270, 580, 557, 104));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        frame_5 = new QFrame(layoutWidget3);
        frame_5->setObjectName("frame_5");
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_5);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_9);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        coin_10 = new QPushButton(frame_5);
        coin_10->setObjectName("coin_10");
        coin_10->setMinimumSize(QSize(25, 0));
        coin_10->setSizeIncrement(QSize(30, 30));
        coin_10->setBaseSize(QSize(30, 30));
        QFont font1;
        font1.setBold(true);
        coin_10->setFont(font1);
        coin_10->setCursor(QCursor(Qt::PointingHandCursor));
        coin_10->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgb(228, 192, 0);"));

        horizontalLayout_16->addWidget(coin_10);

        coin_25 = new QPushButton(frame_5);
        coin_25->setObjectName("coin_25");
        coin_25->setMinimumSize(QSize(25, 0));
        coin_25->setFont(font1);
        coin_25->setCursor(QCursor(Qt::PointingHandCursor));
        coin_25->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgb(0, 194, 8);"));

        horizontalLayout_16->addWidget(coin_25);

        coin_50 = new QPushButton(frame_5);
        coin_50->setObjectName("coin_50");
        coin_50->setMinimumSize(QSize(25, 0));
        coin_50->setFont(font1);
        coin_50->setCursor(QCursor(Qt::PointingHandCursor));
        coin_50->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color: rgb(0, 113, 177);"));

        horizontalLayout_16->addWidget(coin_50);

        coin_100 = new QPushButton(frame_5);
        coin_100->setObjectName("coin_100");
        coin_100->setMinimumSize(QSize(25, 0));
        coin_100->setFont(font1);
        coin_100->setCursor(QCursor(Qt::PointingHandCursor));
        coin_100->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgb(204, 19, 196);"));

        horizontalLayout_16->addWidget(coin_100);


        horizontalLayout_15->addLayout(horizontalLayout_16);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_10);


        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        cashout_btn = new QPushButton(frame_5);
        cashout_btn->setObjectName("cashout_btn");
        cashout_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 169, 17);\n"
""));

        horizontalLayout_17->addWidget(cashout_btn);

        bet_btn = new QPushButton(frame_5);
        bet_btn->setObjectName("bet_btn");
        bet_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 169, 17);"));

        horizontalLayout_17->addWidget(bet_btn);

        credits = new QLabel(frame_5);
        credits->setObjectName("credits");

        horizontalLayout_17->addWidget(credits);

        stand_btn = new QPushButton(frame_5);
        stand_btn->setObjectName("stand_btn");
        stand_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 169, 17);"));

        horizontalLayout_17->addWidget(stand_btn);

        hit_btn = new QPushButton(frame_5);
        hit_btn->setObjectName("hit_btn");
        hit_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 169, 17);"));

        horizontalLayout_17->addWidget(hit_btn);


        verticalLayout_7->addLayout(horizontalLayout_17);


        horizontalLayout->addWidget(frame_5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        Notification = new QLabel(PlayWindow);
        Notification->setObjectName("Notification");
        Notification->setGeometry(QRect(357, 195, 331, 61));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        Notification->setFont(font2);
        Notification->setAlignment(Qt::AlignCenter);

        retranslateUi(PlayWindow);

        QMetaObject::connectSlotsByName(PlayWindow);
    } // setupUi

    void retranslateUi(QWidget *PlayWindow)
    {
        PlayWindow->setWindowTitle(QCoreApplication::translate("PlayWindow", "Form", nullptr));
        label_20->setText(QCoreApplication::translate("PlayWindow", "Label", nullptr));
        label_77->setText(QString());
        label_76->setText(QString());
        label_72->setText(QString());
        label_73->setText(QString());
        label_74->setText(QString());
        label_75->setText(QString());
        dealerScore->setText(QCoreApplication::translate("PlayWindow", "15", nullptr));
        quitBtn->setText(QCoreApplication::translate("PlayWindow", "Quit", nullptr));
        inviteBtn->setText(QCoreApplication::translate("PlayWindow", "Invite", nullptr));
        coin_10->setText(QCoreApplication::translate("PlayWindow", "10", nullptr));
        coin_25->setText(QCoreApplication::translate("PlayWindow", "25", nullptr));
        coin_50->setText(QCoreApplication::translate("PlayWindow", "50", nullptr));
        coin_100->setText(QCoreApplication::translate("PlayWindow", "100", nullptr));
        cashout_btn->setText(QCoreApplication::translate("PlayWindow", "CASH OUT", nullptr));
        bet_btn->setText(QCoreApplication::translate("PlayWindow", "BET", nullptr));
        credits->setText(QCoreApplication::translate("PlayWindow", "CREDITS: 100", nullptr));
        stand_btn->setText(QCoreApplication::translate("PlayWindow", "STAND", nullptr));
        hit_btn->setText(QCoreApplication::translate("PlayWindow", "HIT", nullptr));
        Notification->setText(QCoreApplication::translate("PlayWindow", "Start New Round", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H
