#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    if(connectBase()) // si la connexion c'est bien passé
    {
        ui->setupUi(this);
    }
    else // sinon on affiche un message d'erreur
    {
        QMessageBox::critical(this,"Erreur critique", "Impossible d'ouvrir la base de données.");
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::connectBase , permet la connexion a la base de données
 * @return true si la connexion à la base à marché , retourne false sinon
 */
bool MainWindow::connectBase()
{
    QString hote="127.0.0.1";
    QString name="userLDC";
    QString pass="passLDC";
    QString bdd="listedescourses";

    listedescourses=QSqlDatabase::addDatabase("QMYSQL");
    listedescourses.setHostName(hote);
    listedescourses.setPassword(pass);
    listedescourses.setUserName(name);
    listedescourses.setDatabaseName(bdd);
    return listedescourses.open();
}
