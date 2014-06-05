#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QListWidgetItem>
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
private slots:
    void on_action_Quitter_triggered();
    void on_listWidgetProduits_currentRowChanged();
    void on_listWidgetRayons_currentRowChanged();
    void on_pushButtonProduitsAnnuler_clicked();
    void on_pushButtonRayonsAnnuler_clicked();
    void on_pushButtonRayonsModifier_clicked();
    void on_pushButtonRayonsAjouter_clicked();
    void on_pushButtonRayonsSupprimer_clicked();
    void on_lineEditRayons_textChanged();
    void on_pushButtonProduitsAjouter_clicked();
    void on_pushButtonProduitsModifier_clicked();
    void on_pushButtonProduitsSupprimer_clicked();
    void on_comboBoxProduitsRayons_currentIndexChanged();
    void on_lineEditRechercheProduits_textChanged();
    void on_lineEditProduits_textChanged();    

private:
    Ui::MainWindow *ui;
    QSqlDatabase listedescourses;
    QVector <QString> vectorRayons;
    QVector <QString> vectorRayonsProduits;
    QVector <int> vectorPositionInListOfRayon;
    QString getRayonByProduit(QString idProd);

};

#endif // MAINWINDOW_H
