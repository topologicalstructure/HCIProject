/********************************************************************************
** Form generated from reading UI file 'todayworks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODAYWORKS_H
#define UI_TODAYWORKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "create_widget.h"

QT_BEGIN_NAMESPACE

class Ui_Todayworks
{
public:
    QLabel *label;
    create_widget *widget;

    void setupUi(QWidget *Todayworks)
    {
        if (Todayworks->objectName().isEmpty())
            Todayworks->setObjectName(QString::fromUtf8("Todayworks"));
        Todayworks->resize(962, 597);
        label = new QLabel(Todayworks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 131, 61));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        widget = new create_widget(Todayworks);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 550, 951, 51));

        retranslateUi(Todayworks);

        QMetaObject::connectSlotsByName(Todayworks);
    } // setupUi

    void retranslateUi(QWidget *Todayworks)
    {
        Todayworks->setWindowTitle(QCoreApplication::translate("Todayworks", "Form", nullptr));
        label->setText(QCoreApplication::translate("Todayworks", "\346\210\221\347\232\204\344\270\200\345\244\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Todayworks: public Ui_Todayworks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODAYWORKS_H
