#include "deadlinedistri.h"
#include "ui_deadlinedistri.h"

deadlinedistri::deadlinedistri(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deadlinedistri)
{
    ui->setupUi(this);
}

deadlinedistri::~deadlinedistri()
{
    delete ui;
}
