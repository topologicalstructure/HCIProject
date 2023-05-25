#include "deadlinedistri.h"
#include "ui_deadlinedistri.h"
#include "CalendarWidget.h"


deadlinedistri::deadlinedistri(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deadlinedistri)
{

    ui->setupUi(this);

    // 创建一个 MyCalendarWidget 对象
    CalendarWidget *MyCalendar = new CalendarWidget(this);

    // 在布局的位置将自定义 calendarWidget 添加到 Deadlinedistri 窗口中，之后对他进行颜色处理（如果有可能，还可以加入其他自定义样式）
    ui->verticalLayout->addWidget(MyCalendar);

}

deadlinedistri::~deadlinedistri()
{
    delete ui;
}
