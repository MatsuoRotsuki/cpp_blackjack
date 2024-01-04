#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class SocketManager : public QObject
{
    Q_OBJECT
public:
    static SocketManager *GetInstance();
    ~SocketManager();
    QTcpSocket *socket() const;

signals:

public slots:

private:
    SocketManager(QObject *parent = nullptr);
    static SocketManager *instance_;
    QTcpSocket *socket_;
};

#endif // SOCKETMANAGER_H
