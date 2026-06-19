#include "dashboard.h"
#include "ui_dashboard.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "university.h"
#include "addstudentdialog.h"
#include <QMessageBox>
#include "students.h"

dashboard::dashboard(QWidget *parent, Students *students)
    : QWidget(parent) , ui(new Ui::dashboard)
    , studentsPage(students)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
    effect->setOpacity(0.8);
    ui->frame->setGraphicsEffect(effect);
    connect(ui->pushButton_student_6 , &QPushButton::clicked , this , &dashboard::onAddClicked);
    Updatedashboard();
}

void dashboard::Updatedashboard()
{
    int totalStudents = University::get()->getTotalStudents();
    int occupiedRooms = University::get()->getOccupiedRooms();
    int totalRooms    = University::get()->getTotalRooms() == 0 ? 1 : University::get()->getTotalRooms() ;
    int maxStudents   = 1150;


    ui->StudentBar->setMaximum(maxStudents);
    ui->StudentBar->setTextVisible(false);
    ui->pushButton_student_num->setText(QString("%1 / %2").arg(totalStudents).arg(maxStudents));
    ui->StudentBar->setValue(0);
    animateBar(ui->StudentBar, totalStudents);


    ui->RoomBar->setMaximum(totalRooms);
    ui->RoomBar->setTextVisible(false);
    ui->room_num->setText(QString("%1 / %2").arg(occupiedRooms).arg(totalRooms));
    ui->RoomBar->setValue(0);
    animateBar(ui->RoomBar, occupiedRooms);


    ui->DormitoriyBar->setMaximum(5);
    ui->DormitoriyBar->setTextVisible(false);
    ui->DormitoriyBar->setValue(0);
    animateBar(ui->DormitoriyBar, 5);

    int mealsToday = University::get()->getTotalMealsToday();
    int maxMeals = totalStudents == 0 ? 1 : totalStudents;
    ui->MealBar->setMaximum(maxMeals);
    ui->MealBar->setTextVisible(false);
    ui->MealBar->setValue(0);
    animateBar(ui->MealBar, mealsToday);
}
void dashboard::animateBar(QProgressBar *bar , int newvalue)
{
    QPropertyAnimation *anim = new QPropertyAnimation(bar , "value");
    anim->setDuration(600);
    anim->setStartValue(bar->value());
    anim->setEndValue(newvalue);
    anim->setEasingCurve(QEasingCurve::OutBounce);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}
dashboard::~dashboard()
{
    delete ui;
}
void dashboard::onAddClicked()
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
        University::get()->addStudent(s);
        if (s.getRoom() != 0 && s.getDorm() != 0)
            University::get()->assignStudentToRoom(s.getID(), s.getRoom(), s.getDorm());
        Updatedashboard();
        if (studentsPage) studentsPage->refreshTable();
    }
}
void dashboard::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    Updatedashboard();
}