#ifndef NETWORKDATA_H
#define NETWORKDATA_H

#include <QByteArray>
#include <QDataStream>

// Typy wiadomości w protokole
enum class MessageType : uint8_t {
    ConfigSync = 1,      // Przesyłanie pełnej konfiguracji JSON
    SimStep_U = 2,       // Regulator wysyła sygnał sterujący U do Obiektu
    SimStep_Y = 3,       // Obiekt odsyła sygnał wyjściowy Y do Regulatora
    SimControl = 4       // Start/Stop/Reset
};

// Struktura ramki protokołu
struct NetworkFrame {
    MessageType type;
    QByteArray payload;

    // Serializacja do wysłania przez socket
    static QByteArray serialize(MessageType t, const QByteArray& data) {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);
        out << (uint32_t)0; // Miejsce na rozmiar
        out << (uint8_t)t;
        out << data;
        out.device()->seek(0);
        out << (uint32_t)(block.size() - sizeof(uint32_t));
        return block;
    }
};
#endif
