#ifndef CONVEXANDCONCAVE_H
#define CONVEXANDCONCAVE_H

#include <QDialog>

namespace Ui {
class ConvexAndConcave;
}

class ConvexAndConcave : public QDialog
{
    Q_OBJECT

public:
    explicit ConvexAndConcave(QWidget *parent = nullptr);
    ~ConvexAndConcave();

private:
    Ui::ConvexAndConcave *ui;
};

#endif // CONVEXANDCONCAVE_H
