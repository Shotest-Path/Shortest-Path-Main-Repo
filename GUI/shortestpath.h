#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <QDialog>
#include <map>
#include <vector>
#include "result.h"
#include <QTime>
#include "pythonrunner.h"
using namespace std;

namespace Ui {
class ShortestPath;
}

class ShortestPath : public QDialog
{
    Q_OBJECT

public:
    explicit ShortestPath(QWidget *parent = nullptr);
    ~ShortestPath();
    map<char,map<char,double>> ShortestPathGraph;
    char startNode,endNode;
    map<char, double> distances;
    map<char, char> prev;
    vector<char> shortest_path;
    string shortestPathText;

private slots:
    void onAddNodeClick();
    void onRunClick();
private:
    Ui::ShortestPath *ui;
    Result *resultObject;
    QTimer *time;
    PythonRunner pythonRunRunRun;
};

#endif // SHORTESTPATH_H
