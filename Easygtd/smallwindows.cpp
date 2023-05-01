#include "smallwindows.h"
#include "ui_smallwindows.h"
#include "mainwindow.h"

smallwindows::smallwindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::smallwindows)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    screen_width=QGuiApplication::primaryScreen()->geometry().width();
    ui->setupUi(this);
}

smallwindows::~smallwindows()
{
    delete ui;
}

void smallwindows::mousePressEvent(QMouseEvent *event)
{
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
    if(win_hide){
        ShowWindow();
    }
}

void smallwindows::leaveEvent(QEvent *event)
{
    if(win_hide){
        HideWindow();
    }
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
