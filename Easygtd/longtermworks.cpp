#include "longtermworks.h"
#include "ui_longtermworks.h"
#include "workdisplay.h"
#include <QDebug>
#include <QList>

longtermworks::longtermworks(QWidget *parent, SqliteOperator* Oper) :
    QWidget(parent),
    ui(new Ui::longtermworks)
{
    ui->setupUi(this);
    oper = Oper;

    longtermWorks = new QStandardItemModel();
    ModelUpdate();

    workDelegateForLTW* myDelegate = new workDelegateForLTW(ui->workView);
    ui->workView->setItemDelegate(myDelegate);
    ui->workView->setModel(longtermWorks);
    connect(myDelegate,SIGNAL(finishLongtermWork(int)),ui->workView,SIGNAL(DfinishWork(int)));

    //connect(ui->widget,SIGNAL(worksChange()),this,SLOT(ModelUpdate()));     //用户输入新任务，更新Model
    connect(ui->workView,SIGNAL(DdeleteWork(int)),this,SLOT(deleteWork(int)));
    connect(ui->workView,SIGNAL(DfinishWork(int)),this,SLOT(finishWork(int)));
    connect(ui->workView,SIGNAL(DupdateWork(int,QString)),this,SLOT(updateWork(int,QString)));  //用户编辑任务，更新数据库

}
bool finishCmp1(const QStandardItem *left, const QStandardItem *right)   //未完成的在前面，完成的在后面
{
    uint stime1 = QDateTime::fromString((left->data(Qt::UserRole + 4).toString()+ QString(" 00:00:00")), "yyyy-MM-dd hh:mm:ss").toTime_t();
    uint etime1 = QDateTime::fromString((left->data(Qt::UserRole + 5).toString()+ QString(" 23:59:59")), "yyyy-MM-dd hh:mm:ss").toTime_t();
    uint stime2 = QDateTime::fromString((right->data(Qt::UserRole + 4).toString()+ QString(" 00:00:00")), "yyyy-MM-dd hh:mm:ss").toTime_t();
    uint etime2 = QDateTime::fromString((right->data(Qt::UserRole + 5).toString()+ QString(" 23:59:59")), "yyyy-MM-dd hh:mm:ss").toTime_t();
    uint ctime = QDateTime::currentDateTime().toTime_t();
    double proportion1 = 0,proportion2 = 0;
    if(etime1 != stime1){
        uint currentLong = ctime - stime1, totalLong = etime1 - stime1;
        if(ctime<stime1){
            proportion1=0;
        }
        else{
            proportion1 = (double)currentLong / totalLong;
        }
        if(proportion1>1.0){
            proportion1=1.0;
        }
    }
    else{
        if(ctime - stime1 > 0){
            proportion1 = 1;
        }
        if(ctime<stime1){
            proportion1=0;
        }
    }
    if(etime2 != stime2){
        uint currentLong = ctime - stime2, totalLong = etime2 - stime2;
        if(ctime<stime2){
            proportion2=0;
        }
        else{
            proportion2 = (double)currentLong / totalLong;
        }
        if(proportion2>1.0){
            proportion2=1.0;
        }
    }
    else{
        if(ctime - stime2 > 0){
            proportion2 = 1;
        }
        if(ctime<stime2){
            proportion2=0;
        }
    }
    if(left->data(Qt::UserRole + 2).toInt() < right->data(Qt::UserRole + 2).toInt()){
        return 1;
    }
    else if(left->data(Qt::UserRole + 2).toInt() > right->data(Qt::UserRole + 2).toInt()){
        return 0;
    }
    else{
        return proportion1 > proportion2;
    }
}

void longtermworks::sort(QStandardItemModel* model)
{
    oper=new SqliteOperator;
    QList<QStandardItem*> list;
    for(int i = 0; i < model->rowCount(); i++)
        list.append(model->item(i,0)->clone());
    std::sort(list.begin(),list.end(),finishCmp1);
    //delete todayWorks;
    longtermWorks = new QStandardItemModel(this);
    qDebug()<<"排序了！！";
    for(int i = 0; i < list.size(); i++)
        longtermWorks->setItem(i,list.at(i));
    ui->workView->setModel(longtermWorks);
    qDebug()<<"寄了吗？";
    /*QStandardItemModel *model1 = new QStandardItemModel(this);
    for (int i = 0 ; i < model->rowCount() ; i++){
        model1->appendRow(model->item(i,0)->clone());
    }
    model1->sort(Qt::UserRole +2,Qt::AscendingOrder);
    delete todayWorks;
    todayWorks = new QStandardItemModel(this);
    todayWorks=model1;
    ui->workView->setModel(todayWorks);
    emit SortSuccess();
    qDebug()<<"排序完成";*/
}

void longtermworks::ModelUpdate()
{
    longtermWorks->clear();
    int worksCount = 0;
    int* IDs = oper->GetLongtermList(&worksCount);
    QString content, sdate, edate;
    int finish = 0;
    for(int i = 0; i < worksCount; i++)
    {
        QStandardItem *Item = new QStandardItem();
        oper->GetLongterm(IDs[i],sdate,edate,content,finish);
        Item->setData(content,Qt::UserRole + 1);     //1：任务内容
        Item->setData(finish,Qt::UserRole + 2);      //2：任务状态（未完成/完成）
        Item->setData(IDs[i],Qt::UserRole + 3);      //3：任务ID
        Item->setData(sdate,Qt::UserRole + 4);       //4：开始日期
        Item->setData(edate,Qt::UserRole + 5);       //5：结束日期
        longtermWorks->appendRow(Item);
    }
    sort(longtermWorks);
    qDebug()<<"worksCount = "<<worksCount;
    qDebug()<<"data hass been updated!";
}

void longtermworks::updateWork(int id, QString nContent)       //更新编辑内容
{
    QString content, sdate, edate;
    int finish = 0;
    oper->GetLongterm(id,sdate,edate,content,finish);
    oper->ChangeLongterm(id,sdate,edate,nContent);
}

void longtermworks::deleteWork(int id)                  //删除任务
{
    qDebug()<<"删掉了id= "<<id<<" 的任务？";
    oper->DeleteLongterm(id);
}

void longtermworks::finishWork(int id)
{
    qDebug()<<"id为 "<<id<<" 的任务完成了";
    oper->FinishLongterm(id, 1);

    sort(longtermWorks);

}


longtermworks::~longtermworks()
{
    delete ui;
}
