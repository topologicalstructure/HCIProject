
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


private slots:
    void on_becomesmaller_clicked();
};


#endif // MAINWINDOW_H
