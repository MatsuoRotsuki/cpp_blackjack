/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Card
{
public:

    void setupUi(QWidget *Card)
    {
        if (Card->objectName().isEmpty())
            Card->setObjectName("Card");
        Card->resize(191, 236);

        retranslateUi(Card);

        QMetaObject::connectSlotsByName(Card);
    } // setupUi

    void retranslateUi(QWidget *Card)
    {
        Card->setWindowTitle(QCoreApplication::translate("Card", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Card: public Ui_Card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H
