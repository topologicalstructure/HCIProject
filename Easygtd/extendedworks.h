#ifndef EXTENDEDWORKS_H
#define EXTENDEDWORKS_H

#include <QWidget>

namespace Ui {
class extendedworks;
}

class extendedworks : public QWidget
{
    Q_OBJECT

public:
    explicit extendedworks(QWidget *parent = nullptr);
    ~extendedworks();

private:
    Ui::extendedworks *ui;
};

#endif // EXTENDEDWORKS_H
