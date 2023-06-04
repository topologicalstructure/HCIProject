#include "weather.h"
#include "ui_weather.h"

Weather::Weather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
    ui->weather->setText(wea);
    ui->tem->setText("网络");
    QImage ima;
    ima.load("./black/"+code+"@2x.png");
    ui->picture->setPixmap(QPixmap::fromImage(ima));
}

Weather::~Weather()
{
    delete ui;
}

void Weather::Update()
{
    if(wea==""){
        ui->weather->setText("错误");
        ui->tem->setText("网络");
        QImage ima;
        ima.load("./black/99@2x.png");
        ui->picture->setPixmap(QPixmap::fromImage(ima));
    }
    else{
        ui->weather->setText(wea);
        ui->tem->setText(tempe+"°C");
        QImage ima;
        ima.load("./black/"+code+"@2x.png");
        ui->picture->setPixmap(QPixmap::fromImage(ima));
    }
}
