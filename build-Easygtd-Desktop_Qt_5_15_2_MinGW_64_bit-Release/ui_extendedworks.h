/********************************************************************************
** Form generated from reading UI file 'extendedworks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTENDEDWORKS_H
#define UI_EXTENDEDWORKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_extendedworks
{
public:
    QLabel *label;

    void setupUi(QWidget *extendedworks)
    {
        if (extendedworks->objectName().isEmpty())
            extendedworks->setObjectName(QString::fromUtf8("extendedworks"));
        extendedworks->resize(962, 597);
        label = new QLabel(extendedworks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 161, 61));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(extendedworks);

        QMetaObject::connectSlotsByName(extendedworks);
    } // setupUi

    void retranslateUi(QWidget *extendedworks)
    {
        extendedworks->setWindowTitle(QCoreApplication::translate("extendedworks", "Form", nullptr));
        label->setText(QCoreApplication::translate("extendedworks", "\345\267\262\345\273\266\346\234\237\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class extendedworks: public Ui_extendedworks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENDEDWORKS_H
