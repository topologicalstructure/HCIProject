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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <workdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_ExpectedWorks
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    workDisplay *workView;

    void setupUi(QWidget *ExpectedWorks)
    {
        if (ExpectedWorks->objectName().isEmpty())
            ExpectedWorks->setObjectName(QString::fromUtf8("ExpectedWorks"));
        ExpectedWorks->resize(962, 597);
        verticalLayout = new QVBoxLayout(ExpectedWorks);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(ExpectedWorks);
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
"    background-color:rgb(235,255,245);\n"
"}"));

        verticalLayout->addWidget(label);

        workView = new workDisplay(ExpectedWorks);
        workView->setObjectName(QString::fromUtf8("workView"));
        workView->setStyleSheet(QString::fromUtf8("workDisplay#workView{\n"
"    background-color:rgb(235,255,245);\n"
"}"));

        verticalLayout->addWidget(workView);


        retranslateUi(ExpectedWorks);

        QMetaObject::connectSlotsByName(ExpectedWorks);
    } // setupUi

    void retranslateUi(QWidget *ExpectedWorks)
    {
        ExpectedWorks->setWindowTitle(QCoreApplication::translate("ExpectedWorks", "Form", nullptr));
        label->setText(QCoreApplication::translate("ExpectedWorks", "  \346\234\252\346\235\245\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpectedWorks: public Ui_ExpectedWorks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPECTEDWORKS_H
