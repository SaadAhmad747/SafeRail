#include "mainwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Icons/icon.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
