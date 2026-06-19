#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "sidebar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // MAINWINDOW_H
