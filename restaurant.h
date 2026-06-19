#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QWidget>

namespace Ui {
class Restaurant;
}

class Restaurant : public QWidget
{
    Q_OBJECT

public:
    explicit Restaurant(QWidget *parent = nullptr);
    ~Restaurant();
private slots:
    void refreshMenu();
private:
    Ui::Restaurant *ui;
};

#endif // RESTAURANT_H
