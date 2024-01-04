#include "socketmanager.h"

SocketManager *SocketManager::instance_ = nullptr;

SocketManager::SocketManager(QObject *parent)
    : QObject{parent}
    , socket_(new QTcpSocket(this))
{
}

SocketManager *SocketManager::GetInstance()
{
    if (!instance_) {
        instance_ = new SocketManager();
    }

    return instance_;
}

SocketManager::~SocketManager()
{
    socket_->close();
    delete socket_;
    delete instance_;
    qDebug() << "Socket Manager destroyed.";
}

QTcpSocket *SocketManager::socket() const
{
    return socket_;
}
