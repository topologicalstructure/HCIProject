#include "yesterdayworks.h"
#include "ui_yesterdayworks.h"

yesterdayworks::yesterdayworks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yesterdayworks)
{
    ui->setupUi(this);
}

yesterdayworks::~yesterdayworks()
{
    delete ui;
}
