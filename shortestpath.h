#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <QDialog>

namespace Ui {
class ShortestPath;
}

class ShortestPath : public QDialog
{
    Q_OBJECT

public:
    explicit ShortestPath(QWidget *parent = nullptr);
    ~ShortestPath();

private:
    Ui::ShortestPath *ui;
};

#endif // SHORTESTPATH_H
