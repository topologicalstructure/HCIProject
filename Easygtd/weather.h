#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class Weather;
}

class Weather : public QWidget
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    ~Weather();
    QString code="99";
    QString wea="未连接";
    QString tempe=" ";
    void Update();

private:
    Ui::Weather *ui;
};

#endif // WEATHER_H
