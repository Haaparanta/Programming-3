#include "mainwindow.hh"
#include "objectcontroller.hh"

#include <QApplication>
#include <cstdlib>
#include <time.h>
#include <QDebug>



int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);

    ObjectController* engine = new ObjectController();

    MainWindow w(engine);

    w.show();

    return a.exec();
}
