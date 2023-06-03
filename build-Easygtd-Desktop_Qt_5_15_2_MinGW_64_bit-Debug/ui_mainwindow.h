/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "create_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *sidebar;
    QGridLayout *gridLayout;
    QToolButton *todayButton;
    QSpacerItem *verticalSpacer;
    QToolButton *expectsButton;
    QToolButton *extendButton;
    QToolButton *yestButton;
    QToolButton *longtermButton;
    QToolButton *ddlButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *becomesmaller;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    create_widget *widget1;
    QMenuBar *menubar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1214, 669);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLineWidth(0);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(3);
        splitter->setChildrenCollapsible(true);
        sidebar = new QWidget(splitter);
        sidebar->setObjectName(QString::fromUtf8("sidebar"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy);
        sidebar->setMaximumSize(QSize(800, 16777215));
        sidebar->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(245, 245, 245);  /* \350\256\276\347\275\256\350\203\214\346\231\257\350\211\262\344\270\272\347\201\260\350\211\262 */\n"
"}"));
        gridLayout = new QGridLayout(sidebar);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        todayButton = new QToolButton(sidebar);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(todayButton);
        todayButton->setObjectName(QString::fromUtf8("todayButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(todayButton->sizePolicy().hasHeightForWidth());
        todayButton->setSizePolicy(sizePolicy1);
        todayButton->setStyleSheet(QString::fromUtf8("QToolButton{   \n"
"	border-top: 3px outset transparent;         /* \344\270\212\350\276\271\346\241\206\350\256\276\347\275\256*/\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 150px;\n"
"    min-height: 40px;\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(235, 235, 235);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 5px outset rgb(23, 117, 217);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272 */\n"
"	background-color: rgb(235, 235, 235);	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        todayButton->setIconSize(QSize(24, 24));
        todayButton->setCheckable(true);
        todayButton->setAutoExclusive(true);
        todayButton->setPopupMode(QToolButton::DelayedPopup);
        todayButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        todayButton->setArrowType(Qt::NoArrow);

        gridLayout->addWidget(todayButton, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 294, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        expectsButton = new QToolButton(sidebar);
        buttonGroup->addButton(expectsButton);
        expectsButton->setObjectName(QString::fromUtf8("expectsButton"));
        sizePolicy1.setHeightForWidth(expectsButton->sizePolicy().hasHeightForWidth());
        expectsButton->setSizePolicy(sizePolicy1);
        expectsButton->setStyleSheet(QString::fromUtf8("QToolButton{   \n"
"	border-top: 3px outset transparent;         /* \344\270\212\350\276\271\346\241\206\350\256\276\347\275\256*/\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 150px;\n"
"    min-height: 40px;\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(235, 235, 235);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 5px outset rgb(23, 117, 217);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272 */\n"
"	background-color: rgb(235, 235, 235);	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        expectsButton->setCheckable(true);
        expectsButton->setAutoExclusive(true);

        gridLayout->addWidget(expectsButton, 1, 0, 1, 1);

        extendButton = new QToolButton(sidebar);
        buttonGroup->addButton(extendButton);
        extendButton->setObjectName(QString::fromUtf8("extendButton"));
        sizePolicy1.setHeightForWidth(extendButton->sizePolicy().hasHeightForWidth());
        extendButton->setSizePolicy(sizePolicy1);
        extendButton->setStyleSheet(QString::fromUtf8("QToolButton{   \n"
"	border-top: 3px outset transparent;         /* \344\270\212\350\276\271\346\241\206\350\256\276\347\275\256*/\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 150px;\n"
"    min-height: 40px;\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(235, 235, 235);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 5px outset rgb(23, 117, 217);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272 */\n"
"	background-color: rgb(235, 235, 235);	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        extendButton->setCheckable(true);
        extendButton->setAutoExclusive(true);

        gridLayout->addWidget(extendButton, 8, 0, 1, 1);

        yestButton = new QToolButton(sidebar);
        buttonGroup->addButton(yestButton);
        yestButton->setObjectName(QString::fromUtf8("yestButton"));
        sizePolicy1.setHeightForWidth(yestButton->sizePolicy().hasHeightForWidth());
        yestButton->setSizePolicy(sizePolicy1);
        yestButton->setStyleSheet(QString::fromUtf8("QToolButton{   \n"
"	border-top: 3px outset transparent;         /* \344\270\212\350\276\271\346\241\206\350\256\276\347\275\256*/\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 150px;\n"
"    min-height: 40px;\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(235, 235, 235);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 5px outset rgb(23, 117, 217);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272 */\n"
"	background-color: rgb(235, 235, 235);	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        yestButton->setCheckable(true);
        yestButton->setAutoExclusive(true);

        gridLayout->addWidget(yestButton, 7, 0, 1, 1);

        longtermButton = new QToolButton(sidebar);
        buttonGroup->addButton(longtermButton);
        longtermButton->setObjectName(QString::fromUtf8("longtermButton"));
        sizePolicy1.setHeightForWidth(longtermButton->sizePolicy().hasHeightForWidth());
        longtermButton->setSizePolicy(sizePolicy1);
        longtermButton->setStyleSheet(QString::fromUtf8("QToolButton{   \n"
"	border-top: 3px outset transparent;         /* \344\270\212\350\276\271\346\241\206\350\256\276\347\275\256*/\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 150px;\n"
"    min-height: 40px;\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(235, 235, 235);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 5px outset rgb(23, 117, 217);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272 */\n"
"	background-color: rgb(235, 235, 235);	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        longtermButton->setCheckable(true);
        longtermButton->setAutoExclusive(true);

        gridLayout->addWidget(longtermButton, 5, 0, 1, 1);

        ddlButton = new QToolButton(sidebar);
        buttonGroup->addButton(ddlButton);
        ddlButton->setObjectName(QString::fromUtf8("ddlButton"));
        sizePolicy1.setHeightForWidth(ddlButton->sizePolicy().hasHeightForWidth());
        ddlButton->setSizePolicy(sizePolicy1);
        ddlButton->setStyleSheet(QString::fromUtf8("QToolButton{   \n"
"	border-top: 3px outset transparent;         /* \344\270\212\350\276\271\346\241\206\350\256\276\347\275\256*/\n"
"	border-bottom: 7px outset transparent;\n"
"	border-right: 3px outset transparent;\n"
"	border-left: 3px outset transparent;\n"
"    min-width: 150px;\n"
"    min-height: 40px;\n"
"	background-color: rgb(245, 245, 245);\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: rgb(235, 235, 235);\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 5px outset rgb(23, 117, 217);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272 */\n"
"	background-color: rgb(235, 235, 235);	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        ddlButton->setCheckable(true);
        ddlButton->setAutoExclusive(true);

        gridLayout->addWidget(ddlButton, 10, 0, 1, 1);

        splitter->addWidget(sidebar);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        stackedWidget->setMinimumSize(QSize(860, 0));
        stackedWidget->setBaseSize(QSize(0, 0));

        horizontalLayout->addWidget(stackedWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        becomesmaller = new QPushButton(widget);
        becomesmaller->setObjectName(QString::fromUtf8("becomesmaller"));

        verticalLayout->addWidget(becomesmaller);

        verticalSpacer_8 = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        verticalSpacer_7 = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        verticalSpacer_6 = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalSpacer_5 = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalSpacer_4 = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        widget1 = new create_widget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy3);
        widget1->setMinimumSize(QSize(860, 40));

        verticalLayout_2->addWidget(widget1);

        splitter->addWidget(widget);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1214, 17));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        todayButton->setText(QCoreApplication::translate("MainWindow", "\344\273\212\346\227\245\344\273\273\345\212\241", nullptr));
        expectsButton->setText(QCoreApplication::translate("MainWindow", "\351\242\204\345\256\232\344\273\273\345\212\241", nullptr));
        extendButton->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\273\266\346\234\237", nullptr));
        yestButton->setText(QCoreApplication::translate("MainWindow", "\346\230\250\346\227\245\344\273\273\345\212\241", nullptr));
        longtermButton->setText(QCoreApplication::translate("MainWindow", "\351\225\277\346\234\237\344\273\273\345\212\241", nullptr));
        ddlButton->setText(QCoreApplication::translate("MainWindow", "\346\210\252\346\255\242\346\227\245\346\234\237\345\210\206\345\270\203", nullptr));
        becomesmaller->setText(QCoreApplication::translate("MainWindow", "\345\217\230\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
