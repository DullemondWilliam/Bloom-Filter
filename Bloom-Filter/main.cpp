#include "mainwindow.h"
#include "bloomfilter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    BloomFilter( 1000, 5 );

    return a.exec();
}
