#include "convexandconcave.h"
#include "ui_convexandconcave.h"

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
    char pointName =ui->pointNameLineEdit->text().toStdString()[0];
    double xCoordinate =ui->xCoordinateLineEdit->text().toDouble();
    double yCoordinate =ui->yCoordinateLineEdit->text().toDouble();
    thePoitsOfHoleGraph[pointName].first=xCoordinate;
    thePoitsOfHoleGraph[pointName].second=yCoordinate;
    ui->pointNameLineEdit->setText("");
    ui->xCoordinateLineEdit->setText("");
    ui->yCoordinateLineEdit->setText("");
}

void ConvexAndConcave::onRunConvexAndConcaveClick()
{
    startPoint=ui->startPointLineEdit->text().toStdString()[0];
    endPoint=ui->endPointLineEdit->text().toStdString()[0];
    hide();
    resultObject->show();
}
ConvexAndConcave::~ConvexAndConcave()
{
    delete ui;
}
