#include "students.h"
#include "addstudentdialog.h"
#include "ui_students.h"
#include "university.h"
#include <QTableWidgetItem>
#include <QColor>
#include <QFont>
#include <QChar>
#include <QHeaderView>
#include <QMessageBox>

Students::Students(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Students)
{
    ui->setupUi(this);
    QHeaderView *header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(6, QHeaderView::Stretch);

    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setColumnWidth(0, 30);
    connect(ui->AddStudent, &QPushButton::clicked, this, &Students::onAddClicked);
    connect(ui->RemoveStudent, &QPushButton::clicked, this, &Students::onDeleteClicked);

    refreshTable();
}

void Students::refreshTable()
{
    ui->tableWidget->setRowCount(0);

    int rowNum = 1;
    for (const StudentInfo &s : University::get()->getAllStudents())
    {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(rowNum++)));

        QTableWidgetItem *name = new QTableWidgetItem(s.getName());
        name->setForeground(QColor(0xc0cce0));
        QFont f = name->font();
        f.setWeight(QFont::Medium);
        name->setFont(f);
        ui->tableWidget->setItem(row, 1, name);
        QTableWidgetItem *id = new QTableWidgetItem(QString("ID-%1").arg(s.getID(), 3, 10, QChar('0')));
        id->setForeground(QColor(0x4a5060));
        ui->tableWidget->setItem(row, 2, id);

        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString("Year %1").arg(s.getYear())));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(s.getDorm() == 0 ? "—" : QString("Dorm %1").arg(s.getDorm())));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(s.getRoom() == 0 ? "—" : QString::number(s.getRoom())));

        QString status = s.getRoom() == 0 ? "Pending" : "Assigned";
        QTableWidgetItem *statusItem = new QTableWidgetItem(status);
        statusItem->setForeground(status == "Assigned" ? QColor("#4ade80") : QColor("#fbbf24"));
        ui->tableWidget->setItem(row, 6, statusItem);
    }
}

void Students::onAddClicked()
{
    AddStudentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        StudentInfo s = dialog.getStudentData();
        if (s.getName().isEmpty() || s.getID() == 0)
        {
            QMessageBox::warning(this, "Invalid Input", "Please fill Name and ID correctly.");
            return;
        }
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
        University::get()->addStudent(s);
        if (s.getRoom() != 0 && s.getDorm() != 0)
            if (!University::get()->assignStudentToRoom(s.getID(), s.getRoom(), s.getDorm()))
            {
                QMessageBox::warning(this, "Room Occupied", "This room is already occupied.");
                University::get()->removeStudent(s.getID());
                return;
            }
        refreshTable();

    }
}

void Students::onDeleteClicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow == -1)
    {
        QMessageBox::warning(this, "No Selection", "Please select a student to delete.");
        return;
    }
    int id = ui->tableWidget->item(selectedRow, 2)->text().remove("ID-").toInt();
    for (StudentInfo &s : University::get()->getAllStudents())
    {
        if (s.getID() == id)
        {
            if (s.getRoom() != 0 && s.getDorm() != 0)
                University::get()->removeStudentFromRoom(s.getRoom(), s.getDorm());
            break;
        }
    }
    University::get()->removeStudent(id);
    refreshTable();
}

Students::~Students()
{
    delete ui;
}
void Students::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    refreshTable();
}