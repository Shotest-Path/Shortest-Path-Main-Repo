/********************************************************************************
** Form generated from reading UI file 'convexandconcave.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVEXANDCONCAVE_H
#define UI_CONVEXANDCONCAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ConvexAndConcave
{
public:

    void setupUi(QDialog *ConvexAndConcave)
    {
        if (ConvexAndConcave->objectName().isEmpty())
            ConvexAndConcave->setObjectName("ConvexAndConcave");
        ConvexAndConcave->resize(400, 300);

        retranslateUi(ConvexAndConcave);

        QMetaObject::connectSlotsByName(ConvexAndConcave);
    } // setupUi

    void retranslateUi(QDialog *ConvexAndConcave)
    {
        ConvexAndConcave->setWindowTitle(QCoreApplication::translate("ConvexAndConcave", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvexAndConcave: public Ui_ConvexAndConcave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVEXANDCONCAVE_H
