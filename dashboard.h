#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "qprogressbar.h"
#include <QWidget>
#include "students.h"

namespace Ui {
class dashboard;
}

class dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr, Students *students = nullptr);
    ~dashboard();

private:
    Ui::dashboard *ui;
    Students *studentsPage ;

    void Updatedashboard();
    void animateBar(QProgressBar *bar , int newvalue);
    void onAddClicked() ;
protected:
    void showEvent(QShowEvent *event) override;


};

#endif // DASHBOARD_H
