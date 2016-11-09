#include "mainwindow.h"
#include "license.h"
#include <QApplication>
#include <QLibrary>
#include <QMessageBox>
#include <QDebug>
typedef int (*Fun)();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w1;
    w1.show();
    return a.exec();
}
