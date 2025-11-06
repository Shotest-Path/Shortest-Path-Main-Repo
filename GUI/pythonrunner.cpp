#include "pythonrunner.h"

PythonRunner::PythonRunner(QObject *parent)
    : QObject(parent), process(new QProcess(this)), currentIndex(0)
{
    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        qDebug() << process->readAllStandardOutput();
    });

    connect(process, &QProcess::readyReadStandardError, this, [this]() {
        qDebug() << process->readAllStandardError();
    });

    connect(process, &QProcess::finished, this, &PythonRunner::onFinished);
}

void PythonRunner::start() {
    scripts = {
        "/media/windows/workspace/My_Apps/Geometry/GUI/Visualization/get_data.py",
        "/media/windows/workspace/My_Apps/Geometry/GUI/Visualization/main_animation.py",
        "/media/windows/workspace/My_Apps/Geometry/GUI/Visualization/remove_data.py"
    };
    runNext();
}

void PythonRunner::runNext() {
    if (currentIndex < scripts.size()) {
        QString currentScript = scripts[currentIndex];
        qDebug() << "Running script:" << currentScript;
        process->start("python3", QStringList() << currentScript);
    } else {
        qDebug() << "All scripts finished!";
    }
}

void PythonRunner::onFinished(int exitCode, QProcess::ExitStatus status) {
    Q_UNUSED(status)
    qDebug() << "Script finished with code:" << exitCode;
    currentIndex++;
    runNext();
}
