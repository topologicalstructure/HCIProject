#ifndef TODAYWORKS_H
#define TODAYWORKS_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSortFilterProxyModel>
#include "sqlconn.h"

namespace Ui {
class Todayworks;
}

class Todayworks : public QWidget
{
    Q_OBJECT

public:
    explicit Todayworks(QWidget *parent = nullptr, SqliteOperator* oper = nullptr);
    void sort(QStandardItemModel* model);
//    bool finishCmp(const QStandardItem* left, const QStandardItem* right);
    ~Todayworks();
    QStandardItemModel* getTodayWorks();


private:
    Ui::Todayworks *ui;
    QStandardItemModel *todayWorks;
//    QSortFilterProxyModel *myProxyModel;
    SqliteOperator* oper;
    void setButton();
private slots:
    void updateWork(int id, QString nContent);
    void deleteWork(int id);
    void finishWork(int id);
    void ModelUpdate();         //更新任务Model

signals:
    void SortSuccess();
};

#endif // TODAYWORKS_H
