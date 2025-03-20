#include "canbus.h"
#include <QDebug>

CanBus::CanBus(QObject *parent) : QObject(parent), socket(new QUdpSocket(this)) {
    setupSocket();
}

CanBus::~CanBus() {
    delete socket;
}

void CanBus::setupSocket() {
    if (!socket->bind(QHostAddress::Any, 0, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
        qWarning() << "Failed to bind socket";
        return;
    }

    connect(socket, &QUdpSocket::readyRead, this, &CanBus::readPacket);
}

void CanBus::readPacket() {
    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());

        qDebug() << "Received packet of size:" << datagram.size();
        qDebug() << datagram.toHex();  // Виводимо дані у вигляді HEX
    }
}
