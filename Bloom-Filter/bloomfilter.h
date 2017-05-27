#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <QList>
#include <QByteArray>
#include <QCryptographicHash>

class BloomFilter
{
    public:
        BloomFilter( int numBits, int numHash );
        ~BloomFilter();

        bool testElement( QString add );
        bool addElement( QString add );

    private:
        int bitToCheck( int a, QByteArray array );

        QByteArray m_byteArray;
        QList<QByteArray> m_saltArray;

        int m_numBits;
        int m_numHash;
        int m_numElements;

        double m_totalSize;
        double m_sectionSize;
};

#endif // BLOOMFILTER_H
