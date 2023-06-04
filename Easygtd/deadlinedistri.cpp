#include "deadlinedistri.h"
#include "ui_deadlinedistri.h"
#include "CalendarWidget.h"
#include <QDate>
#include <QString>

SqliteOperator* oper1=new SqliteOperator;

deadlinedistri::deadlinedistri(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deadlinedistri)
{

    ui->setupUi(this);

    // 创建一个 MyCalendarWidget 对象
    //CalendarWidget *MyCalendar = new CalendarWidget(this);

    // 在布局的位置将自定义 calendarWidget 添加到 Deadlinedistri 窗口中，之后对他进行颜色处理（如果有可能，还可以加入其他自定义样式）
    //ui->verticalLayout->addWidget(MyCalendar);

    connect(ui->MyCalendar, &QCalendarWidget::selectionChanged, this, &deadlinedistri::onselectionChanged);//用户修改选中的日期动作关联
    QFont font("Arial", 15);  // 创建字体对象并设置字号
    ui->listWidget->setFont(font);      // 设置项目的字体
    ui->listWidget->setWordWrap(true); //设置自动换行

    ui->listWidget->clear(); // 清空 QListWidget
    onselectionChanged();  //初始化时先显示当日的文本信息
}

deadlinedistri::~deadlinedistri()
{
    delete ui;
}

void deadlinedistri::onselectionChanged()
{

    QDate currentDate = ui->MyCalendar->selectedDate();
    ui->MyCalendar->onPageChanged(currentDate.year(), currentDate.month());//只要选择的日期更换就重绘页面
    int taskcount=oper1->GetDeadline(currentDate.toString(Qt::ISODate));//存储ddl数量
    ui->MyCalendar->setddlLabelText();
    ui->listWidget->clear(); // 清空 QListWidget

    for(int i=0;i<taskcount;++i)
    {
        QString sdate,edate,content;
        int* n = new int;
        int finish;
        int *list=oper1->GetLongtermList_by_edate(n,currentDate);
        oper1->GetLongterm(list[i],sdate,edate,content,finish);
        ui->listWidget->addItem("任务"+QString::number(i + 1) + "： " + content);
        ui->listWidget->addItem("起始日期： "+sdate+"\n");
        //ui->listWidget->addItem(edate);
    }
}
