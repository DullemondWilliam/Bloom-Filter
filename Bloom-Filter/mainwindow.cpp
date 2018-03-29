#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "bloomfilter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timerFire()));

    QIntValidator val;
    val.setBottom(0);
    ui->text_NumBits->setValidator( &val );

    ui->text_NumBits->setText("100000");
    ui->text_NumHashes->setText("4");
    ui->text_Elements->setText("100000");

    m_image = new QImage(ui->frame->width(),ui->frame->height(), QImage::Format_RGB32 );
    m_image->fill(QColor("yellow"));
    ui->label_ui->setPixmap(QPixmap::fromImage(*m_image));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_Compute_clicked()
{
    qDebug()<< "Compute Button Clicked";
    int m = ui->text_NumBits->text().toInt();
    int k = ui->text_NumHashes->text().toInt();
    int n = ui->text_Elements->text().toInt();

    startBloomFilter( m, k, n );

//    float prob = (1-(( (1-( 1/m ))^(k*n)) ))^k;
//    setProbCollision( prob );
}

void MainWindow::timerFire()
{

    for(int i=0; i<m_bloomFilter->m_numBits && i<(m_image->width()*m_image->height()); ++i)
    {
        int x = i % m_image->width();
        int y = i / m_image->width();

        if( m_bloomFilter->m_filter.at(i) )
            m_image->setPixelColor( x, y, 1 );
        else
            m_image->setPixelColor( x, y, QColor("yellow") );
    }
    ui->label_ui->setPixmap(QPixmap::fromImage(*m_image));
}

void MainWindow::setProbCollision( float prob )
{
//    QString output = QString::number( prob );
//    output.append( '%' );
//    ui->text_ProbCollision->setText( output );
}

void MainWindow::startBloomFilter( int bits, int hashes, int elements )
{
    m_image = new QImage(ui->frame->width(),ui->frame->height(), QImage::Format_ARGB32 );
    m_image->fill(255);

    // m_timer->setInterval(1000);
    // m_timer->start();

    m_bloomFilter = new BloomFilter( bits, hashes );

    m_image->fill(QColor(0,0,0,0));
    ui->label_ui->setPixmap(QPixmap::fromImage(*m_image));

    int collisions = 0;
    for(int i=0; i<elements; ++i)
    {
        collisions += m_bloomFilter->addElement( QString::number(i) );
    }

    ui->text_Collisions->setText( QString::number(collisions) + " : (" +
                                  QString::number(((float)collisions/(float)elements)*100) + "%)" );
    timerFire();

    qDebug() << "DONE";
    //m_timer->stop();
}
