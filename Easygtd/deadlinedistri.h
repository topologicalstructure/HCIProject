#ifndef DEADLINEDISTRI_H
#define DEADLINEDISTRI_H

#include <QWidget>

namespace Ui {
class deadlinedistri;
}

class deadlinedistri : public QWidget
{
    Q_OBJECT

public:
    explicit deadlinedistri(QWidget *parent = nullptr);
    ~deadlinedistri();

private:
    Ui::deadlinedistri *ui;
};

#endif // DEADLINEDISTRI_H
