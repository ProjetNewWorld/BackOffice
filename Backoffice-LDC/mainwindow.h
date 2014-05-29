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

    void chargerRayons();
    void chargerListeRayons();
    void chargerProduits();
    void chargerListeProduits();
    void chargerRayonInProduits();
    QString getRayonByProduit(QString idProd);
    QString getIdRayonByNameRayon(QString rayonLib);
    QVector <QString> getVectorIdProduit(QString rayonId);


private slots:
    void on_lineEditSearchRayon_cursorPositionChanged(int arg1, int arg2);

    void on_listWidgetRayon_itemClicked(QListWidgetItem *item);

    void on_pushButtonAjouterRayon_clicked();

    void on_pushButtonModifierRayon_clicked();

    void on_pushButtonSupprimerRayon_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_lineEditSearchProduit_cursorPositionChanged(int arg1, int arg2);

    void on_listWidgetProduits_itemClicked(QListWidgetItem *item);

    void on_lineEditNomProduit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEditNomRayon_cursorPositionChanged(int arg1, int arg2);

    void on_pushButtonAjouterProduit_clicked();

    void on_pushButtonModifierProduit_clicked();

    void on_pushButtonSupprimerProduit_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase baseLDC;
    QVector <QString> vectorRayon;
    QVector <int> vectorPositionInListOfRayon;
    QVector <QString> vectorRayonAndProduit;
};

#endif // MAINWINDOW_H
