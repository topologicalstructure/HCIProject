/********************************************************************************
** Form generated from reading UI file 'smallwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWINDOWS_H
#define UI_SMALLWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "create_widget.h"
#include "weather.h"

QT_BEGIN_NAMESPACE

class Ui_smallwindows
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    Weather *weawid;
    QGridLayout *gridLayout;
    QPushButton *CloseButton;
    QPushButton *becomebig;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    create_widget *widget_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *smallwindows)
    {
        if (smallwindows->objectName().isEmpty())
            smallwindows->setObjectName(QString::fromUtf8("smallwindows"));
        smallwindows->resize(549, 642);
        smallwindows->setMinimumSize(QSize(35, 35));
        smallwindows->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        centralwidget = new QWidget(smallwindows);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        weawid = new Weather(centralwidget);
        weawid->setObjectName(QString::fromUtf8("weawid"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(weawid->sizePolicy().hasHeightForWidth());
        weawid->setSizePolicy(sizePolicy1);
        weawid->setMinimumSize(QSize(200, 100));
        weawid->setMaximumSize(QSize(200, 100));

        horizontalLayout->addWidget(weawid);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CloseButton = new QPushButton(centralwidget);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setMinimumSize(QSize(30, 30));
        CloseButton->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setPointSize(9);
        CloseButton->setFont(font1);

        gridLayout->addWidget(CloseButton, 0, 3, 1, 1);

        becomebig = new QPushButton(centralwidget);
        becomebig->setObjectName(QString::fromUtf8("becomebig"));
        becomebig->setMinimumSize(QSize(45, 45));
        becomebig->setMaximumSize(QSize(45, 45));
        QFont font2;
        font2.setPointSize(12);
        becomebig->setFont(font2);

        gridLayout->addWidget(becomebig, 0, 0, 2, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(30, 0, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 2, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(widget);

        widget_2 = new create_widget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        widget_2->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(widget_2);

        smallwindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(smallwindows);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 549, 17));
        smallwindows->setMenuBar(menubar);

        retranslateUi(smallwindows);

        QMetaObject::connectSlotsByName(smallwindows);
    } // setupUi

    void retranslateUi(QMainWindow *smallwindows)
    {
        smallwindows->setWindowTitle(QCoreApplication::translate("smallwindows", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("smallwindows", "\346\210\221\347\232\204\344\270\200\345\244\251", nullptr));
        CloseButton->setText(QCoreApplication::translate("smallwindows", "\345\205\263\351\227\255", nullptr));
        becomebig->setText(QCoreApplication::translate("smallwindows", "\345\217\230\345\244\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smallwindows: public Ui_smallwindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWINDOWS_H
