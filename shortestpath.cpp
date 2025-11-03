#include "shortestpath.h"
#include "ui_shortestpath.h"

ShortestPath::ShortestPath(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShortestPath)
{
    ui->setupUi(this);
}

ShortestPath::~ShortestPath()
{
    delete ui;
}
