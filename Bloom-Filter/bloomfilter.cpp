#include "bloomfilter.h"
#include "math.h"
#include <QDebug>
#include <qmath.h>
#include "bitset"
BloomFilter::BloomFilter( int numBits, int numHash ):
    m_numBits( numBits ),
    m_numHash( numHash ),
    m_numElements( 0 )
{
    qInfo() << " Number of Storage bits: " << m_numBits;
    qInfo() << " Number of Hash bits: " << m_numHash;

    m_filter = QBitArray( m_numBits, 0 );

    //Create K Hashes Seeds
    QByteArray seed;
    for( int i=0; i < m_numHash; ++i )
    {
        m_hashSeeds.append(QCryptographicHash::hash( seed.setNum( i ), QCryptographicHash::Md4 ) );
        qDebug() << m_hashSeeds.last();
    }
}

BloomFilter::~BloomFilter()
{
}

bool BloomFilter::testElement( QString test )
{
    // Hash Element
    QByteArray elementHash = QCryptographicHash::hash( test.toLocal8Bit(), QCryptographicHash::Md4 );

    // Create K hashes
    for( int i=0; i < m_numHash; ++i )
    {
        // Create seeded Hash
        QByteArray seededhash = xorByteArray( elementHash, m_hashSeeds[i] );

        // Convert to a number between 0 - numBits
        // Determine most number of bits
        int a = qLn( m_numBits+1 ) / qLn( 2 );




    }
    return true;
}

bool BloomFilter::addElement( QString add )
{
    QByteArray elementHash = QCryptographicHash::hash( add.toLocal8Bit(), QCryptographicHash::Md4 );

    for( int i=0; i < m_numHash; ++i )
    {
        int bit ;//= checkBit\( i, elementHash );
        bit = bit % 8;
        char bitMask = pow( 2, bit );
        int section = floor( ((double)bit)/8.0 );

//        char element = m_filter.at( section );
//        element = element | bitMask;
//        m_filter.insert( i, element );
    }
    return true;
}

QByteArray BloomFilter::xorByteArray( QByteArray a1, QByteArray a2 )
{
    for( int i=0; i < qMin( a1.length(), a2.length() ); ++i )
    {
        a1[i] = (a1[i] ^ a2[i]);
    }

    return a1;
}

double BloomFilter::hashToNumber( QByteArray a1 )
{
    double number = 0;
    for(int i=0; i<a1.length(); ++i)
    {
        double num = 0;
        num += ((unsigned char) a1.at( i )) * qPow(2,(8*i));
        number += num;
        qDebug() << fixed<< number << " ____ " << (unsigned char) a1.at( i ) << "_____" << num;
    }

    return number;
}

