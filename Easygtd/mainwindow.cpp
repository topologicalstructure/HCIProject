
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smallwindows.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    today=new Todayworks;
    expects=new ExpectedWorks;
    ui->stackedWidget->addWidget(today);
    ui->stackedWidget->addWidget(expects);
    ui->buttonGroup->addButton(ui->todayButton,0);
    ui->buttonGroup->addButton(ui->expectsButton,1);
    ui->buttonGroup->button(0)->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    setWindowTitle("EasyGTD");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete today;

}

void MainWindow::on_becomesmaller_clicked()
{
    smallwindows* smwin=new smallwindows();
    this->hide();
    smwin->show();
}


