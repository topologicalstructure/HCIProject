#ifndef YESTERDAYWORKS_H
#define YESTERDAYWORKS_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSortFilterProxyModel>
#include "sqlconn.h"

namespace Ui {
class yesterdayworks;
}

class yesterdayworks : public QWidget
{
    Q_OBJECT

public:
    explicit yesterdayworks(QWidget *parent = nullptr, SqliteOperator* oper = nullptr);
    ~yesterdayworks();
    void sort(QStandardItemModel* model);
    //    bool finishCmp(const QStandardItem* left, const QStandardItem* right);
    QStandardItemModel* getYesterdayWorks();

private:
    Ui::yesterdayworks *ui;
    QStandardItemModel *yesterdayWorks;
    //    QSortFilterProxyModel *myProxyModel;
    SqliteOperator* oper;
    void setButton();

private slots:
    void updateWork(int id, QString nContent);
    void deleteWork(int id);
    void finishWork(int id);
    void ModelUpdate();         //更新任务Model

};

#endif // YESTERDAYWORKS_H
