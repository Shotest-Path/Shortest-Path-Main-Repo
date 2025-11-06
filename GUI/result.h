#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>

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

private:
    Ui::Result *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // RESULT_H
