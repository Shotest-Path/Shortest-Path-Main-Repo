#ifndef PYTHONRUNNER_H
#define PYTHONRUNNER_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class PythonRunner : public QObject {
    Q_OBJECT

public:
    explicit PythonRunner(QObject *parent = nullptr);

    void start();

private slots:
    void runNext();
    void onFinished(int exitCode, QProcess::ExitStatus status);

private:
    QProcess *process;
    QStringList scripts;
    int currentIndex;
};

#endif // PYTHONRUNNER_H
