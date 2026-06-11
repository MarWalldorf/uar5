#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>

// Definicja roli aplikacji w sieci
enum class NetworkRole {
    Stationary,
    Controller,
    Object
};

class NetworkManager : public QObject
{
    Q_OBJECT

public:
    explicit NetworkManager(QObject *parent = nullptr);

    void startAsServer(quint16 port);
    void connectToServer(const QString &ip, quint16 port);
    void disconnectNetwork();
    void sendData(const QByteArray &data);
    void setStationaryMode();
    NetworkRole getCurrentRole() const { return currentRole; }

signals:
    void dataReceived(QByteArray data);
    void connectionEstablished(QString info);
    void connectionLost();
    void errorOccurred(QString errorMsg);

private slots:
    void onNewConnection();
    void onReadyRead();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    NetworkRole currentRole;
    quint32 blockSize;
};

#endif // NETWORKMANAGER_H
