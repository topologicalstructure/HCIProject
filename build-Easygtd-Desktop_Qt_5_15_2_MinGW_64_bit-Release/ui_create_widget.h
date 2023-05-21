/********************************************************************************
** Form generated from reading UI file 'create_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_WIDGET_H
#define UI_CREATE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_create_widget
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;

    void setupUi(QWidget *create_widget)
    {
        if (create_widget->objectName().isEmpty())
            create_widget->setObjectName(QString::fromUtf8("create_widget"));
        create_widget->resize(889, 46);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(create_widget->sizePolicy().hasHeightForWidth());
        create_widget->setSizePolicy(sizePolicy);
        create_widget->setMouseTracking(true);
        horizontalLayout = new QHBoxLayout(create_widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(create_widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(10);
        lineEdit->setFont(font);
        lineEdit->setMouseTracking(false);

        horizontalLayout->addWidget(lineEdit);

        comboBox = new QComboBox(create_widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox QAbstractItemView::item{\n"
"	height:40px;\n"
"}\n"
""));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(comboBox);

        dateEdit = new QDateEdit(create_widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy2);
        dateEdit->setFont(font1);
        dateEdit->setMouseTracking(false);
        dateEdit->setTabletTracking(false);
        dateEdit->setAcceptDrops(false);
        dateEdit->setMinimumDateTime(QDateTime(QDate(2023, 5, 21), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        dateEdit_2 = new QDateEdit(create_widget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        sizePolicy2.setHeightForWidth(dateEdit_2->sizePolicy().hasHeightForWidth());
        dateEdit_2->setSizePolicy(sizePolicy2);
        dateEdit_2->setFont(font1);
        dateEdit_2->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_2);


        retranslateUi(create_widget);

        QMetaObject::connectSlotsByName(create_widget);
    } // setupUi

    void retranslateUi(QWidget *create_widget)
    {
        create_widget->setWindowTitle(QCoreApplication::translate("create_widget", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("create_widget", "\345\215\225\346\227\245 ", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("create_widget", "\351\225\277\346\234\237 ", nullptr));

        dateEdit->setDisplayFormat(QCoreApplication::translate("create_widget", "yyyy-MM-dd", nullptr));
        dateEdit_2->setDisplayFormat(QCoreApplication::translate("create_widget", "yyyy-MM-dd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class create_widget: public Ui_create_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_WIDGET_H
