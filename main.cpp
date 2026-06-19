#include "login.h"
#include <QGraphicsView>
#include <QApplication>

int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "1.9");
    qputenv("QT_SCREEN_SCALE_FACTORS", "1.9x2.5");
    QApplication a(argc, argv);
    LoginWindow w;
    w.showMaximized();
    return a.exec();
}
