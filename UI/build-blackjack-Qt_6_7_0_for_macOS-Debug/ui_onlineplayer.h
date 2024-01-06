/********************************************************************************
** Form generated from reading UI file 'onlineplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEPLAYER_H
#define UI_ONLINEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OnlinePlayer
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *avatar;
    QLabel *username;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *OnlinePlayer)
    {
        if (OnlinePlayer->objectName().isEmpty())
            OnlinePlayer->setObjectName("OnlinePlayer");
        OnlinePlayer->resize(245, 74);
        OnlinePlayer->setMaximumSize(QSize(300, 300));
        horizontalLayout = new QHBoxLayout(OnlinePlayer);
        horizontalLayout->setObjectName("horizontalLayout");
        avatar = new QLabel(OnlinePlayer);
        avatar->setObjectName("avatar");
        avatar->setMinimumSize(QSize(50, 50));
        avatar->setMaximumSize(QSize(50, 50));
        avatar->setSizeIncrement(QSize(50, 50));
        avatar->setTextFormat(Qt::PlainText);
        avatar->setPixmap(QPixmap(QString::fromUtf8(":/resource/avater.png")));
        avatar->setScaledContents(true);
        avatar->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(avatar);

        username = new QLabel(OnlinePlayer);
        username->setObjectName("username");

        horizontalLayout->addWidget(username);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(OnlinePlayer);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(50, 0));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 178, 255);\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(OnlinePlayer);

        QMetaObject::connectSlotsByName(OnlinePlayer);
    } // setupUi

    void retranslateUi(QWidget *OnlinePlayer)
    {
        OnlinePlayer->setWindowTitle(QCoreApplication::translate("OnlinePlayer", "Form", nullptr));
        avatar->setText(QString());
        username->setText(QCoreApplication::translate("OnlinePlayer", "Bryan", nullptr));
        pushButton->setText(QCoreApplication::translate("OnlinePlayer", "Invite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlinePlayer: public Ui_OnlinePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEPLAYER_H
