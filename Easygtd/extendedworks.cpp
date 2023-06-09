#include "extendedworks.h"
#include "ui_extendedworks.h"
#include "workdisplay.h"
#include <QDebug>
#include <QList>

extendedworks::extendedworks(QWidget *parent, SqliteOperator* Oper) :
    QWidget(parent),
    ui(new Ui::extendedworks)
{
    ui->setupUi(this);
    oper = Oper;
    extendedWorks = new QStandardItemModel();
    ModelUpdate();

    workDelegateForLTW* myDelegate = new workDelegateForLTW(ui->workView);
    ui->workView->setItemDelegate(myDelegate);
    ui->workView->setModel(extendedWorks);
    connect(myDelegate,SIGNAL(finishLongtermWork(int)),ui->workView,SIGNAL(DfinishWork(int)));

    //connect(ui->widget,SIGNAL(worksChange()),this,SLOT(ModelUpdate()));     //用户输入新任务，更新Model
    connect(ui->workView,SIGNAL(DdeleteWork(int)),this,SLOT(deleteWork(int)));
    connect(ui->workView,SIGNAL(DfinishWork(int)),this,SLOT(finishWork(int)));
    connect(ui->workView,SIGNAL(DupdateWork(int,QString)),this,SLOT(updateWork(int,QString)));  //用户编辑任务，更新数据库
}

bool finishCmp(const QStandardItem *left, const QStandardItem *right);   //未完成的在前面，完成的在后面
//{
//    if(left->data(Qt::UserRole + 2).toInt() < right->data(Qt::UserRole + 2).toInt()){
//        return 1;
//    }
//    else if(left->data(Qt::UserRole + 2).toInt() > right->data(Qt::UserRole + 2).toInt()){
//        return 0;
//    }
//    else{
//        return left->data(Qt::UserRole + 3).toInt() < right->data(Qt::UserRole + 3).toInt();
//    }
//}

void extendedworks::sort(QStandardItemModel* model)
{
    oper=new SqliteOperator;
    QList<QStandardItem*> list;
    for(int i = 0; i < model->rowCount(); i++)
        list.append(model->item(i,0)->clone());
    std::sort(list.begin(),list.end(),finishCmp);
    //delete todayWorks;
    extendedWorks = new QStandardItemModel(this);
    qDebug()<<"排序了！！";
    for(int i = 0; i < list.size(); i++)
        extendedWorks->setItem(i,list.at(i));
    ui->workView->setModel(extendedWorks);
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

void extendedworks::ModelUpdate()
{
    extendedWorks->clear();
    int worksCount = 0;
    int* IDs = oper->GetExtendedList(&worksCount);
    QString content, sdate, edate;
    int finish = 0;
    for(int i = 0; i < worksCount; i++)
    {
        QStandardItem *Item = new QStandardItem();
        oper->GetExtended(IDs[i],sdate,edate,content,finish);
        Item->setData(content,Qt::UserRole + 1);     //1：任务内容
        Item->setData(finish,Qt::UserRole + 2);      //2：任务状态（未完成/完成）
        Item->setData(IDs[i],Qt::UserRole + 3);      //3：任务ID
        Item->setData(sdate,Qt::UserRole + 4);       //4：开始日期
        Item->setData(edate,Qt::UserRole + 5);       //5：结束日期
        extendedWorks->appendRow(Item);
    }
    sort(extendedWorks);
    qDebug()<<"worksCount = "<<worksCount;
    qDebug()<<"data hass been updated!";
}

void extendedworks::updateWork(int id, QString nContent)       //更新编辑内容
{
    QString content, sdate, edate;
    int finish = 0;
    oper->GetExtended(id,sdate,edate,content,finish);
    oper->ChangeExtended(id,sdate,edate,nContent);
}

void extendedworks::deleteWork(int id)                  //删除任务
{
    qDebug()<<"删掉了id= "<<id<<" 的任务？";
    oper->DeleteExtended(id);
}

void extendedworks::finishWork(int id)
{
    qDebug()<<"id为 "<<id<<" 的任务完成了";
    oper->FinishExtended(id, 1);

    sort(extendedWorks);

}

extendedworks::~extendedworks()
{
    delete ui;
}
