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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "playwindow.h"
#include "roomitemwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget_main;
    QWidget *main_screen;
    QGridLayout *gridLayout;
    QWidget *menu_widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *homeBtn;
    QPushButton *roomBtn;
    QPushButton *inviteBtn;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *room;
    QPushButton *createNewRoomBtn;
    QPushButton *joinRandomBtn;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_2;
    RoomItemWidget *widget_5;
    RoomItemWidget *widget_6;
    RoomItemWidget *widget_7;
    RoomItemWidget *widget_8;
    RoomItemWidget *widget_3;
    RoomItemWidget *widget_2;
    RoomItemWidget *widget_4;
    RoomItemWidget *widget_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_9;
    QStackedWidget *stackedWidget1;
    QWidget *room_2;
    QWidget *layoutWidget_41;
    QGridLayout *gridLayout_21;
    RoomItemWidget *widget_51;
    RoomItemWidget *widget_61;
    RoomItemWidget *widget_71;
    RoomItemWidget *widget_81;
    RoomItemWidget *widget_31;
    RoomItemWidget *widget_21;
    RoomItemWidget *widget_41;
    RoomItemWidget *widget_91;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createNewRoomBtn1;
    QPushButton *joinRandomBtn1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *onlineList;
    QWidget *ready_screen;
    QWidget *widget_10;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QLabel *label_10;
    QSplitter *splitter;
    QFrame *frame_4;
    QPushButton *cancelBtn;
    QFrame *frame_3;
    QPushButton *startBtn;
    PlayWindow *play_window;
    QWidget *Signup;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *fullnameLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *usernameLineEdit_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *passwordLineEdit_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *confirmpasswordLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *signup_btn;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *signUpError;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *to_login_page_btn;
    QSpacerItem *horizontalSpacer_15;
    QWidget *Login;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_13;
    QLineEdit *usernameLineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *login_btn;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_6;
    QLabel *loginError;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *to_signup_page_btn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1086, 672);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        stackedWidget_main = new QStackedWidget(centralwidget);
        stackedWidget_main->setObjectName("stackedWidget_main");
        main_screen = new QWidget();
        main_screen->setObjectName("main_screen");
        gridLayout = new QGridLayout(main_screen);
        gridLayout->setObjectName("gridLayout");
        menu_widget = new QWidget(main_screen);
        menu_widget->setObjectName("menu_widget");
        menu_widget->setMaximumSize(QSize(141, 400));
        menu_widget->setToolTipDuration(-1);
        menu_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);"));
        verticalLayout_2 = new QVBoxLayout(menu_widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(menu_widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
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

        widget = new QWidget(main_screen);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(1600, 1600));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        room = new QWidget();
        room->setObjectName("room");
        createNewRoomBtn = new QPushButton(room);
        createNewRoomBtn->setObjectName("createNewRoomBtn");
        createNewRoomBtn->setGeometry(QRect(10, 10, 200, 30));
        createNewRoomBtn->setMinimumSize(QSize(200, 30));
        createNewRoomBtn->setMaximumSize(QSize(200, 30));
        createNewRoomBtn->setCursor(QCursor(Qt::PointingHandCursor));
        createNewRoomBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 178, 255);\n"
"border-radius: 10px;"));
        joinRandomBtn = new QPushButton(room);
        joinRandomBtn->setObjectName("joinRandomBtn");
        joinRandomBtn->setGeometry(QRect(240, 10, 200, 30));
        joinRandomBtn->setMinimumSize(QSize(200, 30));
        joinRandomBtn->setMaximumSize(QSize(200, 30));
        joinRandomBtn->setCursor(QCursor(Qt::PointingHandCursor));
        joinRandomBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 178, 255);\n"
"border-radius: 10px;"));
        layoutWidget_4 = new QWidget(room);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(0, 60, 731, 361));
        gridLayout_2 = new QGridLayout(layoutWidget_4);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_5 = new RoomItemWidget(layoutWidget_4);
        widget_5->setObjectName("widget_5");
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 65);"));

        gridLayout_2->addWidget(widget_5, 3, 0, 1, 1);

        widget_6 = new RoomItemWidget(layoutWidget_4);
        widget_6->setObjectName("widget_6");
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 85);"));

        gridLayout_2->addWidget(widget_6, 1, 0, 1, 1);

        widget_7 = new RoomItemWidget(layoutWidget_4);
        widget_7->setObjectName("widget_7");

        gridLayout_2->addWidget(widget_7, 1, 1, 1, 1);

        widget_8 = new RoomItemWidget(layoutWidget_4);
        widget_8->setObjectName("widget_8");

        gridLayout_2->addWidget(widget_8, 2, 1, 1, 1);

        widget_3 = new RoomItemWidget(layoutWidget_4);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 255, 66);"));

        gridLayout_2->addWidget(widget_3, 3, 1, 1, 1);

        widget_2 = new RoomItemWidget(layoutWidget_4);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 4, 255);"));

        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        widget_4 = new RoomItemWidget(layoutWidget_4);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 67);"));

        gridLayout_2->addWidget(widget_4, 0, 1, 1, 1);

        widget_9 = new RoomItemWidget(layoutWidget_4);
        widget_9->setObjectName("widget_9");

        gridLayout_2->addWidget(widget_9, 2, 0, 1, 1);

        stackedWidget->addWidget(room);

        gridLayout_3->addWidget(stackedWidget, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_7 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");
        label_9->setFrameShape(QFrame::NoFrame);

        horizontalLayout_5->addWidget(label_9);

        horizontalSpacer_8 = new QSpacerItem(13, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(50, 50));
        pushButton_6->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/avatar.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon);
        pushButton_6->setIconSize(QSize(50, 50));
        pushButton_6->setAutoRepeatInterval(300);

        horizontalLayout_5->addWidget(pushButton_6);

        horizontalSpacer_9 = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        stackedWidget1 = new QStackedWidget(widget);
        stackedWidget1->setObjectName("stackedWidget1");
        room_2 = new QWidget();
        room_2->setObjectName("room_2");
        layoutWidget_41 = new QWidget(room_2);
        layoutWidget_41->setObjectName("layoutWidget_41");
        layoutWidget_41->setGeometry(QRect(0, 60, 591, 361));
        gridLayout_21 = new QGridLayout(layoutWidget_41);
        gridLayout_21->setSpacing(0);
        gridLayout_21->setObjectName("gridLayout_21");
        gridLayout_21->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        widget_51 = new RoomItemWidget(layoutWidget_41);
        widget_51->setObjectName("widget_51");
        widget_51->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 65);"));

        gridLayout_21->addWidget(widget_51, 3, 0, 1, 1);

        widget_61 = new RoomItemWidget(layoutWidget_41);
        widget_61->setObjectName("widget_61");
        widget_61->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 85);"));

        gridLayout_21->addWidget(widget_61, 1, 0, 1, 1);

        widget_71 = new RoomItemWidget(layoutWidget_41);
        widget_71->setObjectName("widget_71");

        gridLayout_21->addWidget(widget_71, 1, 1, 1, 1);

        widget_81 = new RoomItemWidget(layoutWidget_41);
        widget_81->setObjectName("widget_81");

        gridLayout_21->addWidget(widget_81, 2, 1, 1, 1);

        widget_31 = new RoomItemWidget(layoutWidget_41);
        widget_31->setObjectName("widget_31");
        widget_31->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 255, 66);"));

        gridLayout_21->addWidget(widget_31, 3, 1, 1, 1);

        widget_21 = new RoomItemWidget(layoutWidget_41);
        widget_21->setObjectName("widget_21");
        widget_21->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 4, 255);"));

        gridLayout_21->addWidget(widget_21, 0, 0, 1, 1);

        widget_41 = new RoomItemWidget(layoutWidget_41);
        widget_41->setObjectName("widget_41");
        widget_41->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 67);"));

        gridLayout_21->addWidget(widget_41, 0, 1, 1, 1);

        widget_91 = new RoomItemWidget(layoutWidget_41);
        widget_91->setObjectName("widget_91");

        gridLayout_21->addWidget(widget_91, 2, 0, 1, 1);

        layoutWidget = new QWidget(room_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 416, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        createNewRoomBtn1 = new QPushButton(layoutWidget);
        createNewRoomBtn1->setObjectName("createNewRoomBtn1");
        createNewRoomBtn1->setMinimumSize(QSize(200, 30));
        createNewRoomBtn1->setMaximumSize(QSize(200, 30));
        createNewRoomBtn1->setCursor(QCursor(Qt::PointingHandCursor));
        createNewRoomBtn1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 178, 255);\n"
"border-radius: 10px;"));

        horizontalLayout_2->addWidget(createNewRoomBtn1);

        joinRandomBtn1 = new QPushButton(layoutWidget);
        joinRandomBtn1->setObjectName("joinRandomBtn1");
        joinRandomBtn1->setMinimumSize(QSize(200, 30));
        joinRandomBtn1->setMaximumSize(QSize(200, 30));
        joinRandomBtn1->setCursor(QCursor(Qt::PointingHandCursor));
        joinRandomBtn1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 178, 255);\n"
"border-radius: 10px;"));

        horizontalLayout_2->addWidget(joinRandomBtn1);

        verticalLayoutWidget = new QWidget(room_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(620, 60, 191, 361));
        onlineList = new QVBoxLayout(verticalLayoutWidget);
        onlineList->setObjectName("onlineList");
        onlineList->setContentsMargins(0, 0, 0, 0);
        stackedWidget1->addWidget(room_2);

        gridLayout_3->addWidget(stackedWidget1, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        stackedWidget_main->addWidget(main_screen);
        ready_screen = new QWidget();
        ready_screen->setObjectName("ready_screen");
        widget_10 = new QWidget(ready_screen);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(200, 40, 638, 421));
        layoutWidget1 = new QWidget(widget_10);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(180, 100, 278, 122));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName("label_11");
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(36);
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_11);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName("label_10");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Kannada MN")});
        font1.setPointSize(36);
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_10);

        splitter = new QSplitter(widget_10);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(220, 260, 191, 61));
        splitter->setOrientation(Qt::Horizontal);
        frame_4 = new QFrame(splitter);
        frame_4->setObjectName("frame_4");
        frame_4->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"border-color: rgb(255, 255, 255);\n"
"border-width: 2px; \n"
"border-style: solid;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        cancelBtn = new QPushButton(frame_4);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setGeometry(QRect(0, 0, 91, 60));
        cancelBtn->setMinimumSize(QSize(90, 60));
        cancelBtn->setCursor(QCursor(Qt::PointingHandCursor));
        cancelBtn->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"background-color: rgb(242, 78, 30);\n"
"border-color: rgb(255, 255, 255);"));
        splitter->addWidget(frame_4);
        frame_3 = new QFrame(splitter);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"border-color: rgb(255, 255, 255);\n"
"border-width: 2px; \n"
"border-style: solid;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        startBtn = new QPushButton(frame_3);
        startBtn->setObjectName("startBtn");
        startBtn->setGeometry(QRect(0, 0, 91, 60));
        startBtn->setMinimumSize(QSize(90, 60));
        startBtn->setCursor(QCursor(Qt::PointingHandCursor));
        startBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 30px;\n"
"border-color: rgb(255, 255, 255);"));
        splitter->addWidget(frame_3);
        stackedWidget_main->addWidget(ready_screen);
        play_window = new PlayWindow();
        play_window->setObjectName("play_window");
        stackedWidget_main->addWidget(play_window);
        Signup = new QWidget();
        Signup->setObjectName("Signup");
        widget_11 = new QWidget(Signup);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(270, 130, 421, 301));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 5px;"));
        verticalLayout_4 = new QVBoxLayout(widget_11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(widget_11);
        label_5->setObjectName("label_5");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Umpush")});
        font2.setPointSize(20);
        font2.setBold(true);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color:white;"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_6 = new QLabel(widget_11);
        label_6->setObjectName("label_6");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Umpush")});
        font3.setPointSize(16);
        font3.setBold(true);
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(label_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        fullnameLineEdit = new QLineEdit(widget_11);
        fullnameLineEdit->setObjectName("fullnameLineEdit");
        fullnameLineEdit->setMinimumSize(QSize(200, 0));
        fullnameLineEdit->setMaximumSize(QSize(200, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Ubuntu Mono")});
        font4.setPointSize(14);
        fullnameLineEdit->setFont(font4);
        fullnameLineEdit->setStyleSheet(QString::fromUtf8("border: 2px solid white; color: white;"));

        horizontalLayout->addWidget(fullnameLineEdit);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(widget_11);
        label_7->setObjectName("label_7");
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_7->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        usernameLineEdit_2 = new QLineEdit(widget_11);
        usernameLineEdit_2->setObjectName("usernameLineEdit_2");
        usernameLineEdit_2->setMinimumSize(QSize(200, 0));
        usernameLineEdit_2->setMaximumSize(QSize(200, 16777215));
        usernameLineEdit_2->setFont(font4);
        usernameLineEdit_2->setStyleSheet(QString::fromUtf8("border: 2px solid white; color: white;"));

        horizontalLayout_7->addWidget(usernameLineEdit_2);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(widget_11);
        label_8->setObjectName("label_8");
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_8->addWidget(label_8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        passwordLineEdit_2 = new QLineEdit(widget_11);
        passwordLineEdit_2->setObjectName("passwordLineEdit_2");
        passwordLineEdit_2->setMinimumSize(QSize(200, 0));
        passwordLineEdit_2->setMaximumSize(QSize(200, 16777215));
        passwordLineEdit_2->setFont(font4);
        passwordLineEdit_2->setStyleSheet(QString::fromUtf8("border: 2px solid white; color: white;"));
        passwordLineEdit_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(passwordLineEdit_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_12 = new QLabel(widget_11);
        label_12->setObjectName("label_12");
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_9->addWidget(label_12);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        confirmpasswordLineEdit = new QLineEdit(widget_11);
        confirmpasswordLineEdit->setObjectName("confirmpasswordLineEdit");
        confirmpasswordLineEdit->setMinimumSize(QSize(200, 0));
        confirmpasswordLineEdit->setMaximumSize(QSize(200, 16777215));
        confirmpasswordLineEdit->setFont(font4);
        confirmpasswordLineEdit->setStyleSheet(QString::fromUtf8("border: 2px solid white; color: white;"));
        confirmpasswordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_9->addWidget(confirmpasswordLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        signup_btn = new QPushButton(widget_11);
        signup_btn->setObjectName("signup_btn");
        signup_btn->setFont(font3);
        signup_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 145, 80);\n"
"padding-top: 7px;\n"
"padding-left: 30px; \n"
"padding-bottom: 7px;\n"
"padding-right: 30px; \n"
"color: white;"));

        horizontalLayout_10->addWidget(signup_btn);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        signUpError = new QLabel(widget_11);
        signUpError->setObjectName("signUpError");
        signUpError->setFont(font4);
        signUpError->setStyleSheet(QString::fromUtf8("color:white;"));

        horizontalLayout_11->addWidget(signUpError);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        to_login_page_btn = new QPushButton(widget_11);
        to_login_page_btn->setObjectName("to_login_page_btn");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Umpush")});
        font5.setPointSize(14);
        font5.setBold(true);
        to_login_page_btn->setFont(font5);
        to_login_page_btn->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_4->addWidget(to_login_page_btn);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);


        verticalLayout_4->addLayout(horizontalLayout_4);

        stackedWidget_main->addWidget(Signup);
        Login = new QWidget();
        Login->setObjectName("Login");
        widget_12 = new QWidget(Login);
        widget_12->setObjectName("widget_12");
        widget_12->setGeometry(QRect(270, 130, 381, 281));
        widget_12->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 32, 32);\n"
"border-radius: 5px;"));
        verticalLayout_6 = new QVBoxLayout(widget_12);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_14 = new QLabel(widget_12);
        label_14->setObjectName("label_14");
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: white;"));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_18 = new QLabel(widget_12);
        label_18->setObjectName("label_18");
        label_18->setFont(font3);
        label_18->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_12->addWidget(label_18);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_13);

        usernameLineEdit = new QLineEdit(widget_12);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setMinimumSize(QSize(200, 0));
        usernameLineEdit->setMaximumSize(QSize(200, 16777215));
        usernameLineEdit->setFont(font4);
        usernameLineEdit->setStyleSheet(QString::fromUtf8("border: 2px solid white; color: white;"));

        horizontalLayout_12->addWidget(usernameLineEdit);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_19 = new QLabel(widget_12);
        label_19->setObjectName("label_19");
        label_19->setFont(font3);
        label_19->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_13->addWidget(label_19);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_14);

        passwordLineEdit = new QLineEdit(widget_12);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setMinimumSize(QSize(200, 0));
        passwordLineEdit->setMaximumSize(QSize(200, 16777215));
        passwordLineEdit->setFont(font4);
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border: 2px solid white; color:white;"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_13->addWidget(passwordLineEdit);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_16);

        login_btn = new QPushButton(widget_12);
        login_btn->setObjectName("login_btn");
        login_btn->setFont(font3);
        login_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 145, 80);\n"
"padding-top: 7px;\n"
"padding-left: 30px; \n"
"padding-bottom: 7px;\n"
"padding-right: 30px; \n"
"color: white;"));

        horizontalLayout_15->addWidget(login_btn);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_17);


        verticalLayout_6->addLayout(horizontalLayout_15);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        loginError = new QLabel(widget_12);
        loginError->setObjectName("loginError");
        loginError->setFont(font4);
        loginError->setStyleSheet(QString::fromUtf8("color:white;"));

        horizontalLayout_6->addWidget(loginError);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        to_signup_page_btn = new QPushButton(widget_12);
        to_signup_page_btn->setObjectName("to_signup_page_btn");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Ubuntu Mono")});
        font6.setPointSize(14);
        font6.setBold(true);
        to_signup_page_btn->setFont(font6);
        to_signup_page_btn->setStyleSheet(QString::fromUtf8("color:white;"));

        horizontalLayout_3->addWidget(to_signup_page_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_3);

        stackedWidget_main->addWidget(Login);

        verticalLayout_3->addWidget(stackedWidget_main);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget_main->setCurrentIndex(2);
        stackedWidget->setCurrentIndex(0);
        stackedWidget1->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        homeBtn->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        roomBtn->setText(QCoreApplication::translate("MainWindow", "Room", nullptr));
        inviteBtn->setText(QCoreApplication::translate("MainWindow", "Invite", nullptr));
        createNewRoomBtn->setText(QCoreApplication::translate("MainWindow", "Create new room", nullptr));
        joinRandomBtn->setText(QCoreApplication::translate("MainWindow", "Join random", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Jemmy", nullptr));
        pushButton_6->setText(QString());
        createNewRoomBtn1->setText(QCoreApplication::translate("MainWindow", "Create new room", nullptr));
        joinRandomBtn1->setText(QCoreApplication::translate("MainWindow", "Join random", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Ready!!!", nullptr));
        cancelBtn->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Full name", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Confirm password", nullptr));
        signup_btn->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        signUpError->setText(QString());
        to_login_page_btn->setText(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        login_btn->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        loginError->setText(QString());
        to_signup_page_btn->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
