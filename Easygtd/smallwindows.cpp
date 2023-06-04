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
    /*
     * 更新天气信息
    */
    //QString str=city+":"+text+","+temperature+"℃";
    ui->weawid->code=code;
    ui->weawid->tempe=temperature;
    ui->weawid->wea=text;
    ui->weawid->Update();
    //ui->label->setText(str);
    //qDebug()<<city+":"+text+","+temperature+"℃";
}

void smallwindows::slotCountMessage()
{
    manager.get(request);
}
