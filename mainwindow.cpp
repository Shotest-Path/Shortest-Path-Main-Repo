#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shortestpath.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , shortestPathObject (new ShortestPath())
    , convexAndConcave (new ConvexAndConcave() )
{
    ui->setupUi(this);
    connect(ui->shortestPathButton ,&QPushButton::clicked,this, &MainWindow::showShortestPathWindow );
    connect(ui->convexAndConcaveButton ,&QPushButton::clicked,this, &MainWindow::showConvexAndConcaveWindow );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showShortestPathWindow(){
    hide();
    shortestPathObject->show();
}

void MainWindow::showConvexAndConcaveWindow(){
    hide();
    convexAndConcave->show();
}
