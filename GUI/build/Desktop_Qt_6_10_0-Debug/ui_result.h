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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Result
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_4;
    QPushButton *playButton;
    QVBoxLayout *verticalLayout;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QSpacerItem *horizontalSpacer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *pythonOutputConsole;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLabel *shortestPathResultLabel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Result)
    {
        if (Result->objectName().isEmpty())
            Result->setObjectName("Result");
        Result->resize(1100, 900);
        Result->setMinimumSize(QSize(1100, 900));
        gridLayoutWidget = new QWidget(Result);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 50, 1051, 691));
        gridLayout_4 = new QGridLayout(gridLayoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        playButton = new QPushButton(gridLayoutWidget);
        playButton->setObjectName("playButton");

        gridLayout_4->addWidget(playButton, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 2);

        pauseButton = new QPushButton(gridLayoutWidget);
        pauseButton->setObjectName("pauseButton");

        gridLayout_4->addWidget(pauseButton, 1, 0, 1, 1);

        stopButton = new QPushButton(gridLayoutWidget);
        stopButton->setObjectName("stopButton");

        gridLayout_4->addWidget(stopButton, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_4->addItem(horizontalSpacer, 4, 0, 1, 2);

        horizontalLayoutWidget = new QWidget(Result);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 740, 1051, 151));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pythonOutputConsole = new QPlainTextEdit(horizontalLayoutWidget);
        pythonOutputConsole->setObjectName("pythonOutputConsole");
        pythonOutputConsole->setReadOnly(true);

        horizontalLayout->addWidget(pythonOutputConsole);

        horizontalLayoutWidget_3 = new QWidget(Result);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(210, 10, 601, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName("label");

        horizontalLayout_4->addWidget(label);

        shortestPathResultLabel = new QLabel(horizontalLayoutWidget_3);
        shortestPathResultLabel->setObjectName("shortestPathResultLabel");

        horizontalLayout_4->addWidget(shortestPathResultLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        horizontalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(Result);

        QMetaObject::connectSlotsByName(Result);
    } // setupUi

    void retranslateUi(QDialog *Result)
    {
        Result->setWindowTitle(QCoreApplication::translate("Result", "Dialog", nullptr));
        playButton->setText(QCoreApplication::translate("Result", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("Result", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("Result", "Stop", nullptr));
        label->setText(QCoreApplication::translate("Result", "Shortest Path: ", nullptr));
        shortestPathResultLabel->setText(QCoreApplication::translate("Result", "Shortest Path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Result: public Ui_Result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
