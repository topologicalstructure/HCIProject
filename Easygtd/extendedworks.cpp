#include "extendedworks.h"
#include "ui_extendedworks.h"

extendedworks::extendedworks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::extendedworks)
{
    ui->setupUi(this);
}

extendedworks::~extendedworks()
{
    delete ui;
}
