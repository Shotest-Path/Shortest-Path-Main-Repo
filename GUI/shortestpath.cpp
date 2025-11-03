#include "shortestpath.h"
#include "ui_shortestpath.h"
#include "result.h"

ShortestPath::ShortestPath(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShortestPath)
    ,resultObject(new Result())
{
    ui->setupUi(this);
    connect(ui->addNodeButton,&QPushButton::clicked,this,&ShortestPath::onAddNodeClick);
    connect(ui->runButton,&QPushButton::clicked,this,&ShortestPath::onRunClick);
    ui->fristNodeNameLineEdit->setPlaceholderText("Enter the frist node name");
    ui->secondNodeNameLineEdit->setPlaceholderText("Enter the second node name");
    ui->theEdgeLengthLineEdit->setPlaceholderText("Enter the edage length");
    ui->startNodeLineEdit->setPlaceholderText("Enter the starting node name");
    ui->endNodeLineEdit->setPlaceholderText("Enter the ending node name");
}

ShortestPath::~ShortestPath()
{
    delete ui;
}
void ShortestPath::onAddNodeClick()
{

    char fristNodeName=ui->fristNodeNameLineEdit->text().toStdString()[0];
    char SecandNode=ui->secondNodeNameLineEdit->text().toStdString()[0];
    double yCoordinate=ui->theEdgeLengthLineEdit->text().toDouble();
    ShortestPathGraph[fristNodeName][SecandNode]=yCoordinate;
    ui->fristNodeNameLineEdit->setText("");
    ui->secondNodeNameLineEdit->setText("");
    ui->theEdgeLengthLineEdit->setText("");
}
void ShortestPath::onRunClick()
{
    startNode=ui->startNodeLineEdit->text().toStdString()[0];
    endNode=ui->endNodeLineEdit->text().toStdString()[0];
    hide();
    resultObject->show();
}
