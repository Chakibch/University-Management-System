#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "University.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);


    University::get()->initRooms();
    University::get()->loadData();


    connect(ui->sidebar, &SideBar::dashboardClicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->sidebar, &SideBar::studentsClicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->sidebar, &SideBar::roomsClicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->sidebar, &SideBar::dormitoryClicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->sidebar, &SideBar::restaurantClicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });

}
void MainWindow::closeEvent(QCloseEvent *event)
{
    University::get()->saveData();
    QWidget::closeEvent(event);
}


MainWindow::~MainWindow()
{
    delete ui;
}
