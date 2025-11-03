/********************************************************************************
** Form generated from reading UI file 'shortestpath.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTESTPATH_H
#define UI_SHORTESTPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ShortestPath
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLabel *label;
    QPushButton *runButton;
    QLineEdit *startNodeLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *endNodeLineEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *theEdgeLengthLineEdit;
    QLineEdit *secondNodeNameLineEdit;
    QLineEdit *fristNodeNameLineEdit;
    QPushButton *addNodeButton;

    void setupUi(QDialog *ShortestPath)
    {
        if (ShortestPath->objectName().isEmpty())
            ShortestPath->setObjectName("ShortestPath");
        ShortestPath->resize(1159, 358);
        gridLayout_2 = new QGridLayout(ShortestPath);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer = new QSpacerItem(150, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 3, 1, 1);

        label_2 = new QLabel(ShortestPath);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        label = new QLabel(ShortestPath);
        label->setObjectName("label");
        label->setMinimumSize(QSize(200, 0));
        label->setFont(font);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        runButton = new QPushButton(ShortestPath);
        runButton->setObjectName("runButton");
        runButton->setMinimumSize(QSize(200, 60));
        runButton->setStyleSheet(QString::fromUtf8("background-color: gray\n"
";\n"
""));

        gridLayout->addWidget(runButton, 7, 4, 1, 1);

        startNodeLineEdit = new QLineEdit(ShortestPath);
        startNodeLineEdit->setObjectName("startNodeLineEdit");
        startNodeLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout->addWidget(startNodeLineEdit, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        endNodeLineEdit = new QLineEdit(ShortestPath);
        endNodeLineEdit->setObjectName("endNodeLineEdit");
        endNodeLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout->addWidget(endNodeLineEdit, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 3, 1, 1);

        theEdgeLengthLineEdit = new QLineEdit(ShortestPath);
        theEdgeLengthLineEdit->setObjectName("theEdgeLengthLineEdit");
        theEdgeLengthLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout->addWidget(theEdgeLengthLineEdit, 3, 4, 1, 1);

        secondNodeNameLineEdit = new QLineEdit(ShortestPath);
        secondNodeNameLineEdit->setObjectName("secondNodeNameLineEdit");
        secondNodeNameLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout->addWidget(secondNodeNameLineEdit, 3, 3, 1, 1);

        fristNodeNameLineEdit = new QLineEdit(ShortestPath);
        fristNodeNameLineEdit->setObjectName("fristNodeNameLineEdit");
        fristNodeNameLineEdit->setMinimumSize(QSize(200, 40));

        gridLayout->addWidget(fristNodeNameLineEdit, 3, 2, 1, 1);

        addNodeButton = new QPushButton(ShortestPath);
        addNodeButton->setObjectName("addNodeButton");
        addNodeButton->setMinimumSize(QSize(200, 60));

        gridLayout->addWidget(addNodeButton, 5, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(ShortestPath);

        QMetaObject::connectSlotsByName(ShortestPath);
    } // setupUi

    void retranslateUi(QDialog *ShortestPath)
    {
        ShortestPath->setWindowTitle(QCoreApplication::translate("ShortestPath", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("ShortestPath", "End Node:", nullptr));
        label->setText(QCoreApplication::translate("ShortestPath", "Start Node:", nullptr));
        runButton->setText(QCoreApplication::translate("ShortestPath", "RUN", nullptr));
        addNodeButton->setText(QCoreApplication::translate("ShortestPath", "Add Node", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShortestPath: public Ui_ShortestPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTESTPATH_H
