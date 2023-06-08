#ifndef EXTENDEDWORKS_H
#define EXTENDEDWORKS_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "sqlconn.h"

namespace Ui {
class extendedworks;
}

class extendedworks : public QWidget
{
    Q_OBJECT

public:
    explicit extendedworks(QWidget *parent = nullptr, SqliteOperator* oper = nullptr);
    void sort(QStandardItemModel* model);
    ~extendedworks();

private:
    Ui::extendedworks *ui;
    QStandardItemModel *extendedWorks;
    SqliteOperator* oper;

private slots:
    void updateWork(int id, QString nContent);
    void deleteWork(int id);
    void finishWork(int id);
    void ModelUpdate();         //更新任务Model
};

#endif // EXTENDEDWORKS_H
