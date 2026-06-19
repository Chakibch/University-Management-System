#include "rooms.h"
#include "ui_rooms.h"
#include "university.h"
#include <QButtonGroup>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QColor>

Rooms::Rooms(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Rooms)
{
    ui->setupUi(this);

    QHeaderView *header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Fixed);
    header->setSectionResizeMode(1, QHeaderView::Stretch);
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(6, QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);

    QButtonGroup *buttons = new QButtonGroup(this);
    buttons->addButton(ui->btn_all);
    buttons->addButton(ui->btn_available);
    buttons->addButton(ui->btn_occupied);
    ui->btn_all->setCheckable(true);
    ui->btn_available->setCheckable(true);
    ui->btn_occupied->setCheckable(true);
    buttons->setExclusive(true);
    ui->btn_all->setChecked(true);

    connect(ui->btn_all, &QPushButton::clicked, this, &Rooms::RefreshTable);
    connect(ui->btn_available, &QPushButton::clicked, this, &Rooms::RefreshTable);
    connect(ui->btn_occupied, &QPushButton::clicked, this, &Rooms::RefreshTable);

    University::get()->initRooms();
    RefreshTable();
}

void Rooms::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    RefreshTable();
}

void Rooms::RefreshTable()
{
    ui->tableWidget->setRowCount(0);

    for (const RoomInfo &r : University::get()->getAllRooms())
    {
        if (ui->btn_available->isChecked() && r.isOccupied()) continue;
        if (ui->btn_occupied->isChecked() && !r.isOccupied()) continue;

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(r.GetNumber())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString("Dorm %1").arg(r.GetDorm())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(r.isOccupied() ? QString("ID-%1").arg(r.GetStudent().getID()) : "—"));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(r.isOccupied() ? r.GetStudent().getName() : "—"));

        QString status = r.isOccupied() ? "Occupied" : "Available";
        QTableWidgetItem *statusItem = new QTableWidgetItem(status);
        statusItem->setForeground(r.isOccupied() ? QColor("#f87171") : QColor("#4ade80"));
        ui->tableWidget->setItem(row, 4, statusItem);
    }
    int total = University::get()->getTotalRooms();
    int occupied = University::get()->getOccupiedRooms();
    int available = total - occupied;

    ui->TotalRooms_btn->setText(QString("%1").arg(total));
    ui->AvailableRooms_btn->setText(QString("%1").arg(available));
    ui->OccupiedRooms_btn->setText(QString("%1").arg(occupied));
}

Rooms::~Rooms()
{
    delete ui;
}