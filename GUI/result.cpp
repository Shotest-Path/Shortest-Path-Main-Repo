#include "result.h"
#include "ui_result.h"
#include "shortestpath.cpp"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>

Result::Result(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Result)
{
    ui->setupUi(this);

    ui->pythonOutputConsole->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->pythonOutputConsole->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QString shortestPathTextGlobal = Result::shortestPathResult;
    ui->shortestPathResultLabel->setText(shortestPathTextGlobal);
    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    pythonRunner = new PythonRunner(ui->pythonOutputConsole, this);
    connect(pythonRunner, &PythonRunner::allScriptsFinished, this, []() {
        qDebug() << "Python scripts completed successfully!";
    });

    ui->verticalLayout->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);

    QString path = "../../../Visualization/media/videos/main_animation/720p30/DijkstraVisualization.mp4";

    if (!path.isEmpty()) {
        player->setSource(QUrl::fromLocalFile(path));
        player->play();
    }

    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton , &QPushButton::clicked, player, &QMediaPlayer::stop);
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

