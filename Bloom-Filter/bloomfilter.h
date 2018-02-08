#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <QList>
#include <QDebug>
#include <QByteArray>
#include <QCryptographicHash>

class BloomFilter
{
public:
    BloomFilter( int numBits, int numHash );
    ~BloomFilter();

    bool testElement( QString test );
    bool addElement( QString add );

    bool checkBit( int bit);
    void setBit( int bit );

    QByteArray xorByteArray( QByteArray a1, QByteArray a2 );

private:

    QVector<char> m_filter;
    QVector<QByteArray> m_hashSeeds;

    int m_numBits;
    int m_numHash;
    int m_numElements;
    double m_sectionSize;
};

#endif // BLOOMFILTER_H
