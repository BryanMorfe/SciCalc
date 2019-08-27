#include "scwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SCWindow w;
    w.show();

    return a.exec();
}
