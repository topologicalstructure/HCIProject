/********************************************************************************
** Form generated from reading UI file 'deadlinedistri.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEADLINEDISTRI_H
#define UI_DEADLINEDISTRI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "CalendarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_deadlinedistri
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    CalendarWidget *MyCalendar;
    QListWidget *listWidget;

    void setupUi(QWidget *deadlinedistri)
    {
        if (deadlinedistri->objectName().isEmpty())
            deadlinedistri->setObjectName(QString::fromUtf8("deadlinedistri"));
        deadlinedistri->resize(962, 597);
        label = new QLabel(deadlinedistri);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 191, 61));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        textBrowser = new QTextBrowser(deadlinedistri);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(310, 520, 641, 51));
        MyCalendar = new CalendarWidget(deadlinedistri);
        MyCalendar->setObjectName(QString::fromUtf8("MyCalendar"));
        MyCalendar->setGeometry(QRect(310, 80, 641, 431));
        listWidget = new QListWidget(deadlinedistri);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 80, 256, 491));

        retranslateUi(deadlinedistri);

        QMetaObject::connectSlotsByName(deadlinedistri);
    } // setupUi

    void retranslateUi(QWidget *deadlinedistri)
    {
        deadlinedistri->setWindowTitle(QCoreApplication::translate("deadlinedistri", "Form", nullptr));
        label->setText(QCoreApplication::translate("deadlinedistri", "\346\210\252\346\255\242\346\227\245\346\234\237\345\210\206\345\270\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deadlinedistri: public Ui_deadlinedistri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEADLINEDISTRI_H
