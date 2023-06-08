#include "expectedworks.h"
#include "ui_expectedworks.h"
#include "workdisplay.h"
#include <QDebug>
#include <QList>

ExpectedWorks::ExpectedWorks(QWidget *parent, SqliteOperator* Oper) :
    QWidget(parent),
    ui(new Ui::ExpectedWorks)
{
    ui->setupUi(this);
    oper = Oper;

    expectedWorks = new QStandardItemModel();
    ModelUpdate();

    //    myProxyModel = new QSortFilterProxyModel(this);
    //    myProxyModel->setSourceModel(todayWorks);
    //    myProxyModel->setSortRole(Qt::UserRole + 2);

    workDelegateForFW* myDelegate = new workDelegateForFW(ui->workView);
    ui->workView->setItemDelegate(myDelegate);
    ui->workView->setModel(expectedWorks);

    //connect(ui->widget,SIGNAL(worksChange()),this,SLOT(ModelUpdate()));     //用户输入新任务，更新Model
    connect(ui->workView,SIGNAL(DdeleteWork(int)),this,SLOT(deleteWork(int)));
    connect(ui->workView,SIGNAL(DupdateWork(int,QString)),this,SLOT(updateWork(int,QString)));  //用户编辑任务，更新数据库
}

void ExpectedWorks::ModelUpdate()
{
    expectedWorks->clear();
    int worksCount = 0;
    int* IDs = oper->GetExpectedList(&worksCount);
    QString content, date;
    int finish = 0;
    for(int i = 0; i < worksCount; i++)
    {
        QStandardItem *Item = new QStandardItem();
        oper->GetExpected(IDs[i],date,content,finish);
        Item->setData(content,Qt::UserRole + 1);     //1：任务内容
        Item->setData(finish,Qt::UserRole + 2);      //2：任务状态（未完成/完成）
        Item->setData(IDs[i],Qt::UserRole + 3);      //3：任务ID
        Item->setData(date,Qt::UserRole + 4);      //4：预定日期
        expectedWorks->appendRow(Item);
    }
//    sort(todayWorks);
    qDebug()<<"worksCount = "<<worksCount;
    qDebug()<<"data hass been updated!";
}

void ExpectedWorks::updateWork(int id, QString nContent)       //更新编辑内容
{
    QString content, date;
    int finish = 0;
    oper->GetExpected(id,date,content,finish);
    oper->ChangeExpected(id,date,nContent);
}

void ExpectedWorks::deleteWork(int id)                  //删除任务
{
    qDebug()<<"删掉了id= "<<id<<" 的未来任务？";
    oper->DeleteExpected(id);
}



ExpectedWorks::~ExpectedWorks()
{
    delete ui;
}
