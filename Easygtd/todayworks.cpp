#include "todayworks.h"
#include "ui_todayworks.h"
#include "workdisplay.h"
#include <QDebug>
#include <QList>

Todayworks::Todayworks(QWidget *parent, SqliteOperator* Oper) :
    QWidget(parent),
    ui(new Ui::Todayworks)
{
    ui->setupUi(this);
    oper = Oper;

    todayWorks = new QStandardItemModel();
    ModelUpdate();

//    myProxyModel = new QSortFilterProxyModel(this);
//    myProxyModel->setSourceModel(todayWorks);
//    myProxyModel->setSortRole(Qt::UserRole + 2);

    ui->workView->setModel(todayWorks);
    //connect(ui->widget,SIGNAL(worksChange()),this,SLOT(ModelUpdate()));     //用户输入新任务，更新Model
    connect(ui->workView,SIGNAL(DdeleteWork(int)),this,SLOT(deleteWork(int)));
    connect(ui->workView,SIGNAL(DfinishWork(int)),this,SLOT(finishWork(int)));
    connect(ui->workView,SIGNAL(DupdateWork(int,QString)),this,SLOT(updateWork(int,QString)));  //用户编辑任务，更新数据库
}

QStandardItemModel* Todayworks::getTodayWorks()
{
    return todayWorks;
}

bool finishCmp(const QStandardItem *left, const QStandardItem *right)   //未完成的在前面，完成的在后面
{
    return left->data(Qt::UserRole + 2).toInt() <= right->data(Qt::UserRole + 2).toInt();
}

void Todayworks::sort(QStandardItemModel* model)
{
    oper=new SqliteOperator;
    QList<QStandardItem*> list;
    for(int i = 0; i < model->rowCount(); i++)
        list.append(model->item(i,0)->clone());
    std::sort(list.begin(),list.end(),finishCmp);
    //delete todayWorks;
    todayWorks = new QStandardItemModel(this);
    qDebug()<<"奶奶的我排序了啊！！";
    for(int i = 0; i < list.size(); i++)
        todayWorks->setItem(i,list.at(i));
    ui->workView->setModel(todayWorks);
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

void Todayworks::ModelUpdate()
{
    todayWorks->clear();
    int worksCount = 0;
    int* IDs = oper->GetTodayList(&worksCount);
    QString content;
    int finish = 0;
    for(int i = 0; i < worksCount; i++)
    {
        QStandardItem *Item = new QStandardItem();
        oper->GetToday(IDs[i],content,finish);
        Item->setData(content,Qt::UserRole + 1);     //1：任务内容
        Item->setData(finish,Qt::UserRole + 2);      //2：任务状态（未完成/完成）
        Item->setData(IDs[i],Qt::UserRole + 3);      //3：任务ID
        todayWorks->appendRow(Item);
    }
    sort(todayWorks);
    qDebug()<<"worksCount = "<<worksCount;
    qDebug()<<"data hass been updated!";
}

void Todayworks::updateWork(int id, QString nContent)       //更新编辑内容
{
    oper->ChangeToday(id,nContent);
}

void Todayworks::deleteWork(int id)                  //删除任务
{
    qDebug()<<"删掉了id= "<<id<<" 的任务？";
    oper->DeleteToday(id);
}

void Todayworks::finishWork(int id)
{
    qDebug()<<"id为 "<<id<<" 的任务完成了";
    oper->FinishToday(id, 1);

    sort(todayWorks);

}

void Todayworks::setButton()
{
    QString normal, press, hover;
    normal = "./normal.png";
    press= "./press.png";
    hover = "./hover.png";
    for(int i = 0; i < todayWorks->rowCount(); i++)
    {
        workDoneButton* button = new workDoneButton(ui->workView,normal,hover,press,todayWorks->index(i,0).data(Qt::UserRole + 3).toInt());
        button->setFixedSize(30, 30);
        ui->workView->setIndexWidget(todayWorks->index(i,0), button);

    }
    for(int i = 0; i < todayWorks->rowCount(); i++)
    {
        QRect rect = ui->workView->visualRect(todayWorks->index(i,0));
        ui->workView->indexWidget(todayWorks->index(i,0))->setGeometry(rect.right() - 30,rect.top(),30,30);
    }
}

Todayworks::~Todayworks()
{
    delete ui;
}
