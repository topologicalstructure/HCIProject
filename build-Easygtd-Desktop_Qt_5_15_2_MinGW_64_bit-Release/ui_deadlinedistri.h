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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CalendarWidget.h"

QT_BEGIN_NAMESPACE

class Ui_deadlinedistri
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSplitter *splitter_2;
    QListWidget *listWidget;
    QSplitter *splitter;
    CalendarWidget *MyCalendar;

    void setupUi(QWidget *deadlinedistri)
    {
        if (deadlinedistri->objectName().isEmpty())
            deadlinedistri->setObjectName(QString::fromUtf8("deadlinedistri"));
        deadlinedistri->resize(962, 597);
        verticalLayout = new QVBoxLayout(deadlinedistri);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(deadlinedistri);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel#label{\n"
"    background-color:rgb(250,224,227);\n"
"}"));

        verticalLayout->addWidget(label);

        splitter_2 = new QSplitter(deadlinedistri);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(1);
        splitter_2->setChildrenCollapsible(false);
        listWidget = new QListWidget(splitter_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget#listWidget{\n"
"    background-color:rgb(250,224,227);\n"
"}"));
        splitter_2->addWidget(listWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(1);
        splitter->setChildrenCollapsible(false);
        MyCalendar = new CalendarWidget(splitter);
        MyCalendar->setObjectName(QString::fromUtf8("MyCalendar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MyCalendar->sizePolicy().hasHeightForWidth());
        MyCalendar->setSizePolicy(sizePolicy2);
        MyCalendar->setMinimumSize(QSize(400, 380));
        MyCalendar->setStyleSheet(QString::fromUtf8("CalendarWidget#MyCalendar{\n"
"    background-color:rgb(250,224,227);\n"
"}"));
        splitter->addWidget(MyCalendar);
        splitter_2->addWidget(splitter);

        verticalLayout->addWidget(splitter_2);


        retranslateUi(deadlinedistri);

        QMetaObject::connectSlotsByName(deadlinedistri);
    } // setupUi

    void retranslateUi(QWidget *deadlinedistri)
    {
        deadlinedistri->setWindowTitle(QCoreApplication::translate("deadlinedistri", "Form", nullptr));
        label->setText(QCoreApplication::translate("deadlinedistri", "  \346\210\252\346\255\242\346\227\245\346\234\237\345\210\206\345\270\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deadlinedistri: public Ui_deadlinedistri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEADLINEDISTRI_H
