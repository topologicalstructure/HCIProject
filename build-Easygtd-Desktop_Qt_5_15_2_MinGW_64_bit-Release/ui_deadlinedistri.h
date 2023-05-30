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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "CalendarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_deadlinedistri
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *listWidget;
    CalendarWidget *MyCalendar;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *deadlinedistri)
    {
        if (deadlinedistri->objectName().isEmpty())
            deadlinedistri->setObjectName(QString::fromUtf8("deadlinedistri"));
        deadlinedistri->resize(962, 597);
        gridLayout = new QGridLayout(deadlinedistri);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(deadlinedistri);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        listWidget = new QListWidget(deadlinedistri);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(listWidget, 1, 0, 2, 1);

        MyCalendar = new CalendarWidget(deadlinedistri);
        MyCalendar->setObjectName(QString::fromUtf8("MyCalendar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(MyCalendar->sizePolicy().hasHeightForWidth());
        MyCalendar->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(MyCalendar, 1, 1, 1, 1);

        textBrowser = new QTextBrowser(deadlinedistri);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(textBrowser, 2, 1, 1, 1);


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
