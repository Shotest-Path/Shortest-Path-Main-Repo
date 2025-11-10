#include "shortestpath.h"
#include "ui_shortestpath.h"
#include "result.h"
#include "ShortestPathAlgo-Dijstra.cpp"
#include "result.h"
#include <QTimer>
#include "exportResultFile.cpp"
#include <QMessageBox>
#include "pythonrunner.h"

using namespace std;
ShortestPath::ShortestPath(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShortestPath)
    , resultObject(new Result())
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
    if(ui->theEdgeLengthLineEdit->text()==""||ui->secondNodeNameLineEdit->text()==""||ui->fristNodeNameLineEdit->text()=="")
    {
        ui->fristNodeNameLineEdit->setPlaceholderText("you must Enter the frist node name");
        ui->secondNodeNameLineEdit->setPlaceholderText("you must Enter the second node name");
        ui->theEdgeLengthLineEdit->setPlaceholderText("you must Enter the edage length");
        QMessageBox::critical(nullptr, "Error", "you must Enter all feild");
    }
    else
    {
        ui->fristNodeNameLineEdit->setPlaceholderText("Enter the frist node name");
        ui->secondNodeNameLineEdit->setPlaceholderText("Enter the second node name");
        ui->theEdgeLengthLineEdit->setPlaceholderText("Enter the edage length");
        char fristNodeName=ui->fristNodeNameLineEdit->text().toStdString()[0];
        char SecandNode=ui->secondNodeNameLineEdit->text().toStdString()[0];
        double distance=ui->theEdgeLengthLineEdit->text().toDouble();
        ShortestPathGraph[fristNodeName][SecandNode]=distance;
        ShortestPathGraph[SecandNode][fristNodeName]=distance;
        ui->fristNodeNameLineEdit->setText("");
        ui->secondNodeNameLineEdit->setText("");
        ui->theEdgeLengthLineEdit->setText("");
    }
}
void ShortestPath::onRunClick()
{
    isConvexAndConcave=false;

    if(ui->startNodeLineEdit->text()==""||ui->endNodeLineEdit->text()=="")
    {
        QMessageBox::critical(nullptr, "Error", "you must add starting and end nodes");
    }
    else
    {
    startNode=ui->startNodeLineEdit->text().toStdString()[0];
    endNode=ui->endNodeLineEdit->text().toStdString()[0];

    dijkstra(
        ShortestPathGraph,
        startNode,
        endNode,
        distances,
        prev,
        shortest_path
        );

    for(auto i : shortest_path){
       shortestPathText += i + ' ';
    }
    double len = 0;
    for(auto element : distances){
        if(element.first==endNode)
            len = element.second;
    }
    shortestPathText+= (" => (" + to_string(len) + ")");

    exportResultFile(
        ShortestPathGraph,
        distances,
        prev,
        shortest_path
        );

    QString shortestPathTextGlobal =  QString::fromStdString(shortestPathText);

    time = new QTimer(this);
    time->start();

    // hide();
    resultObject->returnShortestPathResult(shortestPathTextGlobal);
    // resultObject->show();
    resultObject->startPythonRunner();

    time->stop();
    hide();
    resultObject->returnShortestPathResult(shortestPathTextGlobal);
    resultObject->show();
    }
}
