#include "mainwindow.h"
#include <QApplication>
#include "constants.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(Settings::CompanyName);
    QCoreApplication::setApplicationName(Settings::ApplicationName);

    QApplication a(argc, argv);

    MainWindow w;
    //w.showMaximized();
    w.show();

    return a.exec();
}
