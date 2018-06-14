#include <QFile>
#include "csvbuilder.h"

//Assuming data is entered linearly not logrithmicly
CSVBuilder::CSVBuilder()
{
}

void CSVBuilder::insertColomn( double head, QVector<double> m_colomn )
{
    m_xAxisLabel.push_back( head );
    m_data.push_back( m_colomn );
}

bool CSVBuilder::printToFile( QString fileName, QString Description, QString xaxis, QString yaxis, double minEntry, double maxEntry )
{
//    QFile file(fileName);
//    if( !file.open( QFile::WriteOnly ) )
//        return false;

//    //Populate y-axis
//    QVector<double> yAxisLabel;
//    double interval = (double)(maxEntry - minEntry) / ((double)m_data[0].length());
//    for( int i=0; i < m_data[0].length(); ++i )
//        yAxisLabel.push_back( minEntry + (interval * i) );


//    file.write( Description.toLocal8Bit() + "," + "\n" ); //Write Description
//    file.write( ",," + xaxis.toLocal8Bit() + "\n" );      //Write X-Axis Label

//    //Write X-Axis Values
//    QString line = ",,";
//    for( int i=0; i < m_xAxisLabel.length(); ++i )
//        line.append( QString::number(m_xAxisLabel.at(i)) + "," );

//    file.write( line.toLocal8Bit() + "\n" );

//    //Write First Line
//    line = yaxis + "," + QString::number( yAxisLabel[0] ) + ",";
//    for( int i=0; i < m_data.length(); ++i )
//        line.append( QString::number(m_data[0][i]) + "," );

//    file.write( line.toLocal8Bit() + "\n" );


//    for( int i=1; i < m_data.length(); ++i )
//    {
//        line = "," + QString::number( m_xAxisLabel[i] ) + ",";
//        for( int j=0; j < m_data[i].length(); ++j )
//            line.append( QString::number(m_data[j][i]) + "," );
//        file.write( line.toLocal8Bit() + "\n" );
//    }
//    file.close();
}

void CSVBuilder::clear()
{
    m_data.clear();
    m_xAxisLabel.clear();
}
