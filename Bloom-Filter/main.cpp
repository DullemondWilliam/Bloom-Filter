#include "mainwindow.h"
#include "bloomfilter.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    BloomFilter bf = BloomFilter( 10, 2 );

    bf.addElement( "Dan" );
    qDebug() << bf.testElement("Dan");
    qDebug() << bf.testElement("LLd");



    //return a.exec();
}
