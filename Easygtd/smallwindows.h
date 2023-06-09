#ifndef SMALLWINDOWS_H
#define SMALLWINDOWS_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QScreen>
#include <QPropertyAnimation>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>
#include <QDebug>
#include <QtCore>
#include <QTimer>
#include "sqlconn.h"
#include <QStandardItemModel>

namespace Ui {
class smallwindows;
}

class smallwindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit smallwindows(QWidget *parent = nullptr, SqliteOperator* Oper = nullptr, QStandardItemModel* model = nullptr);
    ~smallwindows();
    void sort(QStandardItemModel* model);
    //    bool finishCmp(const QStandardItem* left, const QStandardItem* right);
    QStandardItemModel* getTodayWorks();

protected:
    virtual void mousePressEvent(QMouseEvent *event);    //鼠标点击事件
    virtual void mouseMoveEvent(QMouseEvent *event);     //鼠标移动事件
    virtual void mouseReleaseEvent(QMouseEvent *event);  //鼠标释放事件
    virtual void enterEvent(QEvent *event);              //鼠标移入事件
    virtual void leaveEvent(QEvent *event);              //鼠标移出事件
    bool event(QEvent * event);
    QNetworkAccessManager manager;
    QNetworkRequest request;
    QUrl url = QUrl("https://api.seniverse.com/v3/weather/now.json?key=S9YW3zZRzKHPxy-67&location=ip&language=zh-Hans&unit=c");
    void GetWeather(QNetworkReply *reply);


private:
    Ui::smallwindows *ui;
    bool mouse_is_press=0;         //表示当前鼠标是否被按下
    QPoint mouse_posit;            //鼠标的相对坐标
    int win_hide=0;                //表示当前窗口的隐藏位置，等于0时未隐藏，等于时隐藏在左侧，等于2时隐藏在上方，等于3时隐藏在右侧
    int screen_width;              //屏幕宽度
    void HideWindow();             //隐藏窗口
    void ShowWindow();             //显示窗口
    SqliteOperator* oper;
    QStandardItemModel* todayWorks;
    void setButton();

private slots:
    void on_CloseButton_clicked();
    void on_becomebig_clicked();
    void updateWork(int id, QString nContent);
    void deleteWork(int id);
    void finishWork(int id);
    void ModelUpdate();         //更新任务Model
    void GetCreat();

public slots:
    void slotCountMessage();       //定时触发的槽函数
};


#endif // SMALLWINDOWS_H
