
#include "mainwindow.h"

#include <QApplication>
#include "sqlconn.h"

int main(int argc, char *argv[])
{
    SqliteOperator oper;
    oper.UpdateTable();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
