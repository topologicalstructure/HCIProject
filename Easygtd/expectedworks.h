#ifndef EXPECTEDWORKS_H
#define EXPECTEDWORKS_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "sqlconn.h"

namespace Ui {
class ExpectedWorks;
}

class ExpectedWorks : public QWidget
{
    Q_OBJECT

public:
    explicit ExpectedWorks(QWidget *parent = nullptr, SqliteOperator* Oper = nullptr);
    ~ExpectedWorks();

private:
    Ui::ExpectedWorks *ui;
    QStandardItemModel *expectedWorks;
    SqliteOperator* oper;

private slots:
    void updateWork(int id, QString nContent);
    void deleteWork(int id);
//    void finishWork(int id);
    void ModelUpdate();         //更新任务Model
};

#endif // EXPECTEDWORKS_H
