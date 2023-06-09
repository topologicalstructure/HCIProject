#include "create_widget.h"
#include "ui_create_widget.h"

create_widget::create_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_widget)
{
    ui->setupUi(this);
    //初始隐藏dateEdit_2
    ui->dateEdit->setMinimumDateTime(QDateTime::currentDateTime());
    ui->dateEdit_2->setVisible(0);
    //绑定信号与槽
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(DateChanged()));
    connect(ui->dateEdit_2,SIGNAL(dateChanged(QDate)),this,SLOT(DateChanged2()));
}

create_widget::~create_widget()
{
    delete ui;
}

void create_widget::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="长期"){
        ui->pushButton->setText("单日");
        ui->dateEdit_2->setVisible(0);
        ui->dateEdit->setDate(QDate::currentDate());
        ui->dateEdit->setMaximumDate(QDate(9999,12,31));
    }
    else{
        ui->pushButton->setText("长期");
        ui->dateEdit_2->setVisible(1);
        ui->dateEdit_2->setMinimumDateTime(ui->dateEdit->dateTime());
        ui->dateEdit_2->setDateTime(ui->dateEdit->dateTime().addDays(7));
        ui->dateEdit->setMaximumDateTime(ui->dateEdit_2->dateTime());
    }
}

void create_widget::DateChanged()
{
    //更新dateEdit_2最小日期，以保证编辑内容合法
    if(ui->pushButton->text()=="长期"){
        ui->dateEdit_2->setMinimumDateTime(ui->dateEdit->dateTime());
    }
}

void create_widget::DateChanged2()
{
    //只有当正在编辑长期任务时才需要更新更新dateEdit最大日期
    if(ui->pushButton->text()=="长期"){
        ui->dateEdit->setMaximumDateTime(ui->dateEdit_2->dateTime());
    }
}

void create_widget::keyPressEvent(QKeyEvent *event)
{
    //只有按回车键且lineEdit中有内容时才进行添加
    if(event->key()!=Qt::Key_Return||ui->lineEdit->text().isEmpty()){
        return;
    }
    SqliteOperator oper;
    if(ui->pushButton->text()=="单日"){
        if(ui->dateEdit->date()==ui->dateEdit->minimumDate()){
            oper.AddToday(ui->lineEdit->text());//添加今日任务
        }
        else{
            oper.AddExpected(ui->dateEdit->date().toString("yyyy-MM-dd"),ui->lineEdit->text());//添加预定任务
        }
    }
    else{
        oper.AddLongterm(ui->dateEdit->date().toString("yyyy-MM-dd"),ui->dateEdit_2->date().toString("yyyy-MM-dd"),ui->lineEdit->text());//添加长期任务
    }
    emit CreateSuccess();
    //清空输入框，等待下一次输入
    ui->lineEdit->clearFocus();
    ui->lineEdit->clear();
}
