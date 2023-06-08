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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <workdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_extendedworks
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    workDisplay *workView;

    void setupUi(QWidget *extendedworks)
    {
        if (extendedworks->objectName().isEmpty())
            extendedworks->setObjectName(QString::fromUtf8("extendedworks"));
        extendedworks->resize(962, 597);
        verticalLayout = new QVBoxLayout(extendedworks);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(extendedworks);
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
"    background-color:rgb(255,234,204);\n"
"}"));

        verticalLayout->addWidget(label);

        workView = new workDisplay(extendedworks);
        workView->setObjectName(QString::fromUtf8("workView"));
        workView->setStyleSheet(QString::fromUtf8("workDisplay#workView{\n"
"    background-color:rgb(255,234,204);\n"
"}"));

        verticalLayout->addWidget(workView);


        retranslateUi(extendedworks);

        QMetaObject::connectSlotsByName(extendedworks);
    } // setupUi

    void retranslateUi(QWidget *extendedworks)
    {
        extendedworks->setWindowTitle(QCoreApplication::translate("extendedworks", "Form", nullptr));
        label->setText(QCoreApplication::translate("extendedworks", "  \345\267\262\345\273\266\346\234\237\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class extendedworks: public Ui_extendedworks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENDEDWORKS_H
