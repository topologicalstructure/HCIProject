#ifndef CREATE_WIDGET_H
#define CREATE_WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include "sqlconn.h"

namespace Ui {
class create_widget;
}

class create_widget : public QWidget
{
    Q_OBJECT

public:
    explicit create_widget(QWidget *parent = nullptr);
    ~create_widget();

private:
    Ui::create_widget *ui;
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void DateChanged();
    void DateChanged2();
};

#endif // CREATE_WIDGET_H
