
#include "mainwindow.h"
#include <QApplication>
#include "sqlconn.h"

void Test()
{
    int n;
    int*list;
    SqliteOperator oper;
    list=oper.GetTodayList(&n);
    qDebug()<<n;
    for (int i = 0; i < n; i++) {
        qDebug()<<list[i];
    }
    delete[] list;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
