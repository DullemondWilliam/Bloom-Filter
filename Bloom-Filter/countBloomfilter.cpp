#include "CountBloomFilter.h"
#include "math.h"
#include <QDebug>
#include <qmath.h>
#include "bitset"

namespace
{
const int numberOfBits = 32;
}

CountBloomFilter::CountBloomFilter( int numBits, int numHash ):
    m_numBits( numBits ),
    m_numHash( numHash ),
    m_numElements( 0 )
{
    qInfo() << " Number of Storage bits: " << m_numBits;
    qInfo() << " Number of Hash bits: " << m_numHash;

    m_filter = QByteArray( m_numBits, 0 );

    //Create K Hashes Seeds
    QByteArray seed;
    for( int i=m_numHash*-1; i <0; ++i )
    {
        m_hashSeeds.append(QCryptographicHash::hash( seed.setNum( i ), QCryptographicHash::Md4 ) );
    }
}

CountBloomFilter::~CountBloomFilter()
{
}

int CountBloomFilter::testElement( QString test )
{
    // Hash Element
    QByteArray elementHash = QCryptographicHash::hash( test.toLocal8Bit(), QCryptographicHash::Md4 );

    int lowestNumber;

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

        int spot = m_filter[ qFloor( fraction ) ];
        if( spot == 0 )
            return 0;
        lowestNumber = qMin( lowestNumber, spot );
    }
    return lowestNumber;
}

int CountBloomFilter::addElement( QString add )
{
    // Hash Element
    QByteArray elementHash = QCryptographicHash::hash( add.toLocal8Bit(), QCryptographicHash::Md4 );

    int out = 0;
    QString item;
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

        item.append( QString::number(qFloor(fraction)) +", ");

        out = qMin( out, (int) m_filter.at( qFloor( fraction ) ) );

        m_filter[ qFloor( fraction ) ] = m_filter.at( qFloor( fraction ) ) + 1 ;
    }
    qDebug() << item;
    return out;
}

int CountBloomFilter::removeElement( QString remove )
{
    // Hash Element
    QByteArray elementHash = QCryptographicHash::hash( remove.toLocal8Bit(), QCryptographicHash::Md4 );

    int out = 0;
    QString item;
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

        out = qMin( out, (int) m_filter.at( qFloor( fraction ) ) );
        item.append( QString::number(qFloor(fraction)) +", ");

        m_filter[ qFloor( fraction ) ] = m_filter.at( qFloor( fraction ) ) - 1 ;
    }
    qDebug() << item;
    return out -1 ;
}

QByteArray CountBloomFilter::xorByteArray( const QByteArray& a1, const QByteArray& a2 )
{
    QByteArray array ( a1 );
    for( int i=0; i < qMin( a1.length(), a2.length() ); ++i )
        array[i] = (array[i] ^ a2[i]);

    return array;
}

quint64 CountBloomFilter::hashToNumber( const QByteArray& a1 )
{
    //Note: number is capped at 64 bits
    quint64 number = 0;

    for(int i=0; i<a1.length() && i<numberOfBits/8; ++i)
        number += ((unsigned char) a1.at( i )) * qPow(2,(8*i));

    return number;
}

void CountBloomFilter::printFilter()
{
    qDebug() << "here" << m_numBits;
    QString out;
    for( int i=m_numBits-1 ; i >= 0 ; --i )
        out.append(QString::number( (int) m_filter[i]) + "," );
    qDebug() << out;
}

