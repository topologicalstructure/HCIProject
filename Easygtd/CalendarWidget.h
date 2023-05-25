
#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QDate>
#include <QDebug>
#include "sqlconn.h"

//用HSB（HSL）颜色设置
#define K -7  //不同深浅颜色间相差K个亮度值
#define H_GREEN 120 //绿色的H值
#define S_GREEN 255  //绿色的S值
#define L_MAX 255  //最大L值
#define MAX_DDL 30  //假设一天最多有30个任务

SqliteOperator oper;

class CalendarWidget : public QCalendarWidget
{
public:
    CalendarWidget(QWidget *parent = nullptr): QCalendarWidget(parent)
    {
        connect(this, &QCalendarWidget::currentPageChanged, this, &CalendarWidget::onPageChanged);//换页动作关联

        //下面使用selectedDate()方法获取当前选中的日期，并使用daysInMonth()方法获取当前月份的天数。接下来，使用一个循环遍历这些日期，并使用qDebug()输出日期信息。
        QDate currentDate = selectedDate();
        int daysInMonth = currentDate.daysInMonth();

        QDate previousMonthDate = currentDate.addMonths(-1);  // 获取上个月的日期
        QDate nextMonthDate = currentDate.addMonths(1);//获取下个月日期
        int previousnumDays = previousMonthDate.daysInMonth();
        int nextnumDays = nextMonthDate.daysInMonth();
        change_color(previousMonthDate,previousnumDays);
        change_color(currentDate,daysInMonth);
        change_color(nextMonthDate,nextnumDays);
    }
    void change_color(QDate currentDate,int daysInMonth)//输入参数为当前日期（主要是月份），每月的天数。修改整个月的底色。
    {
        for (int day = 1; day <= daysInMonth; ++day)
        {
            QDate date(currentDate.year(), currentDate.month(), day);
            //下面是修改指定日期方格背景色部分的代码
            QTextCharFormat format;// 设置背景色为指定颜色，根据某天任务数量的多少确定
            int lightness=0;//设定颜色的亮度数值
            int taskcount=oper.GetDeadline(date.toString(Qt::ISODate));//存储ddl数量
            if(taskcount>=MAX_DDL)
            {
                taskcount=MAX_DDL;
            }
            lightness=L_MAX+K*taskcount;
            QColor newcolor = QColor::fromHsl(H_GREEN, S_GREEN, lightness);
            format.setBackground(newcolor);// 应用字符格式到指定的日期
            setDateTextFormat(date, format);//修改背景色完毕
            //变色结束
            //qDebug() << date.toString(Qt::ISODate);//将日期转换为string并输出,曾经用于测试

            //注意：检测到用户切换月份时，有专门的函数处理更新，但是那个函数在用户首次打开一个月份时不工作，所以上面构造函数的部分（对日期首次处理）也是需要的
            //GetDeadline(QString date);这个函数可以查询某一日期的截止任务数量，输入参数应该是"xxxx-xx-xx"

            //假设一天最多有30个任务（30以上均为同一种颜色），不同深浅颜色间相差K个B值
            //使用HSB调整，主要修改B属性，255是白，0是黑。大致调整的范围是45~255，共210.底色用绿色。
            //任务数量0对应255,30对应75.y=K*x+255.
            //QColor newcolor = QColor::fromHsl(hue, saturation, lightness);
            //setDateTextFormat(QDate(2023,05,22), format),输入参数是QDate
        }
    }
private slots:
    void onPageChanged(int year, int month)//这是检测用户日历换页后重新修改颜色
    {
        QDate currentDate(year, month, 1);
        int daysInMonth = currentDate.daysInMonth();

        QDate previousMonthDate = currentDate.addMonths(-1);  // 获取上个月的日期
        QDate nextMonthDate = currentDate.addMonths(1);//获取下个月日期
        int previousnumDays = previousMonthDate.daysInMonth();
        int nextnumDays = nextMonthDate.daysInMonth();
        change_color(previousMonthDate,previousnumDays);
        change_color(currentDate,daysInMonth);
        change_color(nextMonthDate,nextnumDays);
    }
};

#endif // CALENDARWIDGET_H
