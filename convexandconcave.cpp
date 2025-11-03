#include "convexandconcave.h"
#include "ui_convexandconcave.h"

ConvexAndConcave::ConvexAndConcave(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConvexAndConcave)
{
    ui->setupUi(this);
}

ConvexAndConcave::~ConvexAndConcave()
{
    delete ui;
}
