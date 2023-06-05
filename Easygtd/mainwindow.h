
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
    QPushButton* becomesmaller;
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:
    void becomesmaller_clicked();
    void Change(int id);
    void GetCreat();
};


#endif // MAINWINDOW_H
