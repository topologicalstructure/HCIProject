#include "todayworks.h"
#include "ui_todayworks.h"

Todayworks::Todayworks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Todayworks)
{
    ui->setupUi(this);
}

Todayworks::~Todayworks()
{
    delete ui;
}
