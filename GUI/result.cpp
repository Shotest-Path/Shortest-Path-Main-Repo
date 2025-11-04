#include "result.h"
#include "ui_result.h"
#include "shortestpath.cpp"

Result::Result(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Result)
{
    ui->setupUi(this);
    QString shortestPathTextGlobal = Result::shortestPathResult;
    ui->shortestPathResultLabel->setText(shortestPathTextGlobal);
}

Result::~Result()
{
    delete ui;
}

QString Result::returnShortestPathResult(QString shortestPathRes){
    shortestPathResult = shortestPathRes;
    return shortestPathRes;
}
