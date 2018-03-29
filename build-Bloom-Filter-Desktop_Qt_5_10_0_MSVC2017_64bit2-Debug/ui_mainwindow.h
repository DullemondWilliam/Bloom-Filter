/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *text_NumBits;
    QLineEdit *text_NumHashes;
    QLineEdit *text_Elements;
    QLineEdit *text_ProbCollision;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QPushButton *button_Compute;
    QLabel *Label;
    QFrame *frame;
    QLabel *label_ui;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 131, 241));
        text_NumBits = new QLineEdit(groupBox);
        text_NumBits->setObjectName(QStringLiteral("text_NumBits"));
        text_NumBits->setGeometry(QRect(10, 30, 113, 20));
        text_NumHashes = new QLineEdit(groupBox);
        text_NumHashes->setObjectName(QStringLiteral("text_NumHashes"));
        text_NumHashes->setGeometry(QRect(10, 70, 113, 20));
        text_Elements = new QLineEdit(groupBox);
        text_Elements->setObjectName(QStringLiteral("text_Elements"));
        text_Elements->setGeometry(QRect(10, 110, 113, 20));
        text_ProbCollision = new QLineEdit(groupBox);
        text_ProbCollision->setObjectName(QStringLiteral("text_ProbCollision"));
        text_ProbCollision->setGeometry(QRect(10, 210, 113, 20));
        text_ProbCollision->setFrame(true);
        text_ProbCollision->setReadOnly(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 190, 71, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 111, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 91, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 16));
        button_Compute = new QPushButton(groupBox);
        button_Compute->setObjectName(QStringLiteral("button_Compute"));
        button_Compute->setGeometry(QRect(20, 150, 75, 23));
        Label = new QLabel(groupBox);
        Label->setObjectName(QStringLiteral("Label"));
        Label->setGeometry(QRect(140, 20, 241, 211));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(140, 20, 241, 221));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_ui = new QLabel(frame);
        label_ui->setObjectName(QStringLiteral("label_ui"));
        label_ui->setGeometry(QRect(10, 10, 221, 201));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QApplication::translate("MainWindow", "Collison Prob", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Estamated Elements ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Number of Hashes", nullptr));
        label->setText(QApplication::translate("MainWindow", "Number of Bits", nullptr));
        button_Compute->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
        Label->setText(QString());
        label_ui->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
