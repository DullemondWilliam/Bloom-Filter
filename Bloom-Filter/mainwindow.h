#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

public slots:
    void on_button_Compute_clicked();

private:
    Ui::MainWindow *ui;

    int numBits;
    int numHashed;
    int numElements;
};

#endif // MAINWINDOW_H
