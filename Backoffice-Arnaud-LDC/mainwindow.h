#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
  * @brief Inclusion des dépendances
  * QMainWindow
  * QSqlDatabase
  * QSqlQuery
  * QVector
  * QListWidgetItem
  * QMessageBox
  * QDebug
  */
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool connectBase();
    void chargerListWidgetProduits();
    void chargerListWidgetRayons();
    void chargerComboBoxRayons();
    void chargePageRayons();
    void chargePageProduits();
    QVector <QString> getVecteurIdProduit(QString idRayon);
    QString getIdRayonByName(QString rayonLib);

private slots:
    // menu
    void on_action_Quitter_triggered();
    void on_tabWidget_tabBarClicked();

    //rayons
    void on_listWidgetRayons_clicked();
    void on_lineEditRayons_textChanged();
    void on_comboBoxProduitsRayons_currentIndexChanged(int);

    void on_pushButtonRayonsAnnuler_clicked();
    void on_pushButtonRayonsModifier_clicked();
    void on_pushButtonRayonsAjouter_clicked();
    void on_pushButtonRayonsSupprimer_clicked();

    //produits
    void on_listWidgetProduits_clicked();
    void on_lineEditProduits_textChanged();
    void on_lineEditRechercheProduits_textChanged();

    void on_pushButtonProduitsAnnuler_clicked();
    void on_pushButtonProduitsModifier_clicked();
    void on_pushButtonProduitsAjouter_clicked();
    void on_pushButtonProduitsSupprimer_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase listedescourses;
    QVector <QString> vectorRayons;
    QVector <QString> vectorRayonsProduits;
    QVector <int> vectorPositionInListOfRayon;
    QString getRayonByProduit(QString idProd);

};

#endif // MAINWINDOW_H
