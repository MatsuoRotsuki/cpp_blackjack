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
    QWidget *widget;
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
    QSpacerItem *horizontalSpacer_26;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;
    QWidget *widget2;
    QHBoxLayout *listPlayer;
    player *widget3;
    QFormLayout *formLayout;
    player *widget_3;
    QFormLayout *formLayout_3;
    player *widget_5;
    QFormLayout *formLayout_6;
    player *widget_4;
    QFormLayout *formLayout_4;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_11;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_33;
    QPushButton *pushButton_34;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *cashout_btn;
    QPushButton *bet_btn;
    QLabel *credits;
    QPushButton *stand_btn;
    QPushButton *hit_btn;
    QSpacerItem *horizontalSpacer_12;

    void setupUi(QWidget *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName("PlayWindow");
        PlayWindow->resize(1020, 579);
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
        widget = new QWidget(PlayWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(340, 70, 459, 86));
        horizontalLayout_18 = new QHBoxLayout(widget);
        horizontalLayout_18->setSpacing(25);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_77 = new QLabel(widget);
        label_77->setObjectName("label_77");
        label_77->setMinimumSize(QSize(0, 0));
        label_77->setMaximumSize(QSize(50, 70));
        label_77->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_77->setPixmap(QPixmap(QString::fromUtf8("back.png")));
        label_77->setScaledContents(true);

        horizontalLayout_2->addWidget(label_77);

        label_76 = new QLabel(widget);
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
        label_72 = new QLabel(widget);
        label_72->setObjectName("label_72");
        label_72->setMinimumSize(QSize(0, 0));
        label_72->setMaximumSize(QSize(50, 70));
        label_72->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_72->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_72->setScaledContents(true);

        list_card_11->addWidget(label_72);

        label_73 = new QLabel(widget);
        label_73->setObjectName("label_73");
        label_73->setMinimumSize(QSize(0, 0));
        label_73->setMaximumSize(QSize(50, 70));
        label_73->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_73->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_73->setScaledContents(true);

        list_card_11->addWidget(label_73);

        label_74 = new QLabel(widget);
        label_74->setObjectName("label_74");
        label_74->setMinimumSize(QSize(0, 0));
        label_74->setMaximumSize(QSize(50, 70));
        label_74->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_74->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_74->setScaledContents(true);

        list_card_11->addWidget(label_74);

        label_75 = new QLabel(widget);
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

        horizontalSpacer_26 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_26);


        horizontalLayout_18->addLayout(horizontalLayout_24);

        widget1 = new QWidget(PlayWindow);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(800, 0, 152, 66));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_37 = new QPushButton(widget1);
        pushButton_37->setObjectName("pushButton_37");
        pushButton_37->setMinimumSize(QSize(100, 0));
        pushButton_37->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));

        verticalLayout->addWidget(pushButton_37);

        pushButton_38 = new QPushButton(widget1);
        pushButton_38->setObjectName("pushButton_38");
        pushButton_38->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));

        verticalLayout->addWidget(pushButton_38);

        widget2 = new QWidget(PlayWindow);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(50, 280, 956, 182));
        listPlayer = new QHBoxLayout(widget2);
        listPlayer->setSpacing(0);
        listPlayer->setObjectName("listPlayer");
        listPlayer->setContentsMargins(0, 0, 0, 0);
        widget3 = new player(widget2);
        widget3->setObjectName("widget3");
        formLayout = new QFormLayout(widget3);
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);

        listPlayer->addWidget(widget3);

        widget_3 = new player(widget2);
        widget_3->setObjectName("widget_3");
        formLayout_3 = new QFormLayout(widget_3);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_3->setLabelAlignment(Qt::AlignCenter);
        formLayout_3->setVerticalSpacing(10);
        formLayout_3->setContentsMargins(0, 0, 0, 0);

        listPlayer->addWidget(widget_3);

        widget_5 = new player(widget2);
        widget_5->setObjectName("widget_5");
        formLayout_6 = new QFormLayout(widget_5);
        formLayout_6->setObjectName("formLayout_6");
        formLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_6->setLabelAlignment(Qt::AlignCenter);
        formLayout_6->setVerticalSpacing(10);
        formLayout_6->setContentsMargins(0, 0, 0, 0);

        listPlayer->addWidget(widget_5);

        widget_4 = new player(widget2);
        widget_4->setObjectName("widget_4");
        formLayout_4 = new QFormLayout(widget_4);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_4->setLabelAlignment(Qt::AlignCenter);
        formLayout_4->setVerticalSpacing(10);
        formLayout_4->setContentsMargins(0, 0, 0, 0);

        listPlayer->addWidget(widget_4);

        widget4 = new QWidget(PlayWindow);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(270, 470, 557, 104));
        horizontalLayout = new QHBoxLayout(widget4);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        frame_5 = new QFrame(widget4);
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
        pushButton_33 = new QPushButton(frame_5);
        pushButton_33->setObjectName("pushButton_33");

        horizontalLayout_16->addWidget(pushButton_33);

        pushButton_34 = new QPushButton(frame_5);
        pushButton_34->setObjectName("pushButton_34");

        horizontalLayout_16->addWidget(pushButton_34);

        pushButton_35 = new QPushButton(frame_5);
        pushButton_35->setObjectName("pushButton_35");

        horizontalLayout_16->addWidget(pushButton_35);

        pushButton_36 = new QPushButton(frame_5);
        pushButton_36->setObjectName("pushButton_36");

        horizontalLayout_16->addWidget(pushButton_36);


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
        pushButton_37->setText(QCoreApplication::translate("PlayWindow", "Quit", nullptr));
        pushButton_38->setText(QCoreApplication::translate("PlayWindow", "Invite", nullptr));
        pushButton_33->setText(QCoreApplication::translate("PlayWindow", "10", nullptr));
        pushButton_34->setText(QCoreApplication::translate("PlayWindow", "25", nullptr));
        pushButton_35->setText(QCoreApplication::translate("PlayWindow", "50", nullptr));
        pushButton_36->setText(QCoreApplication::translate("PlayWindow", "100", nullptr));
        cashout_btn->setText(QCoreApplication::translate("PlayWindow", "CASH OUT", nullptr));
        bet_btn->setText(QCoreApplication::translate("PlayWindow", "BET", nullptr));
        credits->setText(QCoreApplication::translate("PlayWindow", "CREDITS: 100", nullptr));
        stand_btn->setText(QCoreApplication::translate("PlayWindow", "STAND", nullptr));
        hit_btn->setText(QCoreApplication::translate("PlayWindow", "HIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H
