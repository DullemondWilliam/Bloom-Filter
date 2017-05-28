#include "bloomfilter.h"
#include "math.h"
#include <QDebug>

BloomFilter::BloomFilter( int numBits, int numHash ):
    m_numBits( numBits ),
    m_numHash( numHash ),
    m_numElements( 0 )
{
    m_byteArray = QByteArray( ceil( (double)m_numBits/8.0 ), 0 );
    m_sectionSize = floor(  pow( 2, m_numBits ) / m_numHash );
}

BloomFilter::~BloomFilter()
{
}

bool BloomFilter::testElement( QString test )
{
    QByteArray elementHash = QCryptographicHash::hash( test.toLocal8Bit(), QCryptographicHash::Md4 );

    for( int i=0; i < m_numHash; ++i )
    {
        int bit = bitToCheck( i, elementHash );
        qDebug() << bit;
        bit = bit % 8;
        char bitMask = pow( 2, bit );
        int section = floor( ((double)bit)/8.0 );

        char element = m_byteArray.at( section );

        if( !(element & bitMask) )
        {
            return false;
        }
    }
    return true;
}

bool BloomFilter::addElement( QString add )
{
    QByteArray elementHash = QCryptographicHash::hash( add.toLocal8Bit(), QCryptographicHash::Md4 );

    for( int i=0; i < m_numHash; ++i )
    {
        int bit = bitToCheck( i, elementHash );
        bit = bit % 8;
        char bitMask = pow( 2, bit );
        int section = floor( ((double)bit)/8.0 );

        char element = m_byteArray.at( section );
        element = element | bitMask;
        m_byteArray.insert( i, element );
    }
    return true;
}

int BloomFilter::bitToCheck( int hashNumber, QByteArray array )
{
    QByteArray finalValue;

    for( char i=0; i < array.length(); ++i )
    {
        finalValue.append( array.at( i ) ^ i );
    }

    return floor( finalValue.toDouble() / m_sectionSize );
}
