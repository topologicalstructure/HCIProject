
#include "mainwindow.h"

#include <QApplication>
#include "sqlconn.h"

int main(int argc, char *argv[])
{
    SqliteOperator oper;
    //oper.AddToday("完成数据库第三次作业");
    //oper.FinishToday(1,0);
    oper.UpdateTable();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
