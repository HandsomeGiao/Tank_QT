#include "controller.h"

#include <QApplication>
#include<QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w;
    w.show();
    return a.exec();
}
