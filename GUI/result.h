#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPropertyAnimation>
#include "pythonrunner.h"

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
    QString returnShortestPathResult(QString shortestPathRes);
    QString shortestPathResult;
    void startPythonRunner();

private slots:
    void onVideoReady();
    void onProgressChanged(int value);

private:
    Ui::Result *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    PythonRunner *pythonRunner;
};

#endif // RESULT_H
