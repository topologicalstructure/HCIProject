/********************************************************************************
** Form generated from reading UI file 'expectedworks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPECTEDWORKS_H
#define UI_EXPECTEDWORKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpectedWorks
{
public:
    QLabel *label;

    void setupUi(QWidget *ExpectedWorks)
    {
        if (ExpectedWorks->objectName().isEmpty())
            ExpectedWorks->setObjectName(QString::fromUtf8("ExpectedWorks"));
        ExpectedWorks->resize(962, 597);
        label = new QLabel(ExpectedWorks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 141, 61));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(ExpectedWorks);

        QMetaObject::connectSlotsByName(ExpectedWorks);
    } // setupUi

    void retranslateUi(QWidget *ExpectedWorks)
    {
        ExpectedWorks->setWindowTitle(QCoreApplication::translate("ExpectedWorks", "Form", nullptr));
        label->setText(QCoreApplication::translate("ExpectedWorks", "\346\234\252\346\235\245\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpectedWorks: public Ui_ExpectedWorks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPECTEDWORKS_H
