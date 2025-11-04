#ifndef CONVEXANDCONCAVE_H
#define CONVEXANDCONCAVE_H

#include <QDialog>
<<<<<<< HEAD
#include <map>
#include "result.h"

using namespace std;
=======
>>>>>>> 25b247ca2b94fe8ced1facdc69006b9e4e42179e
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
