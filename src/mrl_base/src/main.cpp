#include "forms/mainwindow.h"
#include <QApplication>
#include <util/rosmanager.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    rosmanager::Instance()->init(argc,argv);

    // rosmanager r ; r.init(argc,argv);

    MainWindow w;
    w.show();

    return a.exec();
}
