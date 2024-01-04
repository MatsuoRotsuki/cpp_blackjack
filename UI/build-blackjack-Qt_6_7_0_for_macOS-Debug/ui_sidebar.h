/********************************************************************************
** Form generated from reading UI file 'sidebar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEBAR_H
#define UI_SIDEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QFormLayout *formLayout;
    QWidget *menu_widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *homeBtn;
    QPushButton *roomBtn;
    QPushButton *inviteBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(400, 485);
        formLayout = new QFormLayout(Form);
        formLayout->setObjectName("formLayout");
        menu_widget = new QWidget(Form);
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


        formLayout->setWidget(0, QFormLayout::LabelRole, menu_widget);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "Menu", nullptr));
        homeBtn->setText(QCoreApplication::translate("Form", "Home", nullptr));
        roomBtn->setText(QCoreApplication::translate("Form", "Room", nullptr));
        inviteBtn->setText(QCoreApplication::translate("Form", "Invite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEBAR_H
