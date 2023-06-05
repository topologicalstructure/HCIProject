#ifndef CREATE_WIDGET_H
#define CREATE_WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QStandardItem>
#include <QApplication>
#include "sqlconn.h"

namespace Ui {
class create_widget;
}

//该类为自定义的任务添加控件
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
    void on_pushButton_clicked();
    void DateChanged();
    void DateChanged2();

signals:
    void CreateSuccess();

};

#endif // CREATE_WIDGET_H
