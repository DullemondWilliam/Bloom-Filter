#include "StorageManager.h"
#include <QFile>
#include <QDebug>

QByteArray StorageManager::bitToByte( const QBitArray& bits )
{
    QByteArray bytes;
    bytes.resize((bits.count()/8));
    bytes.fill(0);

    for(int b=0; b<bits.count()/8; ++b)
    {
        for(int i=0; i<8; ++i)
        {
            bytes[b] = bytes[b] | (bits[(b*8)+i] << (8-(i + 1)));
        }
    }
    return bytes;
}

QBitArray StorageManager::byteToBit( const QByteArray& bytes )
{
    QBitArray bits(bytes.size()*8);
    for(int i=0; i<bytes.size(); ++i)
        for(int b=0; b<8; ++b)
            bits.setBit(i*8 + b, bytes.at(i) & (1 << (7-b)));


    return bits;
}

bool StorageManager::saveToFile( const QByteArray& data, const QString& filename )
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    bool out = file.write(data);
    file.close();
    return out;
}

QByteArray StorageManager::readFromFile( const QString& filename )
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QByteArray out = file.readAll();
    file.close();
    return out;
}
