/********************************************************************************
** Form generated from reading UI file 'convexandconcave.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVEXANDCONCAVE_H
#define UI_CONVEXANDCONCAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConvexAndConcave
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *startPointLineEdit;
    QLabel *label_3;
    QPushButton *runConvexAndConcaveButton;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *pointNameLineEdit;
    QLineEdit *xCoordinateLineEdit;
    QLineEdit *endPointLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QLineEdit *yCoordinateLineEdit;
    QPushButton *addPointButton;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *concaveRadioButton;
    QRadioButton *convexRadioButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ConvexAndConcave)
    {
        if (ConvexAndConcave->objectName().isEmpty())
            ConvexAndConcave->setObjectName("ConvexAndConcave");
        ConvexAndConcave->resize(1005, 326);
        gridLayout_3 = new QGridLayout(ConvexAndConcave);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        startPointLineEdit = new QLineEdit(ConvexAndConcave);
        startPointLineEdit->setObjectName("startPointLineEdit");
        startPointLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout_2->addWidget(startPointLineEdit, 1, 2, 1, 1);

        label_3 = new QLabel(ConvexAndConcave);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_3, 1, 3, 1, 1);

        runConvexAndConcaveButton = new QPushButton(ConvexAndConcave);
        runConvexAndConcaveButton->setObjectName("runConvexAndConcaveButton");
        runConvexAndConcaveButton->setMinimumSize(QSize(200, 60));
        runConvexAndConcaveButton->setStyleSheet(QString::fromUtf8("background-color: gray\n"
";\n"
""));

        gridLayout_2->addWidget(runConvexAndConcaveButton, 11, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        pointNameLineEdit = new QLineEdit(ConvexAndConcave);
        pointNameLineEdit->setObjectName("pointNameLineEdit");
        pointNameLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout_2->addWidget(pointNameLineEdit, 3, 2, 1, 1);

        xCoordinateLineEdit = new QLineEdit(ConvexAndConcave);
        xCoordinateLineEdit->setObjectName("xCoordinateLineEdit");
        xCoordinateLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout_2->addWidget(xCoordinateLineEdit, 3, 3, 1, 1);

        endPointLineEdit = new QLineEdit(ConvexAndConcave);
        endPointLineEdit->setObjectName("endPointLineEdit");
        endPointLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout_2->addWidget(endPointLineEdit, 1, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 10, 3, 1, 1);

        label_4 = new QLabel(ConvexAndConcave);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(200, 0));
        label_4->setFont(font);
        label_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        yCoordinateLineEdit = new QLineEdit(ConvexAndConcave);
        yCoordinateLineEdit->setObjectName("yCoordinateLineEdit");
        yCoordinateLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout_2->addWidget(yCoordinateLineEdit, 3, 4, 1, 1);

        addPointButton = new QPushButton(ConvexAndConcave);
        addPointButton->setObjectName("addPointButton");
        addPointButton->setMinimumSize(QSize(200, 60));

        gridLayout_2->addWidget(addPointButton, 4, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 5, 2, 1, 1);

        concaveRadioButton = new QRadioButton(ConvexAndConcave);
        concaveRadioButton->setObjectName("concaveRadioButton");

        gridLayout_2->addWidget(concaveRadioButton, 4, 3, 1, 1);

        convexRadioButton = new QRadioButton(ConvexAndConcave);
        convexRadioButton->setObjectName("convexRadioButton");

        gridLayout_2->addWidget(convexRadioButton, 4, 4, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(150, 301, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);


        retranslateUi(ConvexAndConcave);

        QMetaObject::connectSlotsByName(ConvexAndConcave);
    } // setupUi

    void retranslateUi(QDialog *ConvexAndConcave)
    {
        ConvexAndConcave->setWindowTitle(QCoreApplication::translate("ConvexAndConcave", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("ConvexAndConcave", "End Point:", nullptr));
        runConvexAndConcaveButton->setText(QCoreApplication::translate("ConvexAndConcave", "RUN", nullptr));
        label_4->setText(QCoreApplication::translate("ConvexAndConcave", "Start Point:", nullptr));
        addPointButton->setText(QCoreApplication::translate("ConvexAndConcave", "Add Node", nullptr));
        concaveRadioButton->setText(QCoreApplication::translate("ConvexAndConcave", "concave", nullptr));
        convexRadioButton->setText(QCoreApplication::translate("ConvexAndConcave", "convex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvexAndConcave: public Ui_ConvexAndConcave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVEXANDCONCAVE_H
