#include "weather.h"
#include "ui_weather.h"

Weather::Weather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
}

Weather::~Weather()
{
    delete ui;
}

void Weather::Update()
{
    ui->weather->setText(wea);
    ui->tem->setText(tempe+"°C");
    QImage ima;
    ima.load("./black/"+code+"@2x.png");
    //ima.scaled(ui->picture->height(),ui->picture->width(),Qt::KeepAspectRatio);
    ui->picture->setPixmap(QPixmap::fromImage(ima));
}
