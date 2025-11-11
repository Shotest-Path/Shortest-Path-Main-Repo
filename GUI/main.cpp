#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon appIcon(":/icons/app.ico");
    QApplication::setWindowIcon(appIcon);

    a.setStyleSheet(R"(
        QMainWindow, QDialog {
            background-image: url(:/icons/icons/background.jpg);
            background-repeat: no-repeat;
            background-position: center;
            background-attachment: fixed;
        }
    )");

    MainWindow w;
    w.setWindowTitle("Shortest Path Algorithm");
    w.show();

    return a.exec();
}
