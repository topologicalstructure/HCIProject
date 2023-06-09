#include "smallwindows.h"
#include "ui_smallwindows.h"
#include "mainwindow.h"

smallwindows::smallwindows(QWidget *parent, SqliteOperator* Oper, QStandardItemModel* model) :
    QMainWindow(parent),
    ui(new Ui::smallwindows)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    screen_width=QGuiApplication::primaryScreen()->geometry().width();
    ui->setupUi(this);
    request.setUrl(url);
    connect(&manager,&QNetworkAccessManager::finished,this,&smallwindows::GetWeather);
    manager.get(request);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage()));
    timer->start(10000);
    oper = Oper;
    oper=new SqliteOperator;
    todayWorks = model;
    //设置按钮图标
    QIcon icon1,icon2;
    ui->workView->setModel(todayWorks);
    icon1.addFile(tr("icons8-full-screen-100.png"));
    icon2.addFile(tr("icons8-close-100.png"));
    ui->becomebig->setIcon(icon1);
    ui->becomebig->setIconSize(QSize(50,50));
    ui->CloseButton->setIcon(icon2);
    ui->CloseButton->setIconSize(QSize(30,30));
    ui->CloseButton->setStyleSheet("background-color:rgba(0,0,0,0)");
    workDelegate* myDelegate = new workDelegate(ui->workView);
    ui->workView->setItemDelegate(myDelegate);
    ui->workView->setModel(todayWorks);
    connect(myDelegate,SIGNAL(finishTodayWork(int)),ui->workView,SIGNAL(DfinishWork(int)));
    //connect(ui->widget,SIGNAL(worksChange()),this,SLOT(ModelUpdate()));     //用户输入新任务，更新Model
    connect(ui->workView,SIGNAL(DdeleteWork(int)),this,SLOT(deleteWork(int)));
    connect(ui->workView,SIGNAL(DfinishWork(int)),this,SLOT(finishWork(int)));
    connect(ui->workView,SIGNAL(DupdateWork(int,QString)),this,SLOT(updateWork(int,QString)));  //用户编辑任务，更新数据库
    connect(ui->widget_2,SIGNAL(CreateSuccess()),this, SLOT(GetCreat()));
}

smallwindows::~smallwindows()
{
    delete ui;
}

void smallwindows::mousePressEvent(QMouseEvent *event)
{
    ui->widget_2->setVisible(1);
    if(event->button() == Qt::LeftButton){
        mouse_is_press=1;
        mouse_posit=event->globalPos()-pos();
    }
}

void smallwindows::mouseMoveEvent(QMouseEvent *event)
{
    if(!mouse_is_press){
        return;
    }
    if(event->globalPos().x()<5){
        win_hide=1;
    }
    else if(event->globalPos().y()<5){
        win_hide=2;
    }
    else if(event->globalPos().x()>screen_width-5){
        win_hide=3;
    }
    else{
        win_hide=0;
    }
    if(win_hide==0){
        move(event->globalPos()-mouse_posit);
    }
    else if(win_hide==1){
        move(0,event->globalPos().y()-mouse_posit.y());
    }
    else if(win_hide==2){
        move(event->globalPos().x()-mouse_posit.x(),0);
    }
    else{
        move(screen_width-width(),event->globalPos().y()-mouse_posit.y());
    }
    mouse_posit=event->globalPos()-pos();
}

void smallwindows::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_is_press=0;
}

void smallwindows::HideWindow()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(x(), y(), width(), height()));
    if(win_hide==1){
        animation->setEndValue(QRect(2-width(), y(), width(), height()));
    }
    else if(win_hide==2){
        animation->setEndValue(QRect(x(), 2-height(), width(), height()));
    }
    else {
        animation->setEndValue(QRect(screen_width-2, y(), width(), height()));
    }
    animation->start();
}

void smallwindows::ShowWindow()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(x(), y(), width(), height()));
    if(win_hide==1){
        animation->setEndValue(QRect(0, y(), width(), height()));
    }
    else if(win_hide==2){
        animation->setEndValue(QRect(x(), 0, width(), height()));
    }
    else {
        animation->setEndValue(QRect(screen_width-width(), y(), width(), height()));
    }
    animation->start();
}

void smallwindows::enterEvent(QEvent *event)
{
    //ui->widget_2->setVisible(1);
    if(win_hide){
        ShowWindow();
    }
}

void smallwindows::leaveEvent(QEvent *event)
{
    /*if(!ui->widget_2->isExpand1&&!ui->widget_2->isExpand2){
        ui->widget_2->setVisible(0);
    }*/
    //ui->widget_2->setVisible(0);
    if(win_hide){
        HideWindow();
    }
}

bool smallwindows::event(QEvent * event)
{
    if (QEvent::WindowDeactivate == event->type())
    {
        ui->widget_2->setVisible(0);
    }
    return QWidget::event(event);
}

void smallwindows::on_CloseButton_clicked()
{
    this->close();
}

void smallwindows::on_becomebig_clicked()
{
    MainWindow* bigwin=new MainWindow();
    this->hide();
    bigwin->show();
}

void smallwindows::GetWeather(QNetworkReply *reply)
{
    QByteArray array = reply->readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(array,&error);
    if(error.error !=QJsonParseError::NoError)
    {
        qDebug("json error");
        return ;
    }
    QJsonObject obj = doc.object();
    QString code =obj["results"].toArray()[0].toObject()["now"].toObject()["code"].toString();
    QString temperature =obj["results"].toArray()[0].toObject()["now"].toObject()["temperature"].toString();
    QString city =obj["results"].toArray()[0].toObject()["location"].toObject()["name"].toString();
    QString text =obj["results"].toArray()[0].toObject()["now"].toObject()["text"].toString();
    ui->weawid->code=code;
    ui->weawid->tempe=temperature;
    ui->weawid->wea=text;
    ui->weawid->Update();
}

void smallwindows::slotCountMessage()
{
    manager.get(request);
}

bool finishCmp2(const QStandardItem *left, const QStandardItem *right)   //未完成的在前面，完成的在后面
{
    if(left->data(Qt::UserRole + 2).toInt() < right->data(Qt::UserRole + 2).toInt()){
        return 1;
    }
    else if(left->data(Qt::UserRole + 2).toInt() > right->data(Qt::UserRole + 2).toInt()){
        return 0;
    }
    else{
        return left->data(Qt::UserRole + 3).toInt() < right->data(Qt::UserRole + 3).toInt();
    }
}

void smallwindows::sort(QStandardItemModel* model)
{
    oper=new SqliteOperator;
    QList<QStandardItem*> list;
    for(int i = 0; i < model->rowCount(); i++)
        list.append(model->item(i,0)->clone());
    std::sort(list.begin(),list.end(),finishCmp2);
    //delete todayWorks;
    todayWorks = new QStandardItemModel(this);
    qDebug()<<"排序了！！";
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

void smallwindows::ModelUpdate()
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

void smallwindows::updateWork(int id, QString nContent)       //更新编辑内容
{
    oper->ChangeToday(id,nContent);
}

void smallwindows::deleteWork(int id)                  //删除任务
{
    qDebug()<<"删掉了id= "<<id<<" 的任务？";
    oper->DeleteToday(id);
}

void smallwindows::finishWork(int id)
{
    qDebug()<<"id为 "<<id<<" 的任务完成了";
    oper->FinishToday(id, 1);

    sort(todayWorks);

}

void smallwindows::setButton()
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

void smallwindows::GetCreat()
{
    ui->setupUi(this);
    oper=new SqliteOperator;
    todayWorks = new QStandardItemModel();
    ModelUpdate();
    //设置按钮图标
    QIcon icon1,icon2;
    ui->workView->setModel(todayWorks);
    icon1.addFile(tr("icons8-full-screen-100.png"));
    icon2.addFile(tr("icons8-close-100.png"));
    ui->becomebig->setIcon(icon1);
    ui->becomebig->setIconSize(QSize(50,50));
    ui->CloseButton->setIcon(icon2);
    ui->CloseButton->setIconSize(QSize(30,30));
    ui->CloseButton->setStyleSheet("background-color:rgba(0,0,0,0)");
    workDelegate* myDelegate = new workDelegate(ui->workView);
    ui->workView->setItemDelegate(myDelegate);
    ui->workView->setModel(todayWorks);
    connect(myDelegate,SIGNAL(finishTodayWork(int)),ui->workView,SIGNAL(DfinishWork(int)));
    //connect(ui->widget,SIGNAL(worksChange()),this,SLOT(ModelUpdate()));     //用户输入新任务，更新Model
    connect(ui->workView,SIGNAL(DdeleteWork(int)),this,SLOT(deleteWork(int)));
    connect(ui->workView,SIGNAL(DfinishWork(int)),this,SLOT(finishWork(int)));
    connect(ui->becomebig,SIGNAL(clicked(bool)),this,SLOT(on_becomebig_clicked()));
    connect(ui->CloseButton,SIGNAL(clicked(bool)),this,SLOT(on_CloseButton_clicked()));
    connect(ui->workView,SIGNAL(DfinishWork(int)),this,SLOT(finishWork(int)));
    connect(ui->workView,SIGNAL(DupdateWork(int,QString)),this,SLOT(updateWork(int,QString)));  //用户编辑任务，更新数据库
    connect(ui->widget_2,SIGNAL(CreateSuccess()),this, SLOT(GetCreat()));
    manager.get(request);
}
