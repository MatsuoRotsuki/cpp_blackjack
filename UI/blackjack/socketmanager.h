#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class SocketManager : public QObject
{
    Q_OBJECT
public:
    static SocketManager& instance();
    QTcpSocket *socket() const;

signals:

public slots:

private:
    SocketManager(QObject *parent = nullptr);
    ~SocketManager();
    QTcpSocket *socket_;
    Q_DISABLE_COPY(SocketManager)
};

#endif // SOCKETMANAGER_H
