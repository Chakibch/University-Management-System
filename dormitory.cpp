#include "dormitory.h"
#include "ui_dormitory.h"
#include "QVBoxLayout"
#include "QString"
#include "university.h"

Dormitory::Dormitory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dormitory)
{
    ui->setupUi(this);

    ui->RoomBar_A->setMaximum(TOTAL_ROOMS) ;
    ui->RoomBar_A_2->setMaximum(TOTAL_ROOMS);
    ui->RoomBar_A_3->setMaximum(TOTAL_ROOMS);
    ui->RoomBar_A_4->setMaximum(TOTAL_ROOMS);
    ui->RoomBar_A_5->setMaximum(TOTAL_ROOMS);

    ui->StudentBar_A->setMaximum(TOTAL_ROOMS);
    ui->StudentBar_A_2->setMaximum(TOTAL_ROOMS);
    ui->StudentBar_A_3->setMaximum(TOTAL_ROOMS);
    ui->StudentBar_A_4->setMaximum(TOTAL_ROOMS);
    ui->StudentBar_A_5->setMaximum(TOTAL_ROOMS);
    RefreshDorms();
}

void Dormitory::RefreshDorms()
{
    int a = University::get()->getOccupiedRoomsInDorm(1);
    int b = University::get()->getOccupiedRoomsInDorm(2);
    int c = University::get()->getOccupiedRoomsInDorm(3);
    int d = University::get()->getOccupiedRoomsInDorm(4);
    int e = University::get()->getOccupiedRoomsInDorm(5);

    ui->StudentBar_A->setValue(a);
    ui->StudentBar_A_2->setValue(b);
    ui->StudentBar_A_3->setValue(c);
    ui->StudentBar_A_4->setValue(d);
    ui->StudentBar_A_5->setValue(e);

    ui->RoomBar_A->setValue(a);
    ui->RoomBar_A_2->setValue(b);
    ui->RoomBar_A_3->setValue(c);
    ui->RoomBar_A_4->setValue(d);
    ui->RoomBar_A_5->setValue(e);

    int total = a + b + c + d + e;
    ui->pushButton_student_num_27->setText(QString("Occupied Rooms : %1").arg(total));
    ui->pushButton_student_num_28->setText(QString("Available Rooms : %1").arg(5 * TOTAL_ROOMS - total));
}

void Dormitory::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    RefreshDorms();
}

Dormitory::~Dormitory()
{
    delete ui;
}
