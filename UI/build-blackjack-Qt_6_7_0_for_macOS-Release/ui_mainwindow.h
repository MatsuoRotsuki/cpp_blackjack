/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "roomitemwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_3;
    QStackedWidget *stackedWidget;
    QWidget *home;
    QLabel *label_4;
    QFrame *frame;
    QPushButton *pushButton_5;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playAloneBtn;
    QPushButton *playGroupBtn;
    QWidget *room;
    QPushButton *createNewRoom;
    QPushButton *pushButton_2;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    RoomItemWidget *widget_5;
    RoomItemWidget *widget_6;
    RoomItemWidget *widget_7;
    RoomItemWidget *widget_8;
    RoomItemWidget *widget_3;
    RoomItemWidget *widget_2;
    RoomItemWidget *widget_4;
    RoomItemWidget *widget_9;
    QWidget *invite;
    QLabel *label_3;
    QWidget *menu_widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *homeBtn;
    QPushButton *roomBtn;
    QPushButton *inviteBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(854, 519);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(1600, 1600));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(50, 50));
        pushButton_4->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/avatar.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(50, 50));
        pushButton_4->setAutoRepeatInterval(300);

        horizontalLayout->addWidget(pushButton_4);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        home = new QWidget();
        home->setObjectName("home");
        label_4 = new QLabel(home);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 20, 261, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(14);
        label_4->setFont(font);
        frame = new QFrame(home);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(300, 220, 91, 61));
        frame->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"border-color: rgb(255, 255, 255);\n"
"border-width: 2px; \n"
"border-style: solid;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 0, 91, 60));
        pushButton_5->setMinimumSize(QSize(90, 60));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 30px;\n"
"border-color: rgb(255, 255, 255);"));
        widget1 = new QWidget(home);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(140, 70, 416, 112));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        playAloneBtn = new QPushButton(widget1);
        playAloneBtn->setObjectName("playAloneBtn");
        playAloneBtn->setMinimumSize(QSize(200, 100));
        playAloneBtn->setCursor(QCursor(Qt::PointingHandCursor));
        playAloneBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
""));

        horizontalLayout_2->addWidget(playAloneBtn);

        playGroupBtn = new QPushButton(widget1);
        playGroupBtn->setObjectName("playGroupBtn");
        playGroupBtn->setMinimumSize(QSize(200, 100));
        playGroupBtn->setCursor(QCursor(Qt::PointingHandCursor));
        playGroupBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-color: rgb(255, 255, 255);\n"
"border-radius: 10px;"));

        horizontalLayout_2->addWidget(playGroupBtn);

        stackedWidget->addWidget(home);
        room = new QWidget();
        room->setObjectName("room");
        createNewRoom = new QPushButton(room);
        createNewRoom->setObjectName("createNewRoom");
        createNewRoom->setGeometry(QRect(10, 10, 200, 30));
        createNewRoom->setMinimumSize(QSize(200, 30));
        createNewRoom->setMaximumSize(QSize(200, 30));
        createNewRoom->setCursor(QCursor(Qt::PointingHandCursor));
        createNewRoom->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 178, 255);\n"
"border-radius: 10px;"));
        pushButton_2 = new QPushButton(room);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 10, 200, 30));
        pushButton_2->setMinimumSize(QSize(200, 30));
        pushButton_2->setMaximumSize(QSize(200, 30));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 178, 255);\n"
"border-radius: 10px;"));
        widget2 = new QWidget(room);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(0, 60, 731, 361));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_5 = new RoomItemWidget(widget2);
        widget_5->setObjectName("widget_5");
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 65);"));

        gridLayout_2->addWidget(widget_5, 3, 0, 1, 1);

        widget_6 = new RoomItemWidget(widget2);
        widget_6->setObjectName("widget_6");
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 85);"));

        gridLayout_2->addWidget(widget_6, 1, 0, 1, 1);

        widget_7 = new RoomItemWidget(widget2);
        widget_7->setObjectName("widget_7");

        gridLayout_2->addWidget(widget_7, 1, 1, 1, 1);

        widget_8 = new RoomItemWidget(widget2);
        widget_8->setObjectName("widget_8");

        gridLayout_2->addWidget(widget_8, 2, 1, 1, 1);

        widget_3 = new RoomItemWidget(widget2);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 255, 66);"));

        gridLayout_2->addWidget(widget_3, 3, 1, 1, 1);

        widget_2 = new RoomItemWidget(widget2);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 4, 255);"));

        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        widget_4 = new RoomItemWidget(widget2);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 67);"));

        gridLayout_2->addWidget(widget_4, 0, 1, 1, 1);

        widget_9 = new RoomItemWidget(widget2);
        widget_9->setObjectName("widget_9");

        gridLayout_2->addWidget(widget_9, 2, 0, 1, 1);

        stackedWidget->addWidget(room);
        invite = new QWidget();
        invite->setObjectName("invite");
        label_3 = new QLabel(invite);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 190, 58, 16));
        stackedWidget->addWidget(invite);

        gridLayout_3->addWidget(stackedWidget, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        menu_widget = new QWidget(centralwidget);
        menu_widget->setObjectName("menu_widget");
        menu_widget->setMaximumSize(QSize(141, 400));
        menu_widget->setToolTipDuration(-1);
        menu_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));
        verticalLayout_2 = new QVBoxLayout(menu_widget);
#ifndef Q_OS_MAC
        verticalLayout_2->setSpacing(-1);
#endif
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(menu_widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(-1);
#endif
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        homeBtn = new QPushButton(menu_widget);
        homeBtn->setObjectName("homeBtn");

        verticalLayout->addWidget(homeBtn);

        roomBtn = new QPushButton(menu_widget);
        roomBtn->setObjectName("roomBtn");

        verticalLayout->addWidget(roomBtn);

        inviteBtn = new QPushButton(menu_widget);
        inviteBtn->setObjectName("inviteBtn");

        verticalLayout->addWidget(inviteBtn);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 300, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addWidget(menu_widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Jemmy", nullptr));
        pushButton_4->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Welcome to Blackjack game", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Play game", nullptr));
        playAloneBtn->setText(QCoreApplication::translate("MainWindow", "Play Alone", nullptr));
        playGroupBtn->setText(QCoreApplication::translate("MainWindow", "Play with other player", nullptr));
        createNewRoom->setText(QCoreApplication::translate("MainWindow", "Create new room", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Join random", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "invite", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        homeBtn->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        roomBtn->setText(QCoreApplication::translate("MainWindow", "Room", nullptr));
        inviteBtn->setText(QCoreApplication::translate("MainWindow", "Invite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
