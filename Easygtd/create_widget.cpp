#include "create_widget.h"
#include "ui_create_widget.h"

create_widget::create_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_widget)
{
    ui->setupUi(this);
    ui->dateEdit->setMinimumDateTime(QDateTime::currentDateTime());
    ui->dateEdit_2->setVisible(0);
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(DateChanged()));
    connect(ui->dateEdit_2,SIGNAL(dateChanged(QDate)),this,SLOT(DateChanged2()));
}

create_widget::~create_widget()
{
    delete ui;
}

void create_widget::on_comboBox_currentIndexChanged(int index)
{
    if(!index){
        ui->dateEdit_2->setVisible(0);
    }
    else{
        ui->dateEdit_2->setVisible(1);
        ui->dateEdit_2->setMinimumDateTime(ui->dateEdit->dateTime());
        ui->dateEdit_2->setDateTime(QDateTime::currentDateTime().addDays(7));
        ui->dateEdit->setMaximumDateTime(ui->dateEdit_2->dateTime());
    }
}

void create_widget::DateChanged()
{
    ui->dateEdit_2->setMinimumDateTime(ui->dateEdit->dateTime());
}

void create_widget::DateChanged2()
{
    ui->dateEdit->setMaximumDateTime(ui->dateEdit_2->dateTime());
}

void create_widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()!=Qt::Key_Return||ui->lineEdit->text().isEmpty()){
        return;
    }
    SqliteOperator oper;
    if(ui->comboBox->currentIndex()==0){
        if(ui->dateEdit->dateTime()==QDateTime::currentDateTime()){
            oper.AddToday(ui->lineEdit->text());
        }
        else{
            oper.AddExpected(ui->dateEdit->date().toString("yyyy-MM-dd"),ui->lineEdit->text());
        }
    }
    else{
        oper.AddLongterm(ui->dateEdit->date().toString("yyyy-MM-dd"),ui->dateEdit_2->date().toString("yyyy-MM-dd"),ui->lineEdit->text());
    }
    ui->lineEdit->clear();
}
