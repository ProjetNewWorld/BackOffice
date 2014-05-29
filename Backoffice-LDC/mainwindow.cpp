#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QListWidgetItem>
#include <QColor>
#include <QLinearGradient>
#include <QGradient>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    if(connectBase()) // si on est connecté on charge l'ui
    {
        ui->setupUi(this);
    }
    else // sinon on affiche un message d erreur
    {
        QMessageBox::critical(this,"Erreur critique", "Impossible d'ouvrir la base de données.");
    }
    chargerRayons();
    chargerProduits();
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::connectBase , permet la conncetion a la base
 * @return true si la connection a marché , false sinon
 */
bool MainWindow::connectBase()
{
    baseLDC=QSqlDatabase::addDatabase("QMYSQL");

    baseLDC.setHostName("127.0.0.1");
    baseLDC.setPassword("passLDC");
    baseLDC.setUserName("userLDC");
    baseLDC.setDatabaseName("listedescourses");
    return baseLDC.open();

}
/**
 * @brief MainWindow::on_tabWidget_currentChanged Quand on change d'onglet
 * @param index le numéro de l'onglet
 */
void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch (index) {
    case 0: // les rayons
        chargerRayons();
        break;
    case 1: // les produits
           chargerProduits();
    default:
        break;
    }
}

// ******************** DEBUT RAYON ********************************
/**
 * @brief MainWindow::chargerRayons , charge l'onglet rayons , efface les lineEdit et charge la liste de rayons et gere les bouttons
 */
void MainWindow::chargerRayons()
{
    ui->lineEditSearchRayon->clear();
    ui->lineEditNomRayon->clear();
    chargerListeRayons();
    ui->pushButtonModifierRayon->setEnabled(false);
    ui->pushButtonAjouterRayon->setEnabled(false);
    ui->pushButtonSupprimerRayon->setEnabled(false);
}
/**
 * @brief MainWindow::chargerListeRayons
 * Charge la liste Widget des rayons
 */
void MainWindow::chargerListeRayons()
{
    ui->listWidgetRayon->clear();
    vectorRayon.clear();
    int i=0;
    QSqlQuery req("select rayonLib, rayonId from rayon where rayonLib like '"+ui->lineEditSearchRayon->text()+"%' order by rayonLib");
    while(req.next())
    {

        QListWidgetItem *item=new QListWidgetItem(req.value(0).toString());
        QLinearGradient linGrad;
        linGrad.setStart(0,ui->listWidgetRayon->y());// gradiant
        linGrad.setFinalStop(ui->listWidgetRayon->width(),ui->listWidgetRayon->y());// stop gradiant
        if(i%2==0)
        {
            linGrad.setColorAt( 0, QColor(191,230,244));//couleur
            linGrad.setColorAt( 1, Qt::white );


          }
        else
        {

              linGrad.setColorAt( 0, QColor(157,214,237));
               linGrad.setColorAt( 1, Qt::white );
        }
          i++;

            QBrush brush(linGrad);//definit une QBrush

        item->setBackground(brush);//ajout de la couleur dd l item


        ui->listWidgetRayon->addItem(item);
        vectorRayon.push_back(req.value(1).toString());
    }
    if(i==0)ui->listWidgetRayon->addItem("Pas de rayon(s)");
}

/**
 * @brief MainWindow::on_lineEditSearchRayon_cursorPositionChanged Quand on tape quelquechose dans la lineEdit de recherche
 * @param arg1
 * @param arg2
 */
void MainWindow::on_lineEditSearchRayon_cursorPositionChanged(int arg1, int arg2)
{
    chargerListeRayons();
    ui->lineEditNomRayon->clear();
}
/**
 * @brief MainWindow::on_listWidgetRayon_itemClicked Quand on clique sur un item (sur un rayon dans la liste)
 * @param item
 */
void MainWindow::on_listWidgetRayon_itemClicked(QListWidgetItem *item)
{
    ui->lineEditNomRayon->setText(ui->listWidgetRayon->currentItem()->text());
    ui->pushButtonModifierRayon->setEnabled(true);
    ui->pushButtonSupprimerRayon->setEnabled(true);
}
/**
 * @brief MainWindow::on_pushButtonAjouterRayon_clicked
 */
void MainWindow::on_pushButtonAjouterRayon_clicked()
{
    QSqlQuery req("select * from rayon where rayonLib='"+ui->lineEditNomRayon->text()+"'");
    req.first();
    if(req.size()>0)
    {
        QMessageBox::information(this,"Erreur", "Ce rayon existe déjà !");
    }
    else
    {
        QSqlQuery req("insert into rayon values (null,'"+ui->lineEditNomRayon->text()+"')");
        req.exec();
        chargerListeRayons();
    }

}
/**
 * @brief MainWindow::on_pushButtonModifierRayon_clicked
 */
void MainWindow::on_pushButtonModifierRayon_clicked()
{
    QSqlQuery req("update rayon set rayonLib='"+ui->lineEditNomRayon->text()+"' where rayonId = "+vectorRayon.value(ui->listWidgetRayon->currentRow())+"");
    chargerRayons();
}
/**
 * @brief MainWindow::on_pushButtonSupprimerRayon_clicked
 */
void MainWindow::on_pushButtonSupprimerRayon_clicked()
{
    QString rayonId=vectorRayon.value(ui->listWidgetRayon->currentRow());


     int reponse=QMessageBox::question(this, "Etes vous sûr ?", "Voulez supprimer  le rayon "+ui->listWidgetRayon->currentItem()->text()+" , et tout les produit qu'il contient et qui sont potentiellement sur une ou plusieurs liste ?", QMessageBox::Yes | QMessageBox::Cancel);


     switch (reponse) {
       case QMessageBox::Yes:

         QVector <QString> vectorIdProduit=getVectorIdProduit(rayonId);
         for(int i=0;i<vectorIdProduit.size();i++)
         {
                QSqlQuery req("delete from contenuliste where produitId = "+vectorIdProduit.value(i));
             qDebug()<<"delete from contenuliste where produitId = "+vectorIdProduit.value(i);
             req.exec();
         }



         QSqlQuery req2("delete from produit where rayonId = "+rayonId);
           qDebug()<<"delete from produit where rayonId = "+rayonId;
         req2.exec();

         QSqlQuery req3("delete from rayon where rayonId = "+rayonId);
         req3.exec();
           qDebug()<<"delete from rayon where rayonId = "+rayonId;
         chargerListeRayons();
           break;

     }
}
/**
 * @brief MainWindow::on_lineEditNomRayon_cursorPositionChanged
 * @param arg1
 * @param arg2
 */
void MainWindow::on_lineEditNomRayon_cursorPositionChanged(int arg1, int arg2)
{
    if(ui->lineEditNomRayon->text().length()>0)
    {
        ui->pushButtonAjouterRayon->setEnabled(true);
    }
    else
    {
        ui->pushButtonAjouterRayon->setEnabled(false);

    }
}
/**
 * @brief MainWindow::getVectorIdProduit
 * @param rayonId
 * @return Revoit un vecteur qui contient l id de tout les produits qui sont dans le rayon dont l'id est passé en parametre
 */
QVector<QString> MainWindow::getVectorIdProduit(QString rayonId)
{
    QVector <QString> vectorIdProduit;
    QSqlQuery req("select produitId from produit where rayonId="+rayonId);
    qDebug()<<"select produitId from prduit where rayonId="+rayonId;
    while(req.next())
    {
        vectorIdProduit.push_back(req.value(0).toString());
        qDebug()<<req.value(0).toString();

    }
    return vectorIdProduit;
}
//******************************* FIN LES RAYON *************************

// **********************  DEBUT LES PRODUITS ******************************
/**
 * @brief MainWindow::chargerProduits
 */
void MainWindow::chargerProduits()
{
    ui->lineEditNomProduit->clear();
    ui->lineEditSearchProduit->clear();
    ui->comboBoxRayonProduit->clear();
    chargerListeProduits();
    chargerRayonInProduits();
    ui->pushButtonAjouterProduit->setEnabled(false);
    ui->pushButtonModifierProduit->setEnabled(false);
    ui->pushButtonSupprimerProduit->setEnabled(false);
}
/**
 * @brief MainWindow::chargerListeProduits
 */
void MainWindow::chargerListeProduits()
{
    ui->listWidgetProduits->clear();
    vectorRayonAndProduit.clear();
    vectorPositionInListOfRayon.clear();
    int i=0;
    QString actualRayon="";
    QSqlQuery req("select produitLib, produitId  , rayonLib from produit natural join rayon where produitLib like '"+ui->lineEditSearchProduit->text()+"%' order by rayonId , produitLib");
    while(req.next())
    {
        QLinearGradient linGrad;
        QListWidgetItem *item;
        if(req.value(2).toString()!=actualRayon) // si on change de rayon
        {
            item=new QListWidgetItem(req.value(2).toString());
            linGrad.setStart(0,ui->listWidgetRayon->y());// gradiant
            linGrad.setFinalStop(ui->listWidgetRayon->width(),ui->listWidgetRayon->y());// stop gradiant
            linGrad.setColorAt( 0, QColor(100,100,100));
            linGrad.setColorAt( 1, Qt::white );
            vectorPositionInListOfRayon.push_back(i);
            vectorRayonAndProduit.push_back(req.value(2).toString());
            actualRayon=req.value(2).toString();

            i++;
           QBrush brush(linGrad);//definit une QBrush

           item->setBackground(brush);//ajout de la couleur dd l item
            ui->listWidgetProduits->addItem(item);
        }

           item=new QListWidgetItem(req.value(0).toString());
           linGrad.setStart(0,ui->listWidgetRayon->y());// gradiant
            linGrad.setFinalStop(ui->listWidgetRayon->width(),ui->listWidgetRayon->y());// stop gradiant
            if(i%2==0)
             {
                 linGrad.setColorAt( 0, QColor(191,230,244));//couleur
                 linGrad.setColorAt( 1, Qt::white );


             }
            else
            {

              linGrad.setColorAt( 0, QColor(157,214,237));
               linGrad.setColorAt( 1, Qt::white );
            }
            vectorRayonAndProduit.push_back(req.value(1).toString());



         i++;
        QBrush brush(linGrad);//definit une QBrush

        item->setBackground(brush);//ajout de la couleur dd l item


        ui->listWidgetProduits->addItem(item);
    }
    if(i==0)ui->listWidgetProduits->addItem("Pas de produits(s)");
}
/**
 * @brief MainWindow::chargerRayonInProduits
 */
void MainWindow::chargerRayonInProduits()
{
    ui->comboBoxRayonProduit->clear();
    QSqlQuery req("select rayonLib from rayon");
    while(req.next())
    {
        ui->comboBoxRayonProduit->addItem(req.value(0).toString());
    }
}
/**
 * @brief MainWindow::getRayonByProduit
 * @param idProd
 * @return
 */
QString MainWindow::getRayonByProduit(QString idProd)
{
    QSqlQuery requette("select rayonLib from produit natural join rayon where produit.produitId="+idProd);
    requette.next();
    if(requette.size()>0)
    {
        return requette.value(0).toString();
    }
    else
    {
        return "Le produit avec comme id "+idProd+" n'éxiste pas ou n est pas dans un rayon !";
    }
}
/**
 * @brief MainWindow::getIdRayonByNameRayon
 * @param rayonLib
 * @return
 */
QString MainWindow::getIdRayonByNameRayon(QString rayonLib)
{
    QSqlQuery requette("select rayonId from rayon where rayonLib='"+rayonLib+"'");
    qDebug()<<"select rayonId from rayon where rayonLib="+rayonLib;
    requette.next();
    qDebug()<<requette.value(0).toString();
    return requette.value(0).toString();
}

/**
 * @brief MainWindow::on_lineEditSearchProduit_cursorPositionChanged
 * @param arg1
 * @param arg2
 */


void MainWindow::on_lineEditSearchProduit_cursorPositionChanged(int arg1, int arg2)
{
    chargerListeProduits();
    ui->lineEditNomProduit->clear();
}
/**
 * @brief MainWindow::on_listWidgetProduits_itemClicked
 * @param item
 */
void MainWindow::on_listWidgetProduits_itemClicked(QListWidgetItem *item)
{
    bool IsProduit=true;
    for(int i=0;i<vectorPositionInListOfRayon.size();i++)
    {
        if(vectorPositionInListOfRayon.value(i)==ui->listWidgetProduits->currentRow()) // Si l'item sur lequel on clique a une position qui correspond a un rayon (si c est un rayon)
        {
            IsProduit=false;
        }
    }
    if(IsProduit)
    {
        ui->lineEditNomProduit->setText(ui->listWidgetProduits->currentItem()->text()); // on met le nom du produit dans la line edit
        QString idProduit=vectorRayonAndProduit.value(ui->listWidgetProduits->currentRow()); // on recupere l id du produit

        chargerRayonInProduits(); // on charge la liste des rayons (combo box)

        QString rayonLib=getRayonByProduit(idProduit); // on recupere le nom du rayon du produit
        for(int i = 0 ; i< ui->comboBoxRayonProduit->count() ; i++) // pour tout le rayons
        {
            if(ui->comboBoxRayonProduit->itemText(i)==rayonLib) // si le rayon a l indice i est celui du produit
            {
                ui->comboBoxRayonProduit->setCurrentIndex(i); // on le met en current
            }
        }

        ui->pushButtonModifierProduit->setEnabled(true);
        ui->pushButtonSupprimerProduit->setEnabled(true);


    }
}
/**
 * @brief MainWindow::on_lineEditNomProduit_cursorPositionChanged
 * @param arg1
 * @param arg2
 */
void MainWindow::on_lineEditNomProduit_cursorPositionChanged(int arg1, int arg2)
{
    if(ui->lineEditNomProduit->text().length()>0)
    {
        ui->pushButtonAjouterProduit->setEnabled(true);
    }
    else
    {
        ui->pushButtonAjouterProduit->setEnabled(false);
    }
}

/**
 * @brief MainWindow::on_pushButtonAjouterProduit_clicked
 */

void MainWindow::on_pushButtonAjouterProduit_clicked()
{
    QSqlQuery req("select * from produit where produitLib='"+ui->lineEditNomProduit->text()+"'");
    req.first();
    if(req.size()>0)
    {
        QMessageBox::information(this,"Erreur", "Ce produit existe déjà !");
    }
    else
    {
       QString rayonId=getIdRayonByNameRayon(ui->comboBoxRayonProduit->currentText());
        QSqlQuery req("insert into produit values (null,'"+ui->lineEditNomProduit->text()+"',"+rayonId+")");
        qDebug()<<"insert into produit values (null,'"+ui->lineEditNomProduit->text()+"',"+rayonId+")";
        //req.exec();
        chargerProduits();
    }
}
/**
 * @brief MainWindow::on_pushButtonModifierProduit_clicked
 */
void MainWindow::on_pushButtonModifierProduit_clicked()
{
    QSqlQuery req("update produit set produitLib='"+ui->lineEditNomProduit->text()+"' , rayonId="+getIdRayonByNameRayon(ui->comboBoxRayonProduit->currentText())+" where produitId = "+vectorRayonAndProduit.value(ui->listWidgetProduits->currentRow())+"");
    chargerProduits();
}
/**
 * @brief MainWindow::on_pushButtonSupprimerProduit_clicked
 */
void MainWindow::on_pushButtonSupprimerProduit_clicked()
{
    QString produitId=vectorRayonAndProduit.value(ui->listWidgetProduits->currentRow());

     int reponse=QMessageBox::question(this, "Etes vous sûr ?", "Voulez supprimer  le produit "+ui->listWidgetProduits->currentItem()->text()+" , qui est potentiellement sur une ou plusieurs liste ?", QMessageBox::Yes | QMessageBox::Cancel);


     switch (reponse) {
       case QMessageBox::Yes:


          QSqlQuery req("delete from contenuliste where produitId = "+produitId);

         QSqlQuery req2("delete from produit where produitId = "+produitId);

         chargerProduits();
           break;

     }
}
