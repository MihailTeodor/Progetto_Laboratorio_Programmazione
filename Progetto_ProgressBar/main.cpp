#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "fileloader.h"
#include "bitprogressbar.h"
#include <QProgressBar>
#include<QHBoxLayout>
#include<QPushButton>
#include<mainwindow.h>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window=new QWidget;
    QPushButton *button= new QPushButton;
    FileLoader file;
    button->connect(button, SIGNAL(clicked(bool)), &file, SLOT(loadFiles()));
    QProgressBar *filesPercentage=new QProgressBar;
    QProgressBar *bitsPercentage=new QProgressBar;
    ProgressBar*pb1=new ProgressBar(&file);
    BitProgressBar* pb2=new BitProgressBar(&file);
    file.addFile("C:\\Users\\gurzu\\Desktop\\prova.txt");
    file.addFile("C:\\Users\\gurzu\\Desktop\\prova1.txt");
    button->connect(button, SIGNAL(clicked(bool)), &file, SLOT(loadFiles()));
    filesPercentage->setRange(0,100);
    bitsPercentage->setRange(0,100);
    filesPercentage->connect(pb1, SIGNAL (display(int)),filesPercentage, SLOT (setValue(int)));
    bitsPercentage->connect(pb2,SIGNAL(display(int)),bitsPercentage, SLOT(setValue(int)));
    QHBoxLayout* layout= new QHBoxLayout;
    layout->addWidget(filesPercentage);
    layout->addWidget(bitsPercentage);
    layout->addWidget(button);
    window->setLayout(layout);
    window->show();
    return a.exec();
}
