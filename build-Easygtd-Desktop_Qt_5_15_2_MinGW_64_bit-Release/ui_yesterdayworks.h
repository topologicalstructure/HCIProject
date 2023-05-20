/********************************************************************************
** Form generated from reading UI file 'yesterdayworks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YESTERDAYWORKS_H
#define UI_YESTERDAYWORKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yesterdayworks
{
public:
    QLabel *label;

    void setupUi(QWidget *yesterdayworks)
    {
        if (yesterdayworks->objectName().isEmpty())
            yesterdayworks->setObjectName(QString::fromUtf8("yesterdayworks"));
        yesterdayworks->resize(962, 597);
        label = new QLabel(yesterdayworks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 131, 61));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(yesterdayworks);

        QMetaObject::connectSlotsByName(yesterdayworks);
    } // setupUi

    void retranslateUi(QWidget *yesterdayworks)
    {
        yesterdayworks->setWindowTitle(QCoreApplication::translate("yesterdayworks", "Form", nullptr));
        label->setText(QCoreApplication::translate("yesterdayworks", "\346\230\250\346\227\245\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yesterdayworks: public Ui_yesterdayworks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YESTERDAYWORKS_H
