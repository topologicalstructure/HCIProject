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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *becomesmaller;
    QWidget *sidebar;
    QGridLayout *gridLayout;
    QToolButton *todayButton;
    QToolButton *expectsButton;
    QToolButton *extendButton;
    QToolButton *yestButton;
    QToolButton *longtermButton;
    QSpacerItem *verticalSpacer;
    QToolButton *ddlButton;
    QStackedWidget *stackedWidget;
    QMenuBar *menubar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1214, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        becomesmaller = new QPushButton(centralwidget);
        becomesmaller->setObjectName(QString::fromUtf8("becomesmaller"));

        gridLayout_2->addWidget(becomesmaller, 0, 2, 1, 1);

        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName(QString::fromUtf8("sidebar"));
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
        todayButton->setCheckable(true);
        todayButton->setAutoExclusive(true);

        gridLayout->addWidget(todayButton, 0, 0, 1, 1);

        expectsButton = new QToolButton(sidebar);
        buttonGroup->addButton(expectsButton);
        expectsButton->setObjectName(QString::fromUtf8("expectsButton"));
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

        verticalSpacer = new QSpacerItem(20, 294, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        ddlButton = new QToolButton(sidebar);
        buttonGroup->addButton(ddlButton);
        ddlButton->setObjectName(QString::fromUtf8("ddlButton"));
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


        gridLayout_2->addWidget(sidebar, 0, 0, 2, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        gridLayout_2->addWidget(stackedWidget, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1214, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        becomesmaller->setText(QCoreApplication::translate("MainWindow", "\345\217\230\345\260\217", nullptr));
        todayButton->setText(QCoreApplication::translate("MainWindow", "\344\273\212\346\227\245\344\273\273\345\212\241", nullptr));
        expectsButton->setText(QCoreApplication::translate("MainWindow", "\351\242\204\345\256\232\344\273\273\345\212\241", nullptr));
        extendButton->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\273\266\346\234\237", nullptr));
        yestButton->setText(QCoreApplication::translate("MainWindow", "\346\230\250\346\227\245\344\273\273\345\212\241", nullptr));
        longtermButton->setText(QCoreApplication::translate("MainWindow", "\351\225\277\346\234\237\344\273\273\345\212\241", nullptr));
        ddlButton->setText(QCoreApplication::translate("MainWindow", "\346\210\252\346\255\242\346\227\245\346\234\237\345\210\206\345\270\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
