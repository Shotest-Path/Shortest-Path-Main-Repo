#ifndef CONVEXANDCONCAVE_H
#define CONVEXANDCONCAVE_H

#include <QDialog>
#include <map>
#include "result.h"

using namespace std;
namespace Ui {
class ConvexAndConcave;
}

class ConvexAndConcave : public QDialog
{
    Q_OBJECT

public:
    explicit ConvexAndConcave(QWidget *parent = nullptr);
    ~ConvexAndConcave();
    map<char ,pair<double,double>> thePoitsOfHoleGraph;
    char startPoint,endPoint;
private slots:
    void onAddPointClick();
    void onRunConvexAndConcaveClick();
private:
    Ui::ConvexAndConcave *ui;
    Result *resultObject;
};

#endif // CONVEXANDCONCAVE_H
