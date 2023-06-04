
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smallwindows.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    oper=new SqliteOperator;
    oper->UpdateTable();
    today=new Todayworks(this,oper);
    expects=new ExpectedWorks;
    longterm=new longtermworks;
    yesterday=new yesterdayworks;
    extended=new extendedworks;
    deadline=new deadlinedistri;
    ui->stackedWidget->addWidget(today);
    ui->stackedWidget->addWidget(expects);
    ui->stackedWidget->addWidget(longterm);
    ui->stackedWidget->addWidget(yesterday);
    ui->stackedWidget->addWidget(extended);
    ui->stackedWidget->addWidget(deadline);
    ui->buttonGroup->addButton(ui->todayButton,0);
    ui->buttonGroup->addButton(ui->expectsButton,1);
    ui->buttonGroup->addButton(ui->longtermButton,2);
    ui->buttonGroup->addButton(ui->yestButton,3);
    ui->buttonGroup->addButton(ui->extendButton,4);
    ui->buttonGroup->addButton(ui->ddlButton,5);

    ui->todayButton->setIcon(QIcon("icons8-note-96.png"));
    ui->todayButton->setIconSize(QSize(30,30));
    ui->todayButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->expectsButton->setIcon(QIcon("icons8-alarm-90.png"));
    ui->expectsButton->setIconSize(QSize(30,30));
    ui->expectsButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->longtermButton->setIcon(QIcon("icons8-deadline-96.png"));
    ui->longtermButton->setIconSize(QSize(30,30));
    ui->longtermButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->yestButton->setIcon(QIcon("icons8-history-96.png"));
    ui->yestButton->setIconSize(QSize(30,30));
    ui->yestButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->extendButton->setIcon(QIcon("icons8-plus-1-day-100.png"));
    ui->extendButton->setIconSize(QSize(30,30));
    ui->extendButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->ddlButton->setIcon(QIcon("icons8-schedule-96.png"));
    ui->ddlButton->setIconSize(QSize(30,30));
    ui->ddlButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->buttonGroup->button(0)->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);
    //connect(ui->buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(ui->buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(Change(int)));
    setWindowTitle("EasyGTD");
    becomesmaller=new QPushButton("smaller",this);
    becomesmaller->setGeometry(this->geometry().width()-50,0,50,50);
    becomesmaller->show();
    becomesmaller->raise();
    becomesmaller->setText("");
    connect(becomesmaller,SIGNAL(clicked(bool)),this,SLOT(becomesmaller_clicked()));
    QIcon icon;
    icon.addFile(tr("icons8-small-screen-100.png"));
    becomesmaller->setIcon(icon);
    becomesmaller->setIconSize(QSize(50,50));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete today;

}

void MainWindow::becomesmaller_clicked()
{
    smallwindows* smwin=new smallwindows(nullptr, oper, today->getTodayWorks());
    this->hide();
    smwin->show();
}

void MainWindow::Change(int id)
{
    if(id==5){
        delete deadline;
        deadline=new deadlinedistri;
        ui->stackedWidget->insertWidget(5, deadline);
    }
    ui->stackedWidget->setCurrentIndex(id);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    becomesmaller->setGeometry(this->geometry().width()-50,0,50,50);
}
