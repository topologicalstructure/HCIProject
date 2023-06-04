#ifndef WORKDISPLAY_H
#define WORKDISPLAY_H

#include <QStyledItemDelegate>
#include <QListView>
#include <QWidget>
#include <QPushButton>
#include <QAction>
#include <QModelIndex>

class workDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    workDelegate(QWidget* parent);
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    bool isFinish;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //创建委托控件
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    //设置控件数据
    void setEditorData(QWidget *editor,const QModelIndex &index) const override;
    //设置模型数据
    void setModelData(QWidget *editor,QAbstractItemModel *model,const QModelIndex &index) const override;
    //设置控件位置
    void updateEditorGeometry(QWidget *editor,const QStyleOption &option,const QModelIndex &index);

    QString normal, hover, press;   //按钮对应图片路径

//signals:
//    void updateWorks(int id, QString nContent) const;
signals:
    void finishTodayWork(int ID);
};

class workDisplay : public QListView
{
    Q_OBJECT
public:
    workDisplay(QWidget* parent);
    void contextMenuEvent(QContextMenuEvent *event);    //右键菜单
    QMenu* menu;
    QAction* workDelete;
    bool isFinishable = 1;
    void setButton();                                   //设置完成按钮
//    void mouseMoveEvent(QMouseEvent*);                  //检测鼠标移动
    QModelIndex changedItem;
    QString nContent;
    bool isChanged = 0;

signals:
    void DdeleteWork(int ID);                            //右键删除任务
    void DfinishWork(int ID);
    void DupdateWork(int ID, QString nContent);
private slots:
    void deleteWorkinModel();
};

//class myMySortFilterProxyModel : public QSortFilterProxyModel
//{
//    Q_OBJECT
//protected:
//    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const;
//};






class workDoneButton : public QPushButton
{
    Q_OBJECT
public:
    explicit workDoneButton(QWidget *parent = 0, QString normal = "", QString hover = "", QString press = "", int ID = 0);
    void enterEvent(QEvent *);//进入事件
    void leaveEvent(QEvent *);//离开事件
    void mousePressEvent(QMouseEvent *event);  //鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event); //鼠标释放事件
    void paintEvent(QPaintEvent *);//按钮绘图事件

private:
    enum ButtonStatus{NORMAL, HOVER, PRESS};	//枚举按钮的几种状态
    ButtonStatus status;
    QString normal_img; //正常路径
    QString hover_img;  //鼠标悬浮路径
    QString press_img;  //按下后的路径
    bool mouse_press;
    int workID;         //对应的任务ID

};

#endif // WORKDISPLAY_H
