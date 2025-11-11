#include "result.h"
#include "ui_result.h"
#include "shortestpath.cpp"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QPropertyAnimation>
#include "pythonrunner.h"


Result::Result(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Result)
{
    ui->setupUi(this);

    ui->pythonOutputConsole->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->pythonOutputConsole->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->progressBar->setStyleSheet("QProgressBar { color: white; } QProgressBar::chunk { background-color: blue; }");

    QString shortestPathTextGlobal = Result::shortestPathResult;
    ui->shortestPathResultLabel->setText(shortestPathTextGlobal);

    pythonRunner = new PythonRunner(ui->pythonOutputConsole, this);
    connect(pythonRunner, &PythonRunner::allScriptsFinished, this, &Result::onVideoReady);
    connect(pythonRunner, &PythonRunner::progressChanged, this, &Result::onProgressChanged);

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    ui->verticalLayout->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);

    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
}

void Result::onVideoReady() {
    QString base_videoPath ="C:/Users/Hp/OneDrive/Documents/4th Year/1st Term/Comp 411 Computational Geometry/Project/Visualization/media/videos";

    if(isConvexAndConcave==false)
        {
        QString videoPath_1 = base_videoPath + "/main_animation/1080p60/DynamicGraphScene.mp4";

        if (!QFile::exists(videoPath_1)) {
            qDebug() << "Video not found at:" << videoPath_1;
            return;
        }

        player->setSource(QUrl::fromLocalFile(videoPath_1));
        player->play();
    }
    else if(isConvexAndConcave==true)
    {
        QString videoPath_2 = base_videoPath + "/main_animation_1/1080p60/DynamicGraphScene.mp4";

        if (!QFile::exists(videoPath_2)) {
            qDebug() << "Video not found at:" << videoPath_2;
            return;
        }

        player->setSource(QUrl::fromLocalFile(videoPath_2));
        player->play();
    }
}

Result::~Result()
{
    delete ui;
}

QString Result::returnShortestPathResult(QString shortestPathRes){
    shortestPathResult = shortestPathRes;
    ui->shortestPathResultLabel->setText(shortestPathRes);
    return shortestPathRes;
}

void Result::startPythonRunner() {
    if (pythonRunner) {
        pythonRunner->start();
    }
}

void Result::onProgressChanged(int value)
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->progressBar, "value");
    animation->setDuration(500);
    animation->setStartValue(ui->progressBar->value());
    animation->setEndValue(value);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

