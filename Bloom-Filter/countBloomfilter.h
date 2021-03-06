#ifndef COUNTBLOOMFILTER_H
#define COUNTBLOOMFILTER_H

#include <QList>
#include <QDebug>
#include <QByteArray>
#include <QBitArray>
#include <QCryptographicHash>
#include "MurmurHash3.h"

class CountBloomFilter
{
public:
    CountBloomFilter( int numBits, int numHash );
    ~CountBloomFilter();

    int testElement( QString test );
    int addElement( QString add );
    int removeElement( QString remove );

    QByteArray xorByteArray( const QByteArray& a1, const QByteArray& a2 );
    quint64 hashToNumber( const QByteArray& a1 );
    void  printFilter();
    bool writeToFile( const QString& filename );
    bool readFromFile( const QString& filename );

private:

    QByteArray m_filter;
    QVector<QByteArray> m_hashSeeds;

    int m_numBits;
    int m_numHash;
    int m_numElements;

    double m_sectionSize;
    double m_fraction;
};

#endif // COUNTBLOOMFILTER_H
