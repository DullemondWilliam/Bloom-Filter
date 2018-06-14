#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <QByteArray>
#include <QBitArray>

class StorageManager
{
    public:
        static QByteArray bitToByte( const QBitArray& data );
        static QBitArray byteToBit( const QByteArray& data );

        static bool saveToFile( const QByteArray& data, const QString& filename );
        static QByteArray readFromFile( const QString& filename );

};

#endif // STORAGEMANAGER_H
