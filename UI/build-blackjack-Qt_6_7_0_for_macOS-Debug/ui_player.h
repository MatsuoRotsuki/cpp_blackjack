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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_player
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *list_card_5;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *userInfo;
    QLabel *avatar;
    QLabel *username;
    QLabel *money;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *player)
    {
        if (player->objectName().isEmpty())
            player->setObjectName("player");
        player->resize(336, 312);
        player->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(player);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(player);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_13 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        list_card_5 = new QHBoxLayout();
        list_card_5->setSpacing(1);
        list_card_5->setObjectName("list_card_5");
        label_37 = new QLabel(player);
        label_37->setObjectName("label_37");
        label_37->setMinimumSize(QSize(0, 0));
        label_37->setMaximumSize(QSize(50, 70));
        label_37->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_37->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_37->setScaledContents(true);

        list_card_5->addWidget(label_37);

        label_38 = new QLabel(player);
        label_38->setObjectName("label_38");
        label_38->setMinimumSize(QSize(0, 0));
        label_38->setMaximumSize(QSize(50, 70));
        label_38->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_38->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_38->setScaledContents(true);

        list_card_5->addWidget(label_38);

        label_39 = new QLabel(player);
        label_39->setObjectName("label_39");
        label_39->setMinimumSize(QSize(0, 0));
        label_39->setMaximumSize(QSize(50, 70));
        label_39->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_39->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_39->setScaledContents(true);

        list_card_5->addWidget(label_39);

        label_40 = new QLabel(player);
        label_40->setObjectName("label_40");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy);
        label_40->setMinimumSize(QSize(0, 0));
        label_40->setMaximumSize(QSize(50, 70));
        label_40->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        label_40->setPixmap(QPixmap(QString::fromUtf8(":/resource/A_h.png")));
        label_40->setScaledContents(true);

        list_card_5->addWidget(label_40);


        horizontalLayout_2->addLayout(list_card_5);

        horizontalSpacer_14 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        userInfo = new QVBoxLayout();
        userInfo->setSpacing(12);
        userInfo->setObjectName("userInfo");
        avatar = new QLabel(player);
        avatar->setObjectName("avatar");
        avatar->setMinimumSize(QSize(50, 50));
        avatar->setMaximumSize(QSize(50, 50));
        avatar->setPixmap(QPixmap(QString::fromUtf8(":/resource/avater.png")));
        avatar->setScaledContents(true);
        avatar->setAlignment(Qt::AlignCenter);

        userInfo->addWidget(avatar);

        username = new QLabel(player);
        username->setObjectName("username");

        userInfo->addWidget(username);

        money = new QLabel(player);
        money->setObjectName("money");
        money->setAlignment(Qt::AlignCenter);

        userInfo->addWidget(money);


        horizontalLayout->addLayout(userInfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(player);

        QMetaObject::connectSlotsByName(player);
    } // setupUi

    void retranslateUi(QWidget *player)
    {
        player->setWindowTitle(QCoreApplication::translate("player", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("player", "Status", nullptr));
        label_37->setText(QString());
        label_38->setText(QString());
        label_39->setText(QString());
        label_40->setText(QString());
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
