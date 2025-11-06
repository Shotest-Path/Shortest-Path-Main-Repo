/********************************************************************************
** Form generated from reading UI file 'result.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Result
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_4;
    QPushButton *pauseButton;
    QVBoxLayout *verticalLayout;
    QPushButton *playButton;
    QPushButton *stopButton;
    QLabel *shortestPathResultLabel;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;

    void setupUi(QDialog *Result)
    {
        if (Result->objectName().isEmpty())
            Result->setObjectName("Result");
        Result->resize(1100, 900);
        Result->setMinimumSize(QSize(1100, 900));
        gridLayoutWidget = new QWidget(Result);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 150, 1051, 691));
        gridLayout_4 = new QGridLayout(gridLayoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pauseButton = new QPushButton(gridLayoutWidget);
        pauseButton->setObjectName("pauseButton");

        gridLayout_4->addWidget(pauseButton, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 2);

        playButton = new QPushButton(gridLayoutWidget);
        playButton->setObjectName("playButton");

        gridLayout_4->addWidget(playButton, 1, 1, 1, 1);

        stopButton = new QPushButton(gridLayoutWidget);
        stopButton->setObjectName("stopButton");

        gridLayout_4->addWidget(stopButton, 3, 1, 1, 1);

        shortestPathResultLabel = new QLabel(Result);
        shortestPathResultLabel->setObjectName("shortestPathResultLabel");
        shortestPathResultLabel->setGeometry(QRect(530, 80, 113, 24));
        horizontalLayoutWidget_2 = new QWidget(Result);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(386, 80, 137, 26));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");

        horizontalLayout_4->addLayout(horizontalLayout_5);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName("label");

        horizontalLayout_4->addWidget(label);


        retranslateUi(Result);

        QMetaObject::connectSlotsByName(Result);
    } // setupUi

    void retranslateUi(QDialog *Result)
    {
        Result->setWindowTitle(QCoreApplication::translate("Result", "Dialog", nullptr));
        pauseButton->setText(QCoreApplication::translate("Result", "Pause", nullptr));
        playButton->setText(QCoreApplication::translate("Result", "Play", nullptr));
        stopButton->setText(QCoreApplication::translate("Result", "Stop", nullptr));
        shortestPathResultLabel->setText(QCoreApplication::translate("Result", "Shortest Path", nullptr));
        label->setText(QCoreApplication::translate("Result", "Shortest Path: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Result: public Ui_Result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
