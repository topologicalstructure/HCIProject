#include "workdisplay.h"
#include <QPainter>
#include <QPainterPath>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QMouseEvent>
#include <QBitmap>
#include <QMenu>
#include <QRect>
#include <QCursor>
#include <QPoint>
#include <QDateTime>
#include <QTime>
const int workDelegateHeight = 40;
const int buttonSize = 30;

workDisplay::workDisplay(QWidget* parent) : QListView(parent)
{
    this->setEditTriggers(QAbstractItemView::DoubleClicked);    //设置控件编辑：双击
    this->setDragEnabled(false);                                 //设置拖动
    //this->setDragDropMode(QAbstractItemView::InternalMove);     //设置移动
    this->setMouseTracking(true);                               //设置鼠标追踪
    this->setSelectionMode(QAbstractItemView::SingleSelection); //设置单击选中

    menu = new QMenu(this);                                     //添加右键菜单
    workDelete = new QAction("删除任务",this);
    menu->addAction(workDelete);
    connect(workDelete,SIGNAL(triggered(bool)),this,SLOT(deleteWorkinModel()));
    //链接任务完成信号再发送新信号
//    connect(myDelegate,SIGNAL(finishTodayWork(int)),this,SIGNAL(DfinishWork(int)));

}

void workDisplay::contextMenuEvent(QContextMenuEvent *event)
{
    if(this->selectionModel()->selectedIndexes().isEmpty())     //列表为空，直接返回
        return;
    Q_UNUSED(event);
    menu->clear();
    menu->addAction(workDelete);
    menu->exec(QCursor::pos());  //在当前鼠标处
}

void workDisplay::deleteWorkinModel()
{
    int ID = this->currentIndex().data(Qt::UserRole + 3).toInt();
    //qDebug()<<"即将要删掉id= "<<ID<<" 的任务";
    emit this->DdeleteWork(ID);     //发送任务删除信号给TodayWorks
    this->model()->removeRow(this->currentIndex().row());   //删除当前任务
}

//void workDisplay::mouseMoveEvent(QMouseEvent *event)
//{
//    //qDebug()<<"???";
//    if(event->pos().x() + buttonSize >= this->width())
//    {
//        qDebug()<<"???我按钮呢";
//        this->repaint();
//    }
//}

//void workDisplay::setButton()
//{
//    QString normal, press, hover;
//    normal = "./normal.png";
//    press= "./press.png";
//    hover = "./hover.png";
//    //qDebug()<<"这里还没问题？";
//    for(int i = 0; i < this->model()->rowCount(); i++)
//    {
//        workDoneButton* button = new workDoneButton(0,normal,hover,press,this->model()->index(i,0).data(Qt::UserRole + 3).toInt());
//        button->setFixedSize(buttonSize, buttonSize);
//        this->setIndexWidget(this->model()->index(i,0), button);
//        QRect rect = this->visualRect(this->model()->index(i,0));
//        button->move(rect.right() - buttonSize,rect.top());
//    }
//}


workDelegate::workDelegate(QWidget *parent) : QStyledItemDelegate(parent)
{
    normal = "./normal.png";
    press= "./press.png";
    hover = "./hover.png";
    isFinish = 0;
}

QSize workDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    return QSize(option.rect.width(),workDelegateHeight);
}

bool workDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        QRectF butRect;
        butRect.setX(option.rect.width() - buttonSize);
        butRect.setY(option.rect.y() + (option.rect.height() - buttonSize)/2);
        butRect.setWidth(buttonSize);
        butRect.setHeight(buttonSize);
        QMouseEvent *mevent = static_cast<QMouseEvent*>(event);
        if(butRect.contains(mevent->pos()))
        {
            qDebug()<<"按钮被按下";
            isFinish = 1;
        }
        else
            isFinish = 0;
    }
    else if(event->type()==QEvent::MouseButtonRelease)
    {
        qDebug()<<"鼠标松开了";
        QRectF butRect;
        butRect.setX(option.rect.width()-buttonSize);
        butRect.setY(option.rect.y() + (option.rect.height() - buttonSize)/2);
        butRect.setWidth(buttonSize);
        butRect.setHeight(buttonSize);
        QMouseEvent *mevent = static_cast<QMouseEvent*>(event);
        if(butRect.contains(mevent->pos()) && isFinish)
        {
            qDebug()<<"任务完成了";
            model->setData(index, 1, Qt::UserRole + 2);                     //完成任务
            emit finishTodayWork(index.data(Qt::UserRole + 3).toInt());     //发送任务完成信号
        }
    }


    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

void workDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return;

    painter->save();
    QRectF textRect, butRect;
    textRect.setX(option.rect.x());
    textRect.setY(option.rect.y());
    textRect.setWidth(option.rect.width() - buttonSize);
    textRect.setHeight(option.rect.height());

    butRect.setX(textRect.right());
    butRect.setY(textRect.y() + (option.rect.height() - buttonSize)/2);
    butRect.setWidth(buttonSize);
    butRect.setHeight(buttonSize);
    if(index.data(Qt::UserRole + 2).toInt())        //已完成的任务
    {
        painter->setPen(QPen(Qt::green));
        painter->setBrush(QBrush(QColor(0,0,0,15)));
        painter->drawRect(option.rect);
        QFont font("Microsoft Yahei", 10);
        font.setStrikeOut(true);
        painter->setFont(font);
        painter->drawText(textRect, Qt::AlignVCenter,index.data(Qt::UserRole + 1).toString());
        painter->restore();
        return;
    }

    if(option.state.testFlag(QStyle::State_MouseOver))  //鼠标悬浮
    {
        painter->setPen(QPen(QColor(255,0,0,100)));
        painter->setBrush(QBrush(QColor(0,0,0,60)));
        //painter->drawPath(path);
        painter->drawRect(option.rect);
        painter->setPen(QPen(Qt::white));
    }
//    else if(option.state.testFlag(QStyle::State_Selected))       //被选中时
//    {

//    }
    else
    {
        painter->setPen(QPen(Qt::darkBlue));
        painter->setBrush(QBrush(QColor(0,0,0,15)));
        painter->drawRect(option.rect);
    }

    //绘制按钮
    QPoint pos = qobject_cast<QWidget*>(this->parent())->mapFromGlobal(QCursor().pos());
    if(option.state.testFlag(QStyle::State_Active) && butRect.contains(pos))
    {
        QPixmap pic;
        pic.load(press);
        pic = pic.scaled(buttonSize,buttonSize);
        painter->drawPixmap(butRect.topLeft(), pic);
    }
    else
    {
        QPixmap pic;
        pic.load(hover);
        pic = pic.scaled(buttonSize,buttonSize);
        painter->drawPixmap(butRect.topLeft(), pic);
    }


    painter->setFont(QFont("Microsoft Yahei", 10));
    painter->drawText(textRect, Qt::AlignVCenter,index.data(Qt::UserRole + 1).toString());

    painter->restore();
}

QWidget* workDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.data(Qt::UserRole + 2).toInt())        //已完成的任务无需编辑
        return NULL;
    qDebug()<<"编辑器被创建了！";
    QLineEdit* workEdit = new QLineEdit(index.data(Qt::UserRole + 1).toString(), parent);
    workEdit->setStyleSheet("background: rgb(200,200,200); border-width:0; border-style:outset");
    QFont font;
    font.setPointSize(10); //字号大小
    font.setFamily("Microsoft Yahei"); //字体样式
    font.setBold(false);
    workEdit->setFont(font);
    workEdit->deselect();
    return workEdit;
}

void workDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    static_cast<QLineEdit*>(editor)->setText(index.data(Qt::UserRole + 1).toString());

}

void workDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(!static_cast<QLineEdit*>(editor)->text().isEmpty())      //文本框不为空即进行更新
    {
        qDebug()<<"数据被更新拉！";
        model->setData(index, static_cast<QLineEdit*>(editor)->text(),Qt::UserRole + 1);
        workDisplay* view = qobject_cast<workDisplay*>(this->parent());
        view->isChanged = 1;
        view->nContent = static_cast<QLineEdit*>(editor)->text();
        view->changedItem = index;
        emit view->DupdateWork(index.data(Qt::UserRole + 3).toInt(),view->nContent);
    }

}

void workDelegate::updateEditorGeometry(QWidget *editor, const QStyleOption &option, const QModelIndex &index)
{
    Q_UNUSED(index);
    editor->setGeometry(0,0,option.rect.width(),option.rect.height());
}


/*--------------------------------------------------------------------------------------------------------------------------------------*/
workDelegateForLTW::workDelegateForLTW(QWidget *parent) : QStyledItemDelegate(parent)
{
    normal = "./normal.png";
    press= "./press.png";
    hover = "./hover.png";
    isFinish = 0;
}

bool workDelegateForLTW::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(event->type()==QEvent::MouseButtonPress)
    {
        QRectF butRect;
        butRect.setX(option.rect.width() - buttonSize);
        butRect.setY(option.rect.y() + (option.rect.height() - buttonSize)/2);
        butRect.setWidth(buttonSize);
        butRect.setHeight(buttonSize);
        QMouseEvent *mevent = static_cast<QMouseEvent*>(event);
        if(butRect.contains(mevent->pos()))
        {
            qDebug()<<"按钮被按下";
            isFinish = 1;
        }
        else
            isFinish = 0;
    }
    else if(event->type()==QEvent::MouseButtonRelease)
    {
        qDebug()<<"鼠标松开了";
        QRectF butRect;
        butRect.setX(option.rect.width()-buttonSize);
        butRect.setY(option.rect.y() + (option.rect.height() - buttonSize)/2);
        butRect.setWidth(buttonSize);
        butRect.setHeight(buttonSize);
        QMouseEvent *mevent = static_cast<QMouseEvent*>(event);
        if(butRect.contains(mevent->pos()) && isFinish)
        {
            qDebug()<<"任务完成了";
            model->setData(index, 1, Qt::UserRole + 2);                     //完成任务
            emit finishLongtermWork(index.data(Qt::UserRole + 3).toInt());     //发送任务完成信号
        }
    }


    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
QWidget* workDelegateForLTW::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.data(Qt::UserRole + 2).toInt())        //已完成的任务无需编辑
        return NULL;
    qDebug()<<"编辑器被创建了！";
    QLineEdit* workEdit = new QLineEdit(index.data(Qt::UserRole + 1).toString(), parent);
    workEdit->setStyleSheet("background: rgb(200,200,200); border-width:0; border-style:outset");
    QFont font;
    font.setPointSize(10); //字号大小
    font.setFamily("Microsoft Yahei"); //字体样式
    font.setBold(false);
    workEdit->setFont(font);
    workEdit->deselect();
    return workEdit;
}

void workDelegateForLTW::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    static_cast<QLineEdit*>(editor)->setText(index.data(Qt::UserRole + 1).toString());

}

void workDelegateForLTW::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(!static_cast<QLineEdit*>(editor)->text().isEmpty())      //文本框不为空即进行更新
    {
        qDebug()<<"数据被更新拉！";
        model->setData(index, static_cast<QLineEdit*>(editor)->text(),Qt::UserRole + 1);
        workDisplay* view = qobject_cast<workDisplay*>(this->parent());
        view->isChanged = 1;
        view->nContent = static_cast<QLineEdit*>(editor)->text();
        view->changedItem = index;
        emit view->DupdateWork(index.data(Qt::UserRole + 3).toInt(),view->nContent);
    }

}

void workDelegateForLTW::updateEditorGeometry(QWidget *editor, const QStyleOption &option, const QModelIndex &index)
{
    Q_UNUSED(index);
    editor->setGeometry(0,0,option.rect.width(),option.rect.height());
}


void workDelegateForLTW::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const       //长期任务渲染函数
{
    if(!index.isValid())
        return;

    painter->save();
    int realWidth = option.rect.width() - buttonSize;
    QRectF textRect, butRect, pgBarRect, sDateRect, eDateRect;
    textRect.setX(option.rect.x());
    textRect.setY(option.rect.y());
    textRect.setWidth(realWidth / 3);
    textRect.setHeight(option.rect.height());

    sDateRect.setX(textRect.right());
    sDateRect.setY(option.rect.y());
    sDateRect.setWidth(realWidth * 2 / 9);
    sDateRect.setHeight(option.rect.height());

    pgBarRect.setX(sDateRect.right());
    pgBarRect.setY(option.rect.y());
    pgBarRect.setWidth(realWidth * 2 / 9);
    pgBarRect.setHeight(option.rect.height());

    eDateRect.setX(pgBarRect.right());
    eDateRect.setY(option.rect.y());
    eDateRect.setWidth(realWidth * 2 / 9);
    eDateRect.setHeight(option.rect.height());

    butRect.setX(eDateRect.right());
    butRect.setY(option.rect.y() + (option.rect.height() - buttonSize)/2);
    butRect.setWidth(buttonSize);
    butRect.setHeight(buttonSize);

    //绘制任务
    if(index.data(Qt::UserRole + 2).toInt())        //已完成的任务
    {
        painter->setPen(QPen(Qt::green));
        painter->setBrush(QBrush(QColor(0,0,0,15)));
        painter->drawRect(option.rect);
        painter->setFont(QFont("Microsoft Yahei", 10));
        painter->drawText(textRect, Qt::AlignVCenter,index.data(Qt::UserRole + 1).toString());
        painter->restore();
        return;
    }

    //绘制进度条
    QString startTime = index.data(Qt::UserRole + 4).toString() + QString(" 00:00:00");
    QString endTime = index.data(Qt::UserRole + 5).toString() + QString(" 00:00:00");

    QDateTime current= QDateTime::currentDateTime();//获取系统当前的时间
    QDateTime start = QDateTime::fromString(startTime, "yyyy-MM-dd hh:mm:ss");
    QDateTime end = QDateTime::fromString(endTime, "yyyy-MM-dd hh:mm:ss");

    uint stime = start.toTime_t();
    uint etime = end.toTime_t();
    uint ctime = current.toTime_t();
    double proportion=0;
    if(etime != stime){
        proportion = (ctime - stime) / (etime - stime);
    }
    else{
        if(ctime - stime>0){
            proportion = 1;
        }
    }
    if(proportion > 0)
    {
        int r,g,b;
        if(proportion < 0.33)               //绿色
            r=0,g=50,b=15;
        else if(proportion < 0.66)           //黄色
            r=0,g=50,b=55;
        else                                 //红色
            r=50,g=0,b=0;
        painter->setBrush(QBrush(QColor(r,g,b)));
        painter->drawRoundRect(pgBarRect);
    }


    if(option.state.testFlag(QStyle::State_MouseOver))  //鼠标悬浮
    {
        painter->setPen(QPen(QColor(255,0,0,100)));
        painter->setBrush(QBrush(QColor(0,0,0,60)));
        painter->drawRect(option.rect);
        painter->setPen(QPen(Qt::white));
    }
    //    else if(option.state.testFlag(QStyle::State_Selected))       //被选中时
    //    {

    //    }
    else
    {
        painter->setPen(QPen(Qt::darkBlue));
        painter->setBrush(QBrush(QColor(0,0,0,15)));
        painter->drawRect(option.rect);
    }

    //绘制按钮
    QPoint pos = qobject_cast<QWidget*>(this->parent())->mapFromGlobal(QCursor().pos());
    if(option.state.testFlag(QStyle::State_Active) && butRect.contains(pos))
    {
        QPixmap pic;
        pic.load(press);
        pic = pic.scaled(buttonSize,buttonSize);
        painter->drawPixmap(butRect.topLeft(), pic);
    }
    else
    {
        QPixmap pic;
        pic.load(hover);
        pic = pic.scaled(buttonSize,buttonSize);
        painter->drawPixmap(butRect.topLeft(), pic);
    }


    painter->setFont(QFont("Microsoft Yahei", 10));
    painter->drawText(textRect, Qt::AlignVCenter,index.data(Qt::UserRole + 1).toString());
    painter->drawText(sDateRect, Qt::AlignVCenter,index.data(Qt::UserRole + 4).toString());
    painter->drawText(eDateRect, Qt::AlignVCenter,index.data(Qt::UserRole + 5).toString());

    painter->restore();
}

QSize workDelegateForLTW::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(option.rect.width(),workDelegateHeight);
}


/*-------------------------------------------------------------------------------------------------------------------------*/


workDelegateForFW::workDelegateForFW(QWidget *parent) : QStyledItemDelegate(parent){}

void workDelegateForFW::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return;

    painter->save();
    QRectF textRect,/* butRect, */timeRect;
    textRect.setX(option.rect.x());
    textRect.setY(option.rect.y());
    textRect.setWidth(option.rect.width() / 2);
    textRect.setHeight(option.rect.height());

    timeRect.setX(textRect.right());
    timeRect.setY(option.rect.y());
    timeRect.setWidth(option.rect.width() / 2/* - buttonSize*/);
    timeRect.setHeight(option.rect.height());

//    butRect.setX(timeRect.right());
//    butRect.setY(option.rect.y() + (option.rect.height() - buttonSize)/2);
//    butRect.setWidth(buttonSize);
//    butRect.setHeight(buttonSize);

//    if(index.data(Qt::UserRole + 2).toInt())        //已完成的任务
//    {
//        painter->setPen(QPen(Qt::green));
//        painter->setBrush(QBrush(QColor(0,0,0,15)));
//        painter->drawRect(option.rect);
//        painter->setFont(QFont("Microsoft Yahei", 10));
//        painter->drawText(textRect, Qt::AlignVCenter,index.data(Qt::UserRole + 1).toString());
//        painter->restore();
//        return;
//    }

    if(option.state.testFlag(QStyle::State_MouseOver))
    {
        painter->setPen(QPen(QColor(255,0,0,100)));
        painter->setBrush(QBrush(QColor(0,0,0,60)));
        painter->drawRect(option.rect);
        painter->setPen(QPen(Qt::white));
    }
    else
    {
        painter->setPen(QPen(Qt::darkBlue));
        painter->setBrush(QBrush(QColor(0,0,0,15)));
        painter->drawRect(option.rect);
    }

//    //绘制按钮
//    QPoint pos = qobject_cast<QWidget*>(this->parent())->mapFromGlobal(QCursor().pos());
//    if(option.state.testFlag(QStyle::State_Active) && butRect.contains(pos))
//    {
//        QPixmap pic;
//        pic.load(press);
//        pic = pic.scaled(buttonSize,buttonSize);
//        painter->drawPixmap(butRect.topLeft(), pic);
//    }
//    else
//    {
//        QPixmap pic;
//        pic.load(hover);
//        pic = pic.scaled(buttonSize,buttonSize);
//        painter->drawPixmap(butRect.topLeft(), pic);
//    }

    painter->setFont(QFont("Microsoft Yahei", 10));
    painter->drawText(textRect, Qt::AlignVCenter, index.data(Qt::UserRole + 1).toString());
    painter->drawText(timeRect, Qt::AlignVCenter, QString("预定日期:") + index.data(Qt::UserRole + 4).toString());  //绘制日期

    painter->restore();
}

QSize workDelegateForFW::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(option.rect.width(),workDelegateHeight);
}


QWidget* workDelegateForFW::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.data(Qt::UserRole + 2).toInt())        //已完成的任务无需编辑
        return NULL;
    qDebug()<<"编辑器被创建了！";
    QLineEdit* workEdit = new QLineEdit(index.data(Qt::UserRole + 1).toString(), parent);
    workEdit->setStyleSheet("background: rgb(200,200,200); border-width:0; border-style:outset");
    QFont font;
    font.setPointSize(10); //字号大小
    font.setFamily("Microsoft Yahei"); //字体样式
    font.setBold(false);
    workEdit->setFont(font);
    workEdit->deselect();
    return workEdit;
}

void workDelegateForFW::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    static_cast<QLineEdit*>(editor)->setText(index.data(Qt::UserRole + 1).toString());

}

void workDelegateForFW::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(!static_cast<QLineEdit*>(editor)->text().isEmpty())      //文本框不为空即进行更新
    {
        qDebug()<<"数据被更新拉！";
        model->setData(index, static_cast<QLineEdit*>(editor)->text(),Qt::UserRole + 1);
        workDisplay* view = qobject_cast<workDisplay*>(this->parent());
        view->isChanged = 1;
        view->nContent = static_cast<QLineEdit*>(editor)->text();
        view->changedItem = index;
        emit view->DupdateWork(index.data(Qt::UserRole + 3).toInt(),view->nContent);
    }

}

void workDelegateForFW::updateEditorGeometry(QWidget *editor, const QStyleOption &option, const QModelIndex &index)
{
    Q_UNUSED(index);
    editor->setGeometry(0,0,option.rect.width()/2, option.rect.height());
}



/*------------------------------------------------------------------------------------------------------------------------------------*/




workDoneButton::workDoneButton(QWidget* parent, QString normal, QString hover, QString press, int ID) : QPushButton(parent)
{
    qDebug()<<"一个按钮被创建，ID = "<<ID;
    normal_img = normal;
    hover_img = hover;
    press_img = press;
    status = NORMAL;
    mouse_press = false;
    workID = ID;
}

void workDoneButton::enterEvent(QEvent *)
{
    status = HOVER;
    update();
}
void workDoneButton::mousePressEvent(QMouseEvent *event)
{
    //若点击鼠标左键
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}
void workDoneButton::mouseReleaseEvent(QMouseEvent *event)
{
    //若点击鼠标左键响应
    if(mouse_press&&this->rect().contains(event->pos()))
    {
        mouse_press = false;
        status = HOVER;
        update();
        emit clicked();
    }
}
void workDoneButton::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}
void workDoneButton::paintEvent(QPaintEvent *)      //根据不同状态显示按钮
{
    QPainter painter(this);
    QPixmap pixmap;
    bool suc = 1;
    switch(status)
    {
    case NORMAL:
    {
        suc = pixmap.load(normal_img);
        break;
    }
    case HOVER:
    {
        suc = pixmap.load(hover_img);
        break;
    }
    case PRESS:
    {
        suc = pixmap.load(press_img);
        break;
    }
    default:
        suc = pixmap.load(normal_img);
    }
//    if(!suc)
//    {
//        qDebug()<<"图片打开失败了妈的！！";
//        qDebug()<<normal_img<<" "<<press_img<<' '<<hover_img;
//    }
//    else
//        qDebug()<<"图片打开成功了好耶！！";
    pixmap = pixmap.scaled(this->width(),this->height());
    painter.drawPixmap(rect(), pixmap);
    //setMask(pixmap.mask());         //设置图片遮盖

}


