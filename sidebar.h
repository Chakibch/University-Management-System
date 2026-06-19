#ifndef SIDEBAR_H
#define SIDEBAR_H
#include "qwidget.h"
#include "ui_sidebar.h"
class SideBar : public QWidget
{
    Q_OBJECT
public:
    explicit SideBar(QWidget *parent = nullptr);

    ~SideBar();
signals:
    void dashboardClicked();
    void studentsClicked();
    void roomsClicked();
    void dormitoryClicked();
    void restaurantClicked();
private :
    Ui::SideBar *ui;

};

#endif // SIDEBAR_H
