#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_Compute_clicked()
{
    int m = ui->text_NumBits->text().toInt();
    int k = ui->text_NumHashes->text().toInt();
    int n = ui->text_Elements->text().toInt();

    float prob = (1-(( (1-( 1/m ))^(k*n)) ))^k;

    setProbCollision( prob );

}

void MainWindow::setProbCollision( float prob )
{
    QString output = QString::number( prob );
    output.append( '%' );
    ui->text_ProbCollision->setText( output );
}
