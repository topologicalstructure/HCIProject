#ifndef EXPECTEDWORKS_H
#define EXPECTEDWORKS_H

#include <QWidget>

namespace Ui {
class ExpectedWorks;
}

class ExpectedWorks : public QWidget
{
    Q_OBJECT

public:
    explicit ExpectedWorks(QWidget *parent = nullptr);
    ~ExpectedWorks();

private:
    Ui::ExpectedWorks *ui;
};

#endif // EXPECTEDWORKS_H
