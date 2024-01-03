#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QThread>
#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>
#include "message.h"
#include <string.h>

class WorkerThread : public QThread {
public:
    void run() override {
        QTcpSocket socket;
        socket.connectToHost("127.0.0.1", 5500);

        if (socket.waitForConnected(3000)) {
            qDebug() << "Connected to server";
            socket.write("Hello from client");

            if (socket.waitForReadyRead())
            {
                QByteArray data = socket.read(sizeof(Message));
                const Message* msgPtr = reinterpret_cast<const Message*>(data.constData());
                Message msg;
                memcpy(&msg, msgPtr, sizeof(Message));

                qDebug() << strlen(msg.payload.invalidRequestData.message);

                socket.close();
            }
        } else {
            qDebug() << "Connection failed";
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "blackjack_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();

    WorkerThread workerThread;
    workerThread.start();

    return a.exec();
}
