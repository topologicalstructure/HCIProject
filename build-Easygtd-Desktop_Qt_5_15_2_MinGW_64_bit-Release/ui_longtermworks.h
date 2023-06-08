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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <workdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_longtermworks
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    workDisplay *workView;

    void setupUi(QWidget *longtermworks)
    {
        if (longtermworks->objectName().isEmpty())
            longtermworks->setObjectName(QString::fromUtf8("longtermworks"));
        longtermworks->resize(962, 597);
        verticalLayout = new QVBoxLayout(longtermworks);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(longtermworks);
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
"    background-color:rgb(240,240,255);\n"
"}"));

        verticalLayout->addWidget(label);

        workView = new workDisplay(longtermworks);
        workView->setObjectName(QString::fromUtf8("workView"));
        workView->setStyleSheet(QString::fromUtf8("workDisplay#workView{\n"
"    background-color:rgb(240,240,255);\n"
"}"));

        verticalLayout->addWidget(workView);


        retranslateUi(longtermworks);

        QMetaObject::connectSlotsByName(longtermworks);
    } // setupUi

    void retranslateUi(QWidget *longtermworks)
    {
        longtermworks->setWindowTitle(QCoreApplication::translate("longtermworks", "Form", nullptr));
        label->setText(QCoreApplication::translate("longtermworks", "  \351\225\277\346\234\237\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class longtermworks: public Ui_longtermworks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LONGTERMWORKS_H
