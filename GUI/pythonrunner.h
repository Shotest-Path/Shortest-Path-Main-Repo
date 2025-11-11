#ifndef PYTHONRUNNER_H
#define PYTHONRUNNER_H

#include <QObject>
#include <QProcess>
#include <QPlainTextEdit>
#include <QLabel>
#include <QStringList>


inline bool isConvexAndConcave =false;
class PythonRunner : public QObject {
    Q_OBJECT

public:
    explicit PythonRunner(QObject *parent = nullptr);
    explicit PythonRunner(QPlainTextEdit *outputWidget, QObject *parent = nullptr);
    void start();

signals:
    void progressUpdate(const QString &message);
    void allScriptsFinished();
    void progressChanged(int value);

private slots:
    void runNext();
    void onFinished(int exitCode, QProcess::ExitStatus status);

private:
    void appendOutput(const QString &text);

    QProcess *process;
    QStringList scripts;
    int currentIndex;
    QPlainTextEdit *output;
    QLabel *labelOutput;
    QList<int> progressRanges;
    int progressOffset;
    int currentProgress;
};

#endif // PYTHONRUNNER_H
