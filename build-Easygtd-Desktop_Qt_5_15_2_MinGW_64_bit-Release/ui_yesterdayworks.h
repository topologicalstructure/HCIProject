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
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yesterdayworks
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *workView;

    void setupUi(QWidget *yesterdayworks)
    {
        if (yesterdayworks->objectName().isEmpty())
            yesterdayworks->setObjectName(QString::fromUtf8("yesterdayworks"));
        yesterdayworks->resize(962, 597);
        verticalLayout = new QVBoxLayout(yesterdayworks);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(yesterdayworks);
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
"    background-color:rgb(244,249,210);\n"
"}"));

        verticalLayout->addWidget(label);

        workView = new QListView(yesterdayworks);
        workView->setObjectName(QString::fromUtf8("workView"));
        workView->setStyleSheet(QString::fromUtf8("workDisplay#workView{\n"
"    background-color:rgb(244,249,210);\n"
"}"));

        verticalLayout->addWidget(workView);


        retranslateUi(yesterdayworks);

        QMetaObject::connectSlotsByName(yesterdayworks);
    } // setupUi

    void retranslateUi(QWidget *yesterdayworks)
    {
        yesterdayworks->setWindowTitle(QCoreApplication::translate("yesterdayworks", "Form", nullptr));
        label->setText(QCoreApplication::translate("yesterdayworks", "  \346\230\250\346\227\245\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yesterdayworks: public Ui_yesterdayworks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YESTERDAYWORKS_H
