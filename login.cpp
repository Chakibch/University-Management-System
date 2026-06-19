#include "login.h"
#include "ui_login.h"
#include <QMovie>
#include <QGraphicsBlurEffect>
#include <QButtonGroup>
#include <QMessageBox>
#include "mainwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &LoginWindow::handleLogin);

    QMovie *movie = new QMovie(":/Study1.gif"); //for gif
    movie->setScaledSize(QSize(48*4, double(29.3*4)));
    ui->gif_label->setMovie(movie);
    movie->start();
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;//blur for welcome text
    blur->setBlurRadius(5);
    ui->label_7->setGraphicsEffect(blur);

    QButtonGroup *buttons = new QButtonGroup(this); //student and administrator choices
    buttons->addButton(ui->pushButton_student);
    buttons->addButton(ui->pushButton_administrator);

    ui->pushButton_administrator->setCheckable(true);
    ui->pushButton_student->setCheckable(true);
    buttons->setExclusive(true);
    ui->pushButton_administrator->setChecked(true);
}

void LoginWindow::handleLogin()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    bool IsStudent = ui->pushButton_student->isChecked();
    bool IsAdmin = ui->pushButton_administrator->isChecked();

    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, " Login ", "Please fill all fields");
        return;
    }

    if(IsStudent && password != "ENSIAStudents2026")
    {
        QMessageBox::critical(this, " Login ", "Wrong Password , please try again");
        return;
    }
    if(IsAdmin && password != "Mahelma3")
    {
        QMessageBox::critical(this, " Login ", "Wrong Password , please try again");
        return;
    }

    ::MainWindow *main_window = new ::MainWindow;
    main_window->showMaximized();
    this->close();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
