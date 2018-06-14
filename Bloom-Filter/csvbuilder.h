#ifndef CSVBUILDER_H
#define CSVBUILDER_H

#include <QVector>

class CSVBuilder
{
public:
    CSVBuilder();

    void insertColomn( double head, QVector<double> m_colomn );
    bool printToFile( QString fileName, QString Description, QString xaxis, QString yaxis, double minEntry, double maxEntry );

    void clear();

private:
    double m_minEntry;
    double m_maxEntry;

    QVector<double> m_xAxisLabel;

    QVector< QVector<double> > m_data;
};

#endif // CSVBUILDER_H
