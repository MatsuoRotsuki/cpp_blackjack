QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    inviteplayerdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    onlineplayer.cpp \
    message.cpp \
    player.cpp \
    playwindow.cpp \
    quitdialog.cpp \
    roomitemwidget.cpp \
    socketmanager.cpp

HEADERS += \
    card.h \
    inviteplayerdialog.h \
    mainwindow.h \
    onlineplayer.h \
    player.h \
    playwindow.h \
    quitdialog.h \
    roomitemwidget.h \
    message.h \
    socketmanager.h

FORMS += \
    card.ui \
    inviteplayerdialog.ui \
    mainwindow.ui \
    onlineplayer.ui \
    player.ui \
    playwindow.ui \
    quitdialog.ui \
    roomitemwidget.ui \
    sidebar.ui

TRANSLATIONS += \
    blackjack_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    A_h.qrc
