#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H
#include "studentinfo.h"
#include <QDialog>

namespace Ui {
class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentDialog(QWidget *parent = nullptr);
    ~AddStudentDialog();
    StudentInfo getStudentData() const;

private:
    Ui::AddStudentDialog *ui;
};

#endif // ADDSTUDENTDIALOG_H
