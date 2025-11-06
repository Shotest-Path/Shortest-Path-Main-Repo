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

    QString shortestPathTextGlobal = Result::shortestPathResult;
    ui->shortestPathResultLabel->setText(shortestPathTextGlobal);
    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    ui->verticalLayout->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);
    // TODO : change this path
    QString path = "../../../Visualization/media/videos/P1/1080p60/DijkstraVisualization.mp4";
    // QString file = QFileDialog::getOpenFileName(this, "Open Video");

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
