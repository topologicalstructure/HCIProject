
#include "mainwindow.h"

#include <QApplication>
#include "sqlconn.h"

int main(int argc, char *argv[])
{
    SqliteOperator oper;
    //oper.AddToday("2023-5-11","完成数据库第三次作业");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
