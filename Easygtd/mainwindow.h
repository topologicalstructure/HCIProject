
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "todayworks.h"
#include "expectedworks.h"
#include "longtermworks.h"
#include "extendedworks.h"
#include "yesterdayworks.h"
#include "deadlinedistri.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Todayworks* today;
    ExpectedWorks* expects;
    longtermworks* longterm;
    extendedworks* extended;
    yesterdayworks* yesterday;
    deadlinedistri* deadline;
    SqliteOperator* oper;
    QPushButton* smaller;


private slots:
    void on_becomesmaller_clicked();
    void Change(int id);
};


#endif // MAINWINDOW_H
