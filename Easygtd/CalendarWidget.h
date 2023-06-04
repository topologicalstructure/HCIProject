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
#include"sqlconn.h"

#define MAX_DDL 10  //假设一天最多有MAX_DDL个任务
//每日实际任务数超过(严格大于)MAX_DDL后，会按照和MAX_DDL一样的颜色显示背景色、DDL数量显示框会显示一个加号、任务总览仍然显示全部(数量多于MAX_DDL)的每日任务

//用HSB（HSL）颜色设置
#define K -12  //不同深浅颜色间相差K个色相值
#define H_MAX 120 //最大的H值（绿色）
#define H_MIN 0 //最小的H值（红色）
#define S_CONST 255  //设定不变的饱和度S值
#define L_CONST 170  //设定不变的亮度L值
//调色的范围是H_MIN~H_MAX，最好使得 K * MAX_DDL = H_MAX - H_MIN
//每日任务数大于0才会修改底色

//#define H_triangle 300 //为当前日期添加三角形角标
//#define S_triangle 255
//#define L_triangle 140
#define alpha_triangle 0.3 //三角形角标占据正方形日期方格高度的百分比

#define BtnSize 50 //切换年月按钮大小
#define topWidget_height 60 //顶部表头布局栏高度
#define bottomWidget_height 60 //底部布局栏高度
#define toDayBtn_length 45 //回到今日按钮大小

class QPushButton;
class QLabel;

class CalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    CalendarWidget(QWidget *parent = nullptr);
    void setddlLabelText();
private:
    void initControl();
    void initTopWidget();
    void initBottomWidget();
    void setDataLabelTimeText(int year, int month);
    bool eventFilter(QObject* obj, QEvent* event);
public slots:
    void onbtnClicked();
protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override;
private:
    QPushButton* m_leftYearBtn;
    QPushButton* m_leftMonthBtn;

    QPushButton* m_rightYearBtn;
    QPushButton* m_rightMonthBtn;

    QPushButton* m_toDayBtn;

    QLabel* m_dataLabel;
    QLabel* m_ddlLabel;
};

#endif // CALENDARWIDGET_H
