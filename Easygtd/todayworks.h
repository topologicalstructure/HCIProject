#ifndef TODAYWORKS_H
#define TODAYWORKS_H

#include <QWidget>

namespace Ui {
class Todayworks;
}

class Todayworks : public QWidget
{
    Q_OBJECT

public:
    explicit Todayworks(QWidget *parent = nullptr);
    ~Todayworks();

private:
    Ui::Todayworks *ui;
};

#endif // TODAYWORKS_H
