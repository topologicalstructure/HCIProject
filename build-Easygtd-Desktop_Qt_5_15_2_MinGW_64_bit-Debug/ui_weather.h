/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QGridLayout *gridLayout;
    QLabel *picture;
    QLabel *tem;
    QLabel *weather;

    void setupUi(QWidget *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QString::fromUtf8("Weather"));
        Weather->resize(200, 100);
        gridLayout = new QGridLayout(Weather);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        picture = new QLabel(Weather);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(picture, 0, 0, 2, 1);

        tem = new QLabel(Weather);
        tem->setObjectName(QString::fromUtf8("tem"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        tem->setFont(font);
        tem->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(tem, 0, 1, 1, 1);

        weather = new QLabel(Weather);
        weather->setObjectName(QString::fromUtf8("weather"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        weather->setFont(font1);
        weather->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(weather, 1, 1, 1, 1);


        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QWidget *Weather)
    {
        Weather->setWindowTitle(QCoreApplication::translate("Weather", "Form", nullptr));
        picture->setText(QCoreApplication::translate("Weather", "TextLabel", nullptr));
        tem->setText(QString());
        weather->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
