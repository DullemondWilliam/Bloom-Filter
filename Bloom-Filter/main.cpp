#include "mainwindow.h"
#include "bloomfilter.h"
#include "csvbuilder.h"
#include "MurmurHash3.h"
#include "StorageManager.h"

#include <QApplication>
#include <QDebug>
#include <QtMath>


int main(int argc, char *argv[])
{

    BloomFilter bloomFilter(10000, 3);

    for(int i=0; i<1000; ++i)
        bloomFilter.addElement(QString::number(i));

    bloomFilter.writeToFile("/home/tcu001/Desktop/BloomFilter.bf");


    bloomFilter.readFromFile("/home/tcu001/Desktop/BloomFilter.bf");


//    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

//    qDebug() << "end";
//    return a.exec();

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//    for( int j = 2; j<500; ++j )
//    {
//        CountBloomFilter bf(10000000 , j);

//        uint64_t error = 0;
//        for( int i=0; i<1000000; ++i )
//        {
//            if( bf.addElement( QString::number( i ) ) )
//                error ++;

//            if( !(i % 100000))
//                qDebug() << "   " << i << " - " << error;
//        }

//        qDebug() << j << "-" << error;
//    }


    //    uint32_t result1;
    //    uint32_t result2;
    //    char* result3 = (char*) malloc( 16 );

    //    QString t("test");

    //    char* test1 = "test1";
    //    char* test = "test";

    //    qDebug() << result1 << " =+= " << result2;

    ////    qDebug() << result1;
    //    MurmurHash3_x86_128( test1,5,12, &result1);
    //    MurmurHash3_x86_128( test,4,12, &result2);

    //    qDebug() << result1 << " =+= " << result2;

//    CSVBuilder builder;

//    int numberOfColumns = 50;
//    int numberOfRows    = 100;

//    int N_elements = 1;
//    int M_bits     = 1;
//    int K_hashes   = 1;

//    int N_MAX_elements = 1000000;
//    int M_MAX_bits     = 10000;
//    int K_MAX_hashes   = 100;
    ///////////////////////////////////////////////////////////////////////////
    // "False positive rate over N where N=1,000,000 M=50,000 and K as a fraction of M",
    // N = 1,000,000 M = 50,000 K = [1-M]

    //    N_elements = 1;
    //    M_bits     = 1;
    //    K_hashes   = 1;

    //    for( int i=1; i<=numberOfColumns; ++i ) //Number of columns (different values of K)
    //    {
    //        BloomFilter bf( 50000, (i / 50.0) * 50000  );
    //        QVector<double> column;
    //        double errors = 0;
    //        for( int j=0; j< numberOfRows; ++j ) //Number of rows (fraction of N)
    //        {
    //            for( int a=0; a<1000; ++a)
    //            {
    //                if( bf.addElement( QString::number( j*1000 + a ) ) )
    //                    errors++;
    //            }
    //            column.append( errors );
    //            qDebug() << errors;
    //        }
    //        builder.insertColomn( i * (1.0/50.0), column );
    //    }

    //    builder.printToFile( "C:\\Users\\William\\Desktop\\K_to_Error.csv",
    //                         "False positive rate over N where N=1,000,000 M=50,000 and K as a fraction of M",
    //                         "Number of Hashes(K)", "Number of Elements", 1000, 1000000 );
    //    builder.clear();
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // [N,M] "False positive rate over N, N=1,000,000 K as a set fraction of M, M being a fraction of N",
    // N = 1-1,000,000 M =1-1000 K = (M/N)ln2

    //    QVector<QPair<double>> M_K [ QPair<double>( )];

    //    for( int i=1; i<=50; ++i ) //Number of columns (different values of K)
    //    {
    //        BloomFilter bf( 50000, 50000 );
    //        QVector<double> column;
    //        double errors = 0;
    //        for( int j=0; j<1000000/1000; ++j ) //Number of rows (fraction of N)
    //        {
    //            for( int a=0; a<1000; ++a)
    //            {
    //                if( bf.addElement( QString::number( j*1000 + a ) ) )
    //                    errors++;
    //            }
    //            column.append( errors );
    //            qDebug() << errors;
    //        }
    //        builder.insertColomn( i * (1.0/50.0), column );
    //    }

    //    builder.printToFile( "C:\\Users\\William\\Desktop\\K_to_Error.csv",
    //                         "False positive rate over N, N=1,000,000 K as a set fraction of M, M being a fraction of N",
    //                         "Number of Bits(K)", "Number of Elements", 1000, 1000000 );
    //    builder.clear();
    ///////////////////////////////////////////////////////////////////////////




}
