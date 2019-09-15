#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "progressbar.h"
#include "bitprogressbar.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // connect(pb1, SIGNAL (display(int)),ui->fileProgressBar, SLOT (setValue(int)))

}

MainWindow::~MainWindow()
{
    delete ui;
}






