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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    create_widget *widget;
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
"    padding-left:35px;\n"
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
        todayButton->setIconSize(QSize(30, 30));
        todayButton->setCheckable(true);
        todayButton->setChecked(false);
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
"    padding-left:35px;\n"
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
"    padding-left:35px;\n"
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
"    padding-left:35px;\n"
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
"    padding-left:35px;\n"
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
"    padding-left:35px;\n"
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
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(layoutWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        stackedWidget->setMinimumSize(QSize(860, 0));
        stackedWidget->setBaseSize(QSize(0, 0));

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(horizontalLayout);

        widget = new create_widget(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy3);
        widget->setMinimumSize(QSize(860, 40));

        verticalLayout_2->addWidget(widget);

        splitter->addWidget(layoutWidget);

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
        todayButton->setText(QCoreApplication::translate("MainWindow", "  \344\273\212\346\227\245\344\273\273\345\212\241", nullptr));
        expectsButton->setText(QCoreApplication::translate("MainWindow", "  \351\242\204\345\256\232\344\273\273\345\212\241", nullptr));
        extendButton->setText(QCoreApplication::translate("MainWindow", "  \345\267\262\345\273\266\346\234\237", nullptr));
        yestButton->setText(QCoreApplication::translate("MainWindow", "  \346\230\250\346\227\245\344\273\273\345\212\241", nullptr));
        longtermButton->setText(QCoreApplication::translate("MainWindow", "  \351\225\277\346\234\237\344\273\273\345\212\241", nullptr));
        ddlButton->setText(QCoreApplication::translate("MainWindow", "  \346\210\252\346\255\242\346\227\245\346\234\237\345\210\206\345\270\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
