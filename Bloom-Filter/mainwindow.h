#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bloomfilter.h"
#include "QTimer"
#include "QImage"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setProbCollision( float prob );

    void startBloomFilter( int bits, int hashes, int elements );

public slots:
    void on_button_Compute_clicked();

    void timerFire();

private:
    Ui::MainWindow *ui;

    int numBits;
    int numHashed;
    int numElements;

    int m_imageWidth;
    QImage* m_image;

    QTimer* m_timer;
    BloomFilter* m_bloomFilter;



};

#endif // MAINWINDOW_H
