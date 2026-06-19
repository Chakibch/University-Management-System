#include "restaurant.h"
#include "ui_restaurant.h"
#include <QVBoxLayout>
#include "university.h"
Restaurant::Restaurant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Restaurant)
{
    ui->setupUi(this);
    connect(ui->comboDorm, &QComboBox::currentIndexChanged, this, &Restaurant::refreshMenu);
    connect(ui->comboDay, &QComboBox::currentIndexChanged, this, &Restaurant::refreshMenu);

    refreshMenu();
    ui->comboDorm->raise();
    ui->comboDay->raise();
}
void Restaurant::refreshMenu()
{
    int dorm = ui->comboDorm->currentIndex();
    int day  = ui->comboDay->currentIndex();

    RestaurantInfo& r = University::get()->getRestaurant(dorm);

    ui->labelBreakfast->setText(r.getBreakfast(day));
    ui->labelLunch->setText(r.getLunch(day));
    ui->labelDinner->setText(r.getDinner(day));
}
Restaurant::~Restaurant()
{
    delete ui;
}
