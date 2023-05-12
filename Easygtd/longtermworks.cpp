#include "longtermworks.h"
#include "ui_longtermworks.h"

longtermworks::longtermworks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::longtermworks)
{
    ui->setupUi(this);
}

longtermworks::~longtermworks()
{
    delete ui;
}
