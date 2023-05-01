#include "expectedworks.h"
#include "ui_expectedworks.h"

ExpectedWorks::ExpectedWorks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpectedWorks)
{
    ui->setupUi(this);
}

ExpectedWorks::~ExpectedWorks()
{
    delete ui;
}
