#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <QList>
#include <QDebug>
#include <QByteArray>
#include <QBitArray>
#include <QCryptographicHash>

class BloomFilter
{
public:
    BloomFilter( int numBits, int numHash );
    ~BloomFilter();

    bool testElement( QString test );
    bool addElement( QString add );

    QByteArray xorByteArray( const QByteArray& a1, const QByteArray& a2 );
    quint64 hashToNumber( const QByteArray& a1 );
    void  printFilter();

private:

    QBitArray m_filter;
    QVector<QByteArray> m_hashSeeds;

    int m_numBits;
    int m_numHash;
    int m_numElements;
    double m_sectionSize;
};

#endif // BLOOMFILTER_H
