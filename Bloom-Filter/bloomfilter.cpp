#include "bloomfilter.h"
#include "math.h"
#include <QDebug>
#include <qmath.h>
#include "bitset"
#include "MurmurHash3.h"

namespace
{
const int numberOfBits = 32; // 4 294 967 296
}

BloomFilter::BloomFilter( int numBits, int numHash ):
    m_numBits( numBits ),
    m_numHash( numHash ),
    m_numElements( 0 )
{
    qInfo() << " Number of Storage bits: " << m_numBits;
    qInfo() << " Number of Hash bits: " << m_numHash;

    m_filter = QBitArray( m_numBits, 0 );

    m_fraction = m_numBits / qPow (2,numberOfBits);
//    //Create K Hashes Seeds
//    QByteArray seed;
//    for( int i=0; i < m_numHash; ++i )
//    {
//        m_hashSeeds.append(QCryptographicHash::hash( seed.setNum( i ), QCryptographicHash::Md4 ) );
//    }
}

BloomFilter::~BloomFilter()
{
}

bool BloomFilter::testElement( const QString& test )
{
    uint32_t num;

    // Create K hashes
    for( int i=0; i < m_numHash; ++i )
    {
        MurmurHash3_x86_32( test.toLocal8Bit().data(), test.size(), i, &num );

        double index = m_fraction * num;

        if( !m_filter.at( qFloor( index ) ) )
            return false;

    }
    return true;
}

bool BloomFilter::addElement( const QString& add )
{
    bool included = true;
    uint32_t num;

    // Create K hashes
    for( int i=0; i < m_numHash; ++i )
    {
        MurmurHash3_x86_32( add.toLocal8Bit().data(), add.size(), i, &num );

        uint32_t index = qFloor( m_fraction * num );

      //  qDebug() << index;

        if( !m_filter.at( index  ) )
        {
            m_filter.setBit( index );
            included = false;
        }
    }
    return included;
}

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

