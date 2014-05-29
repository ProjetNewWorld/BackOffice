#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("userLDC");
    db.setPassword("passLDC");
    db.setDatabaseName("listedescourses");
    db.open();
    return a.exec();
}
