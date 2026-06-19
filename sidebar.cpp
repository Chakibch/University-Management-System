#include "sidebar.h"
#include "qwidget.h"
#include "ui_sidebar.h"

SideBar::SideBar(QWidget *parent) : QWidget(parent), ui(new Ui::SideBar)
{
    ui->setupUi(this);
    connect(ui->pushButton_dashboard,  &QPushButton::clicked, this, &SideBar::dashboardClicked);
    connect(ui->pushButton_students,   &QPushButton::clicked, this, &SideBar::studentsClicked);
    connect(ui->pushButton_rooms,      &QPushButton::clicked, this, &SideBar::roomsClicked);
    connect(ui->pushButton_dormitory,  &QPushButton::clicked, this, &SideBar::dormitoryClicked);
    connect(ui->pushButton_restaurant, &QPushButton::clicked, this, &SideBar::restaurantClicked);
}

SideBar::~SideBar()
{
    delete ui;
}
