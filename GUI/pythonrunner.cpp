#include "pythonrunner.h"
#include <QDebug>
#include <QDir>

PythonRunner::PythonRunner(QObject *parent)
    : QObject(parent), process(new QProcess(this)), currentIndex(0),
    output(nullptr), labelOutput(nullptr)
{
    process->setProcessChannelMode(QProcess::MergedChannels);
    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        QByteArray data = process->readAllStandardOutput();
        QString output = QString::fromLocal8Bit(data);
        QStringList lines = output.split('\n', Qt::SkipEmptyParts);
        for (const QString &line : lines) {
            if (line.startsWith("PROGRESS:")) {
                QString progressStr = line.section(':', 1, 1).trimmed();
                bool ok;
                int progress = progressStr.toInt(&ok);
                if (ok) {
                    if (currentIndex < progressRanges.size()) {
                        int overallProgress = progressOffset + (progress * progressRanges[currentIndex] / 100);
                        emit progressChanged(overallProgress);
                    }
                }
            } else {
                appendOutput(line);
            }
        }
    });
    connect(process, &QProcess::readyReadStandardError, this, [this]() {
        appendOutput(process->readAllStandardError());
    });
    connect(process, &QProcess::finished, this, &PythonRunner::onFinished);
}

PythonRunner::PythonRunner(QPlainTextEdit *outputWidget, QObject *parent)
    : PythonRunner(parent)
{
    output = outputWidget;
}

void PythonRunner::start()
{
    currentProgress = 0;
    progressRanges = {0, 80, 20};
    progressOffset = 0;
    QString basePath = "E:/workspace/Geometry Project for windows/Shortest-Path-Main-Repo/Visualization";
    if(isConvexAndConcave==false)

    {
        scripts = {
            basePath + "/getdata.py",
            basePath + "/main_animation.py",
            basePath + "/removedata.py"
        };

        currentIndex = 0;
        appendOutput("Starting Python script sequence...");
        emit progressUpdate("Starting Python script sequence...");
        runNext();
    }
    else if(isConvexAndConcave==true)
    {
        scripts = {
            basePath + "/getdata_1.py",
            basePath + "/main_animation_1.py",
            basePath + "/removedata_1.py"
        };

        currentIndex = 0;
        appendOutput("Starting Python script sequence...");
        emit progressUpdate("Starting Python script sequence...");
        runNext();
    }
}

void PythonRunner::runNext()
{
    if(isConvexAndConcave==false){
        if (currentIndex < scripts.size()) {
            QString script = scripts[currentIndex];
            QString msg = QString("> Running script %1 of %2: %3")
                              .arg(currentIndex + 1)
                              .arg(scripts.size())
                              .arg(script);

            appendOutput(msg);
            emit progressUpdate(msg);
            qDebug() << msg;

            process->setWorkingDirectory(QFileInfo(script).absolutePath());

            if (script.contains("main_animation.py", Qt::CaseInsensitive)) {
                process->start("manim", QStringList()
                            << "-qh"
                            << "main_animation.py"
                            << "DynamicGraphScene");
            } else {
                process->start("python", QStringList() << script);
            }
        } else {
            QString doneMsg = "All scripts finished! Video ready.";
            appendOutput(doneMsg);
            emit progressUpdate(doneMsg);
            emit progressChanged(100);
            emit allScriptsFinished();
            qDebug() << doneMsg;
        }
    }
    else if(isConvexAndConcave==true){
        if (currentIndex < scripts.size()) {
            QString script = scripts[currentIndex];
            QString msg = QString("> Running script %1 of %2: %3")
                              .arg(currentIndex + 1)
                              .arg(scripts.size())
                              .arg(script);

            appendOutput(msg);
            emit progressUpdate(msg);
            qDebug() << msg;

            process->setWorkingDirectory(QFileInfo(script).absolutePath());

            if (script.contains("main_animation_1.py", Qt::CaseInsensitive)) {
                process->start("manim", QStringList()
                               << "-qh"
                               << "main_animation_1.py"
                               << "DynamicGraphScene");
            } else {
                process->start("python", QStringList() << script);
            }
        } else {
            QString doneMsg = "All scripts finished! Video ready.";
            appendOutput(doneMsg);
            emit progressUpdate(doneMsg);
            emit progressChanged(100);
            emit allScriptsFinished();
            qDebug() << doneMsg;
        }
    }
}

void PythonRunner::onFinished(int exitCode, QProcess::ExitStatus status)
{
    Q_UNUSED(status)
    QString msg = QString("Script %1 finished (exit code %2)")
                      .arg(currentIndex + 1)
                      .arg(exitCode);
    appendOutput(msg);
    emit progressUpdate(msg);

    if (currentIndex < progressRanges.size()) {
        progressOffset += progressRanges[currentIndex];
    }

    currentIndex++;
    runNext();
}

void PythonRunner::appendOutput(const QString &text)
{
    if (text.trimmed().isEmpty()) return;

    if (output) {
        output->appendPlainText(text.trimmed());
        output->moveCursor(QTextCursor::End);
    }

    if (labelOutput) {
        labelOutput->setText(labelOutput->text() + "\n" + text.trimmed());
    }
}

