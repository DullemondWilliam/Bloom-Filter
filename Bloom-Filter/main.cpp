#include "mainwindow.h"
#include "bloomfilter.h"
#include <QApplication>
#include <QDebug>
#include <QtMath>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BloomFilter bf = BloomFilter( 2000, 2 );


    bf.addElement( "123456789" );
    bf.addElement( "12" );

    for( int i=0; i<500; ++i )
        bf.addElement( QString::number(i) );

    qDebug() << bf.testElement( "123456789" );
    qDebug() << bf.testElement( "123456789" );

    qDebug() << bf.testElement( "abcdefghi" );

//    bf.printFilter();

    return a.exec();
}
