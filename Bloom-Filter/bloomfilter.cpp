#include "bloomfilter.h"
#include "math.h"
#include <QDebug>
#include <qmath.h>
#include "bitset"
#include "MurmurHash3.h"

namespace
{
const int numberOfBits = 56; // 4 294 967 296
}

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

        // Hash Number
        qint64 num = hashToNumber( seededhash );

        // Convert to a number between 0 - numBits
        double fraction = m_numBits / qPow(2,numberOfBits); // 2^48

        fraction *= num;

        if( !m_filter.at( qFloor( fraction ) ) )
            return false;

    }
    return true;
}

bool BloomFilter::addElement( QString add )
{
    bool out = true;

    // Hash Element
    QByteArray elementHash = QCryptographicHash::hash( add.toLocal8Bit(), QCryptographicHash::Md4 );

    // Create K hashes
    for( int i=0; i < m_numHash; ++i )
    {
        // Create seeded Hash
        QByteArray seededhash = xorByteArray( elementHash, m_hashSeeds[i] );

        // Hash Number
        qint64 num = hashToNumber( seededhash );

        // Convert to a number between 0 - numBits
        double fraction = m_numBits / qPow(2,numberOfBits); // 2^48

        fraction *= num;

        if( m_filter.testBit( ( qFloor( fraction ) ) ) )
            out = false;

        m_filter.setBit( ( qFloor( fraction ) ) );
    }
    return out;
}

//uint32 stringToHash( QString str )
//{
//    QByteArray arr = str.toLocal8Bit();
//    for( int i=0; i < arr.size(); ++i )
//    {
//       // MurmurHash3_x86_32(  arr.at( i ), );
//    }
//}

QByteArray BloomFilter::xorByteArray( const QByteArray& a1, const QByteArray& a2 )
{
    QByteArray array ( a1 );
    for( int i=0; i < qMin( a1.length(), a2.length() ); ++i )
        array[i] = array[i] ^ a2[i];

    return array;
}

quint64 BloomFilter::hashToNumber( const QByteArray& a1 )
{
    //Note: number is capped at 64 bits
    quint64 number = 0;

    for(int i=0; i<a1.length() && i<numberOfBits/8; ++i)
        number += ((unsigned char) a1.at( i )) * qPow(2,(8*i));

    return number;
}

void BloomFilter::printFilter()
{
    for( int i=m_numBits-1 ; i >= 0 ; --i )
    {
        if( m_filter.at( i ) )
            printf( "1" );
        else
            printf( "0" );
    }
    printf( "\n" );
}

