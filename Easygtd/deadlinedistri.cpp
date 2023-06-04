#include "deadlinedistri.h"
#include "ui_deadlinedistri.h"
#include "CalendarWidget.h"
#include <QDate>
#include <QString>
#include <QPainter>

SqliteOperator* oper1=new SqliteOperator;

deadlinedistri::deadlinedistri(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deadlinedistri)
{
    ui->setupUi(this);

    connect(ui->MyCalendar, &QCalendarWidget::selectionChanged, this, &deadlinedistri::onselectionChanged);//用户修改选中的日期动作关联
    QFont font("Arial", 15);  // 创建字体对象并设置字号
    ui->listWidget->setFont(font);      // 设置项目的字体
    ui->listWidget->setWordWrap(true); //设置自动换行

    ui->listWidget->clear(); // 清空 QListWidget
    onselectionChanged();//首次初始化一下今天的显示
}

deadlinedistri::~deadlinedistri()
{
    delete ui;
}

void deadlinedistri::onselectionChanged()
{
    QDate currentDate = ui->MyCalendar->selectedDate();
    oper1=new SqliteOperator;

    int taskcount=oper1->GetDeadline(currentDate.toString(Qt::ISODate));//存储ddl数量

    ui->MyCalendar->setddlLabelText();

    ui->listWidget->clear(); // 清空 QListWidget
    for(int i=0;i<taskcount;++i)
    {
        QString sdate,edate,content;
        int* n = new int;
        int finish;
        oper1=new SqliteOperator;
        int *list=oper1->GetLongtermList_by_edate(n,currentDate);
        oper1->GetLongterm(list[i],sdate,edate,content,finish);
        ui->listWidget->addItem("任务"+QString::number(i + 1) + "： " + content);
        ui->listWidget->addItem("起始日期： "+sdate+"\n");
        //ui->listWidget->addItem(edate);
    }
}
