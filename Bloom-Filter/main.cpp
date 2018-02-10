#include "mainwindow.h"
#include "bloomfilter.h"
#include <QApplication>
#include <QDebug>
#include <QtMath>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    BloomFilter bf = BloomFilter( 64, 2 );

    qDebug()<< sizeof(long long);

//    bf.setBit( 10 );
//    bf.setBit( 60 );
//    bf.setBit( 21 );
//    bf.setBit( 40 );

//    qDebug() << bf.checkBit( 9 );
//    qDebug() << bf.checkBit( 60 );
//    qDebug() << bf.checkBit( 21 );
//    qDebug() << bf.checkBit( 55 );

//    qDebug() << QCryptographicHash::hash( "Information3", QCryptographicHash::Md4 );
//    qDebug() << QCryptographicHash::hash( "Information3", QCryptographicHash::Md4 );
//    qDebug() << QCryptographicHash::hash( "Informa1tion3", QCryptographicHash::Md4 );



   // qDebug() << bf.hashToNumber( QCryptographicHash::hash( "Information3", QCryptographicHash::Md4 ) );
    //qDebug() << bf.hashToNumber( QCryptographicHash::hash( "Information2", QCryptographicHash::Md4 ) );
    qDebug() << bf.hashToNumber( QCryptographicHash::hash( "Information1", QCryptographicHash::Md4 ) );

//    bf.addElement( "Dan" );
//    qDebug() << bf.testElement("Dan");
//    qDebug() << bf.testElement("LLd");



    //return a.exec();
}
