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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Todayworks
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget_2;

    void setupUi(QWidget *Todayworks)
    {
        if (Todayworks->objectName().isEmpty())
            Todayworks->setObjectName(QString::fromUtf8("Todayworks"));
        Todayworks->resize(962, 597);
        verticalLayout = new QVBoxLayout(Todayworks);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, 0);
        label = new QLabel(Todayworks);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        verticalLayout->addWidget(label);

        widget_2 = new QWidget(Todayworks);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);


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
