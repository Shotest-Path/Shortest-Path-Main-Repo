#include "pythonrunner.h"
#include <QDebug>
#include <QDir>

PythonRunner::PythonRunner(QObject *parent)
    : QObject(parent), process(new QProcess(this)), currentIndex(0),
    output(nullptr), labelOutput(nullptr)
{
    process->setProcessChannelMode(QProcess::MergedChannels);
    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        appendOutput(process->readAllStandardOutput());
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
    QString basePath = QDir::cleanPath(QDir::currentPath() + "../../../../Visualization");
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

void PythonRunner::runNext()
{
    if (currentIndex < scripts.size()) {
        QString script = scripts[currentIndex];
        QString msg = QString("> Running script %1 of %2: %3")
                          .arg(currentIndex + 1)
                          .arg(scripts.size())
                          .arg(script);

        appendOutput(msg);
        emit progressUpdate(msg);
        qDebug() << msg;

        process->setWorkingDirectory("../../../Visualization");

        if (script.contains("main_animation.py", Qt::CaseInsensitive)) {
            process->start("python3", QStringList()
                           << "-m" << "manim"
                           << "-qh"
                           << script
                           << "DijkstraVisualization");
        } else {
            process->start("python3", QStringList() << script);
        }
    } else {
        QString doneMsg = "All scripts finished! Video ready.";
        appendOutput(doneMsg);
        emit progressUpdate(doneMsg);
        emit allScriptsFinished();
        qDebug() << doneMsg;
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


