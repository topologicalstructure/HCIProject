#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QDate>
#include <QDebug>
#include <QPainter>
#include <QDir>
#include <QStyleOption>
#include <QToolButton>
#include "sqlconn.h"

//用HSB（HSL）颜色设置
#define K -7  //不同深浅颜色间相差K个亮度值
#define H_GREEN 120 //绿色的H值
#define S_GREEN 255  //绿色的S值
#define L_MAX 255  //最大L值
#define MAX_DDL 30  //假设一天最多有30个任务

#define H_triangle 60 //为当前日期添加黄色三角形角标
#define S_triangle 255
#define L_triangle 120
#define alpha_triangle 0.4 //三角形角标占据正方形日期方格宽度和高度的百分比

#define BtnSize 50 //切换年月按钮大小
#define topWidget_height 60 //顶部表头布局栏高度
#define bottomWidget_height 60 //底部布局栏高度
#define toDayBtn_length 50 //回到今日按钮大小

class QPushButton;
class QLabel;

class CalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    CalendarWidget(QWidget *parent = nullptr);
    void change_color(QDate currentDate,int daysInMonth);//输入参数为当前日期（主要是月份），每月的天数。修改整个月的底色。
private:
    void initControl();
    void initTopWidget();
    void initBottomWidget();
    void setDataLabelTimeText(int year, int month);
    bool eventFilter(QObject* obj, QEvent* event);
public slots:
    void onPageChanged(int year, int month);//这是检测用户日历换页后重新修改颜色
    void onbtnClicked();
protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override;
private:
    QPushButton* m_leftYearBtn;
    QPushButton* m_leftMonthBtn;

    QPushButton* m_rightYearBtn;
    QPushButton* m_rightMonthBtn;

    QPushButton* m_ensureBtn;
    QPushButton* m_toDayBtn;

    QLabel* m_dataLabel;
};

#endif // CALENDARWIDGET_H
