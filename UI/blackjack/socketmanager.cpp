#include "socketmanager.h"

SocketManager::SocketManager(QObject *parent)
    : QObject{parent}
    , socket_(new QTcpSocket(this))
{
}

SocketManager& SocketManager::instance()
{
    static SocketManager instance;
    return instance;
}

SocketManager::~SocketManager()
{
    qDebug() << "Socket Manager destroyed.";
    socket_->close();
    delete socket_;    
}

QTcpSocket *SocketManager::socket() const
{
    return socket_;
}
