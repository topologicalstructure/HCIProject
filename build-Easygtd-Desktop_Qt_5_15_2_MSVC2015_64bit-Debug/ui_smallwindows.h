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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smallwindows
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *becomebig;
    QSpacerItem *horizontalSpacer;
    QPushButton *CloseButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *smallwindows)
    {
        if (smallwindows->objectName().isEmpty())
            smallwindows->setObjectName(QString::fromUtf8("smallwindows"));
        smallwindows->resize(696, 642);
        smallwindows->setMinimumSize(QSize(35, 35));
        centralwidget = new QWidget(smallwindows);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(600, 0, 96, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        becomebig = new QPushButton(layoutWidget);
        becomebig->setObjectName(QString::fromUtf8("becomebig"));
        becomebig->setMinimumSize(QSize(45, 45));
        QFont font;
        font.setPointSize(12);
        becomebig->setFont(font);

        gridLayout->addWidget(becomebig, 0, 0, 2, 1);

        horizontalSpacer = new QSpacerItem(13, 42, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 2, 1);

        CloseButton = new QPushButton(layoutWidget);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setMinimumSize(QSize(35, 5));
        QFont font1;
        font1.setPointSize(9);
        CloseButton->setFont(font1);

        gridLayout->addWidget(CloseButton, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 0, 211, 31));
        label->setFont(font);
        smallwindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(smallwindows);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 696, 26));
        smallwindows->setMenuBar(menubar);
        statusbar = new QStatusBar(smallwindows);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        smallwindows->setStatusBar(statusbar);

        retranslateUi(smallwindows);

        QMetaObject::connectSlotsByName(smallwindows);
    } // setupUi

    void retranslateUi(QMainWindow *smallwindows)
    {
        smallwindows->setWindowTitle(QCoreApplication::translate("smallwindows", "MainWindow", nullptr));
        becomebig->setText(QCoreApplication::translate("smallwindows", "\345\217\230\345\244\247", nullptr));
        CloseButton->setText(QCoreApplication::translate("smallwindows", "\345\205\263\351\227\255", nullptr));
        label->setText(QCoreApplication::translate("smallwindows", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class smallwindows: public Ui_smallwindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWINDOWS_H
