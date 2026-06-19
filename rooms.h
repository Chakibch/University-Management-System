#ifndef ROOMS_H
#define ROOMS_H

#include <QWidget>

namespace Ui {
class Rooms;
}

class Rooms : public QWidget
{
    Q_OBJECT

public:
    explicit Rooms(QWidget *parent = nullptr);
    void RefreshTable() ;
    ~Rooms();

private:
    Ui::Rooms *ui;

protected:
    void showEvent(QShowEvent *event) override;
};

#endif // ROOMS_H
