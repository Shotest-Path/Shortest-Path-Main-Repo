#include "convexandconcave.h"
#include "ui_convexandconcave.h"
#include <QErrorMessage>
#include <QMessageBox>
#include "ConvexAndConCaveDrawAlgo.cpp"
#include "shortestpath.h"
#include "ShortestPathAlgo-Dijstra.cpp"

ConvexAndConcave::ConvexAndConcave(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConvexAndConcave)
    ,resultObject(new Result())
{
    ui->setupUi(this);
    connect(ui->addPointButton,&QPushButton::clicked,this,&ConvexAndConcave::onAddPointClick);
    connect(ui->runConvexAndConcaveButton,&QPushButton::clicked,this,&ConvexAndConcave::onRunConvexAndConcaveClick);
    ui->pointNameLineEdit->setPlaceholderText("Enter the point name");
    ui->xCoordinateLineEdit->setPlaceholderText("Enter the x Coordinate");
    ui->yCoordinateLineEdit->setPlaceholderText("Enter the y Coordinate");
    ui->startPointLineEdit->setPlaceholderText("Enter the starting point name");
    ui->endPointLineEdit->setPlaceholderText("Enter the ending point name");
}
void ConvexAndConcave::onAddPointClick()
{
    if(ui->pointNameLineEdit->text()==""||ui->xCoordinateLineEdit->text()==""||ui->yCoordinateLineEdit->text()=="")
    {
        ui->pointNameLineEdit->setPlaceholderText("you must enter point name");
        ui->xCoordinateLineEdit->setPlaceholderText("you must Enter the x Coordinate");
        ui->yCoordinateLineEdit->setPlaceholderText("you must Enter the y Coordinate");
        QMessageBox::critical(nullptr, "Error", "you must Enter all feild");
    }
    else
    {
        ui->pointNameLineEdit->setPlaceholderText("Enter the point name");
        ui->xCoordinateLineEdit->setPlaceholderText("Enter the x Coordinate");
        ui->yCoordinateLineEdit->setPlaceholderText("Enter the y Coordinate");
        char pointName =ui->pointNameLineEdit->text().toStdString()[0];
        double xCoordinate =ui->xCoordinateLineEdit->text().toDouble();
        double yCoordinate =ui->yCoordinateLineEdit->text().toDouble();
        thePoitsOfHoleGraph[pointName].first=xCoordinate;
        thePoitsOfHoleGraph[pointName].second=yCoordinate;
        ui->pointNameLineEdit->setText("");
        ui->xCoordinateLineEdit->setText("");
        ui->yCoordinateLineEdit->setText("");
    }

}

void ConvexAndConcave::onRunConvexAndConcaveClick()
{


    if(ui->startPointLineEdit->text()==""||ui->endPointLineEdit->text()=="")
    {
        QMessageBox::critical(nullptr, "Error", "you must add starting and end points");
    }
    else
    {
        startPoint=ui->startPointLineEdit->text().toStdString()[0];
        endPoint=ui->endPointLineEdit->text().toStdString()[0];
        if(ui->concaveRadioButton->isChecked())
        {
            Polygon theGivenGraph;
            ShortestPath theFinalpath;
            theGivenGraph.GetConcave(thePoitsOfHoleGraph);
            theFinalpath.ShortestPathGraph=theGivenGraph.Edges;
            dijkstra
                (
                    theFinalpath.ShortestPathGraph,
                    startPoint,
                    endPoint,
                    theFinalpath.distances,
                    theFinalpath.prev,
                    theFinalpath.shortest_path
                    );
            hide();
            resultObject->show();
        }
        else if(ui->convexRadioButton->isChecked())
        {
            Polygon theGivenGraph;
            ShortestPath theFinalpath;
            theFinalpath.ShortestPathGraph=theGivenGraph.GetConvex(thePoitsOfHoleGraph);
            dijkstra
                (
                theFinalpath.ShortestPathGraph,
                startPoint,
                endPoint,
                theFinalpath.distances,
                theFinalpath.prev,
                theFinalpath.shortest_path
                );
            hide();
            resultObject->show();
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "An unselectead polgon Type error occurred!");
        }

    }
}
ConvexAndConcave::~ConvexAndConcave()
{
    delete ui;
}
