#include "mainwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Icons/icon.ico"));

    // Determine the absolute path to the plugins folder
    QString pluginPath = QCoreApplication::applicationDirPath() + "/plugins";
    qputenv("GST_PLUGIN_PATH", pluginPath.toUtf8());
    qDebug() << "GST_PLUGIN_PATH set to:" << qgetenv("GST_PLUGIN_PATH");

    MainWindow w;
    w.show();
    return a.exec();
}
