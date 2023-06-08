#ifndef LONGTERMWORKS_H
#define LONGTERMWORKS_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "sqlconn.h"

namespace Ui {
class longtermworks;
}

class longtermworks : public QWidget
{
    Q_OBJECT

public:
    explicit longtermworks(QWidget *parent = nullptr, SqliteOperator* oper = nullptr);
    void sort(QStandardItemModel* model);
    ~longtermworks();

private:
    Ui::longtermworks *ui;
    QStandardItemModel *longtermWorks;
    SqliteOperator* oper;

private slots:
    void updateWork(int id, QString nContent);
    void deleteWork(int id);
    void finishWork(int id);
    void ModelUpdate();         //更新任务Model
};

#endif // LONGTERMWORKS_H
