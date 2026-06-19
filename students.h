#ifndef STUDENTS_H
#define STUDENTS_H
#include <QWidget>

namespace Ui {
class Students;
}

class Students : public QWidget
{
    Q_OBJECT

public:
    explicit Students(QWidget *parent = nullptr);
    ~Students();
    void refreshTable();

private:
    Ui::Students *ui;
protected:
    void showEvent(QShowEvent *event) override;

private slots :
    void onAddClicked();
    void onDeleteClicked();

};

#endif // STUDENTS_H
