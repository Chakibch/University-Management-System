#ifndef DORMITORY_H
#define DORMITORY_H

#include <QWidget>

namespace Ui {
class Dormitory;
}

class Dormitory : public QWidget
{
    Q_OBJECT

public:
    explicit Dormitory(QWidget *parent = nullptr);
    ~Dormitory();
    void RefreshDorms();

protected:
    void showEvent(QShowEvent *event) override;

private:
    static const int TOTAL_ROOMS = 230;
    static const int Dorms = 5;
    Ui::Dormitory *ui;
};

#endif // DORMITORY_H