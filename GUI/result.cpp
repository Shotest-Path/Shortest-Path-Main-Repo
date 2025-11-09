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
    pythonRunner = new PythonRunner(ui->pythonOutputConsole, this);
    connect(pythonRunner, &PythonRunner::allScriptsFinished, this, &Result::onVideoReady);

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    ui->verticalLayout->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);

    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
}    void Result::onVideoReady()
    {
        QString videoPath = QDir::cleanPath(QCoreApplication::applicationDirPath() +
                                            "/../../../../Visualization/media/videos/main_animation/1080p60/DynamicGraphScene.mp4");
    
        if (!QFile::exists(videoPath)) {
            qDebug() << "Video not found at:" << videoPath;
            return;
        }
    
        player->setSource(QUrl::fromLocalFile(videoPath));
        player->play();
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

