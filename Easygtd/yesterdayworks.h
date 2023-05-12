#ifndef YESTERDAYWORKS_H
#define YESTERDAYWORKS_H

#include <QWidget>

namespace Ui {
class yesterdayworks;
}

class yesterdayworks : public QWidget
{
    Q_OBJECT

public:
    explicit yesterdayworks(QWidget *parent = nullptr);
    ~yesterdayworks();

private:
    Ui::yesterdayworks *ui;
};

#endif // YESTERDAYWORKS_H
