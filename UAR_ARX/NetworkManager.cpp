#include "NetworkManager.h"
#include <QHostAddress>

NetworkManager::NetworkManager(QObject *parent) : QObject(parent), currentRole(NetworkRole::Stationary), blockSize(0)
{
    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);

    connect(tcpServer, &QTcpServer::newConnection, this, &NetworkManager::onNewConnection);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &NetworkManager::onReadyRead);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &NetworkManager::onDisconnected);
    connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &NetworkManager::onError);
    connect(tcpSocket, &QTcpSocket::connected, this, [this]() {
        emit connectionEstablished(tcpSocket->peerAddress().toString());
    });

}

void NetworkManager::startAsServer(quint16 port)
{
    disconnectNetwork();
    if (tcpServer->listen(QHostAddress::Any, port)) {
        currentRole = NetworkRole::Controller;
    } else {
        emit errorOccurred("Nie udało się uruchomić serwera: " + tcpServer->errorString());
    }
}

void NetworkManager::connectToServer(const QString &ip, quint16 port)
{
    disconnectNetwork();
    currentRole = NetworkRole::Object;
    tcpSocket->connectToHost(ip, port);
}

void NetworkManager::disconnectNetwork()
{
    if (tcpServer->isListening())
        tcpServer->close();

    if (tcpSocket) {

        tcpSocket->disconnect();

        tcpSocket->disconnectFromHost();
        tcpSocket->deleteLater();
        tcpSocket = new QTcpSocket(this);


        connect(tcpSocket, &QTcpSocket::readyRead, this, &NetworkManager::onReadyRead);
        connect(tcpSocket, &QTcpSocket::disconnected, this, &NetworkManager::onDisconnected);
        connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &NetworkManager::onError);
        connect(tcpSocket, &QTcpSocket::connected, this, [this]() {
            emit connectionEstablished(tcpSocket->peerAddress().toString());
        });
    }

    currentRole = NetworkRole::Stationary;
    blockSize = 0;
}
void NetworkManager::onNewConnection()
{

    if (tcpSocket && tcpSocket->state() != QAbstractSocket::UnconnectedState) {
        tcpSocket->disconnectFromHost();
        tcpSocket->waitForDisconnected(100);
        tcpSocket->deleteLater();
    }

    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    tcpSocket = clientSocket;

    connect(tcpSocket, &QTcpSocket::readyRead, this, &NetworkManager::onReadyRead);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &NetworkManager::onDisconnected);
    connect(tcpSocket, &QTcpSocket::errorOccurred, this, &NetworkManager::onError);

    blockSize = 0;

    emit connectionEstablished("Połączono z obiektem: " + tcpSocket->peerAddress().toString());
}
void NetworkManager::onReadyRead()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_6_0);

    while (!in.atEnd()) {
        if (blockSize == 0) {
            if (tcpSocket->bytesAvailable() < (qint64)sizeof(quint32))
                return;
            in >> blockSize;
        }

        if (tcpSocket->bytesAvailable() < blockSize)
            return;

        QByteArray data;
        in >> data;
        emit dataReceived(data);
        blockSize = 0;
    }
}

void NetworkManager::sendData(const QByteArray &data)
{
    if (!tcpSocket || tcpSocket->state() != QAbstractSocket::ConnectedState) return;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << (quint32)data.size();
    out << data;

    tcpSocket->write(block);
}

void NetworkManager::onDisconnected()
{
    emit connectionLost();
}

void NetworkManager::setStationaryMode()
{
    currentRole = NetworkRole::Stationary;
}
void NetworkManager::onError(QAbstractSocket::SocketError socketError)
{
    emit errorOccurred(tcpSocket->errorString());
}
