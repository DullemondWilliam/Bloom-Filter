#include "bloomfilter.h"
#include <QDebug>

BloomFilter::BloomFilter( int numBits, int numHash ):
    m_numBits( numBits ),
    m_numHash( numHash ),
    m_numElements( 0 )
{
    m_byteArray = QByteArray( m_numBits, 0 );
    m_saltArray = QList<QByteArray>();

    m_totalSize = pow( 2, m_numBits );
    m_sectionSize = floor( m_totalSize / m_numHash );

    for( int i=0; i < numHash; ++i )
    {
        m_saltArray.append( QCryptographicHash::hash( (QString::number(1000+i).toLocal8Bit()),
                                             QCryptographicHash::Algorithm::Md4 ));
        qDebug( m_saltArray.at( i ) );
    }
}

BloomFilter::~BloomFilter()
{
}

bool BloomFilter::testElement( QString add )
{
}

int BloomFilter::bitToCheck( int a, QByteArray array )
{
    QByteArray finalValue;
    for( int i=0; i < array.length(); ++i )
    {

    }

    return floor( finalValue / m_sectionSize );
}
