#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"

AddStudentDialog::AddStudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setAttribute(Qt::WA_TranslucentBackground);
    connect(ui->AddStudentButton, &QPushButton::clicked, this, &QDialog::accept);

    connect(ui->CancelButton , &QPushButton::clicked , this , &QDialog::reject);
}
AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}

StudentInfo AddStudentDialog::getStudentData() const
{
    // Reads fields from the dialog UI and returns a StudentInfo object
    QString name = ui->FullName->text();
    int room = ui->Room->text().toInt();
    int Id = ui->ID->text().toInt();
    int year = ui->AcademicYear->currentIndex() + 1 ;
    int dorm = ui->Dormitory->currentIndex() + 1 ;
    return StudentInfo(Id , room , dorm , year , name );
}
