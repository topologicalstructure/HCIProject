/********************************************************************************
** Form generated from reading UI file 'longtermworks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LONGTERMWORKS_H
#define UI_LONGTERMWORKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_longtermworks
{
public:
    QLabel *label;

    void setupUi(QWidget *longtermworks)
    {
        if (longtermworks->objectName().isEmpty())
            longtermworks->setObjectName(QString::fromUtf8("longtermworks"));
        longtermworks->resize(962, 597);
        label = new QLabel(longtermworks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 131, 61));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(longtermworks);

        QMetaObject::connectSlotsByName(longtermworks);
    } // setupUi

    void retranslateUi(QWidget *longtermworks)
    {
        longtermworks->setWindowTitle(QCoreApplication::translate("longtermworks", "Form", nullptr));
        label->setText(QCoreApplication::translate("longtermworks", "\351\225\277\346\234\237\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class longtermworks: public Ui_longtermworks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LONGTERMWORKS_H
