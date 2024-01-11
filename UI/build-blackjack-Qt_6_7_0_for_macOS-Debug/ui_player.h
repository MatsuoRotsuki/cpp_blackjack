/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_player
{
public:
    QFormLayout *formLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *readyBtn;
    QSpacerItem *horizontalSpacer_4;
    QLabel *status;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *list_card;
    QLabel *label_37;
    QLabel *score;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *userInfo;
    QLabel *betting;
    QLabel *avatar;
    QLabel *username;
    QLabel *money;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *player)
    {
        if (player->objectName().isEmpty())
            player->setObjectName("player");
        player->resize(360, 310);
        player->setMinimumSize(QSize(360, 310));
        player->setMaximumSize(QSize(360, 310));
        player->setLayoutDirection(Qt::LeftToRight);
        formLayout = new QFormLayout(player);
        formLayout->setObjectName("formLayout");
        widget_2 = new QWidget(player);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(119, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        readyBtn = new QPushButton(widget);
        readyBtn->setObjectName("readyBtn");
        readyBtn->setMinimumSize(QSize(70, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        readyBtn->setFont(font);
        readyBtn->setCursor(QCursor(Qt::PointingHandCursor));
        readyBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(242, 78, 30);\n"
"border-radius:10px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(readyBtn);

        horizontalSpacer_4 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget);

        status = new QLabel(widget_2);
        status->setObjectName("status");
        status->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(status);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_13 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        list_card = new QHBoxLayout();
        list_card->setSpacing(1);
        list_card->setObjectName("list_card");
        label_37 = new QLabel(widget_2);
        label_37->setObjectName("label_37");
        label_37->setMinimumSize(QSize(0, 0));
        label_37->setMaximumSize(QSize(50, 70));
        label_37->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_37->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_37->setScaledContents(true);

        list_card->addWidget(label_37);

        score = new QLabel(widget_2);
        score->setObjectName("score");
        score->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        list_card->addWidget(score);


        horizontalLayout_2->addLayout(list_card);

        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        userInfo = new QVBoxLayout();
        userInfo->setSpacing(6);
        userInfo->setObjectName("userInfo");
        betting = new QLabel(widget_2);
        betting->setObjectName("betting");
        QFont font1;
        font1.setBold(true);
        betting->setFont(font1);
        betting->setStyleSheet(QString::fromUtf8("color: rgb(255, 249, 100);"));
        betting->setAlignment(Qt::AlignCenter);

        userInfo->addWidget(betting);

        avatar = new QLabel(widget_2);
        avatar->setObjectName("avatar");
        avatar->setMinimumSize(QSize(50, 50));
        avatar->setMaximumSize(QSize(50, 50));
        avatar->setPixmap(QPixmap(QString::fromUtf8(":/resource/avater.png")));
        avatar->setScaledContents(true);
        avatar->setAlignment(Qt::AlignCenter);

        userInfo->addWidget(avatar);

        username = new QLabel(widget_2);
        username->setObjectName("username");

        userInfo->addWidget(username);

        money = new QLabel(widget_2);
        money->setObjectName("money");
        money->setFont(font1);
        money->setStyleSheet(QString::fromUtf8("color: rgb(255, 249, 100);"));
        money->setAlignment(Qt::AlignCenter);

        userInfo->addWidget(money);


        horizontalLayout->addLayout(userInfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        formLayout->setWidget(0, QFormLayout::LabelRole, widget_2);


        retranslateUi(player);

        QMetaObject::connectSlotsByName(player);
    } // setupUi

    void retranslateUi(QWidget *player)
    {
        player->setWindowTitle(QCoreApplication::translate("player", "Form", nullptr));
        readyBtn->setText(QCoreApplication::translate("player", "Ready", nullptr));
        status->setText(QCoreApplication::translate("player", "Status", nullptr));
        label_37->setText(QString());
        score->setText(QCoreApplication::translate("player", "6", nullptr));
        betting->setText(QCoreApplication::translate("player", "5K", nullptr));
        avatar->setText(QString());
        username->setText(QCoreApplication::translate("player", "Username", nullptr));
        money->setText(QCoreApplication::translate("player", "65K", nullptr));
    } // retranslateUi

};

namespace Ui {
    class player: public Ui_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
