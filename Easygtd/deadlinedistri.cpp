#include "deadlinedistri.h"
#include "ui_deadlinedistri.h"
#include "CalendarWidget.h"
#include <QDate>
#include <QString>

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
    ui->textBrowser->setFontPointSize(20);
    QFont font("Arial", 15);  // 创建字体对象并设置字号
    ui->listWidget->setFont(font);      // 设置项目的字体
    ui->listWidget->setWordWrap(true); //设置自动换行

    ui->listWidget->clear(); // 清空 QListWidget
}

deadlinedistri::~deadlinedistri()
{
    delete ui;
}

void deadlinedistri::onselectionChanged()
{

    QDate currentDate = ui->MyCalendar->selectedDate();
    int taskcount=oper->GetDeadline(currentDate.toString(Qt::ISODate));//存储ddl数量
    ui->textBrowser->setText(QString::number(taskcount)+" 个任务的截止日期是 "+currentDate.toString(Qt::ISODate));
    ui->textBrowser->setAlignment(Qt::AlignCenter); // 设置文本居中对齐

    ui->listWidget->clear(); // 清空 QListWidget

    for(int i=0;i<taskcount;++i)
    {
        QString sdate,edate,content;
        int* n = new int;
        int finish;
        int *list=oper->GetLongtermList_by_edate(n,currentDate);
        oper->GetLongterm(list[i],sdate,edate,content,finish);
        ui->listWidget->addItem("任务"+QString::number(i + 1) + "： " + content);
        ui->listWidget->addItem("起始日期： "+sdate+"\n");
        //ui->listWidget->addItem(edate);
    }
}

