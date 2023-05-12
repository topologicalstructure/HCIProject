#ifndef LONGTERMWORKS_H
#define LONGTERMWORKS_H

#include <QWidget>

namespace Ui {
class longtermworks;
}

class longtermworks : public QWidget
{
    Q_OBJECT

public:
    explicit longtermworks(QWidget *parent = nullptr);
    ~longtermworks();

private:
    Ui::longtermworks *ui;
};

#endif // LONGTERMWORKS_H
