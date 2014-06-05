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
        chargerListWidgetRayons();
        chargerListWidgetProduits();
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

// *********************************************************
// ****************** Base de données **********************
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

// *********************************************************
// *********************** Commun **************************

void MainWindow::on_action_Quitter_triggered()
{
    this->close();
}

void MainWindow::chargerComboBoxRayons()
{
    ui->comboBoxProduitsRayons->clear();
    ui->comboBoxProduitsRayons->addItem("Selectionnez un rayon");
    QSqlQuery req("select rayonLib from rayon");
    while(req.next())
    {
        ui->comboBoxProduitsRayons->addItem(req.value(0).toString());
    }
}

// *********************************************************
// *********************** Rayons **************************

void MainWindow::chargerListWidgetRayons()
{
    ui->listWidgetRayons->clear();
    ui->lineEditRayons->clear();
    vectorRayons.clear();
    int i=0;
    QSqlQuery req("select rayonId, rayonLib from rayon order by rayonLib");
    while(req.next())
    {
        QListWidgetItem *item=new QListWidgetItem(req.value(1).toString());
        i++;
        ui->listWidgetRayons->addItem(item);
        vectorRayons.push_back(req.value(0).toString());
    }
    if(i==0)
    {
        ui->listWidgetRayons->addItem("Pas de rayon");
    }
}

void MainWindow::on_listWidgetRayons_currentRowChanged()
{
    ui->lineEditRayons->setText(ui->listWidgetRayons->currentItem()->text());
    ui->pushButtonRayonsModifier->setEnabled(true);
    ui->pushButtonRayonsSupprimer->setEnabled(true);
    ui->pushButtonRayonsAnnuler->setEnabled(true);
}

void MainWindow::on_pushButtonRayonsAnnuler_clicked()
{
    ui->lineEditRayons->clear();
    ui->pushButtonRayonsAjouter->setEnabled(false);
    ui->pushButtonRayonsAnnuler->setEnabled(false);
    ui->pushButtonRayonsSupprimer->setEnabled(false);
    ui->pushButtonRayonsModifier->setEnabled(false);
}

// *********************************************************
// ********************** Produits *************************

void MainWindow::chargerListWidgetProduits(){
    ui->listWidgetProduits->clear();
    chargerComboBoxRayons();
    vectorRayonsProduits.clear();
    vectorPositionInListOfRayon.clear();
    int i=0;
    QString rayon;
    QSqlQuery req("select produitId, produitLib, rayonLib from produit natural join rayon where produitLib like '%"+ui->lineEditRechercheProduits->text()+"%' order by rayonId , produitLib");
    while(req.next())
    {
        QListWidgetItem *item;
        if(req.value(2).toString()!=rayon) // si on change de rayon
        {
            item=new QListWidgetItem(req.value(2).toString());
            vectorPositionInListOfRayon.push_back(i);
            vectorRayonsProduits.push_back(req.value(2).toString());
            ui->listWidgetProduits->addItem(item);
            rayon=req.value(2).toString();
            i++;
        }
        item=new QListWidgetItem(req.value(1).toString());
        vectorRayonsProduits.push_back(req.value(0).toString());
        ui->listWidgetProduits->addItem(item);
        i++;
    }
    if(i==0)ui->listWidgetProduits->addItem("Aucun produit");
}

QString MainWindow::getRayonByProduit(QString idProd)
{
    QSqlQuery requete("select rayonLib from produit natural join rayon where produit.produitId="+idProd);
    requete.next();
    if(requete.size()>0)
    {
        return requete.value(0).toString();
    }
    else
    {
        return "Le produit avec comme id "+idProd+" n'éxiste pas ou n est pas dans un rayon !";
    }
}

void MainWindow::on_listWidgetProduits_currentRowChanged()
{
    bool produit=true;
    for(int i=0;i<vectorPositionInListOfRayon.size();i++)
    {
        if(vectorPositionInListOfRayon.value(i)==ui->listWidgetProduits->currentRow()) // Si l'item sur lequel on clique à une position qui correspond à un rayon
        {
            produit=false;
        }
    }
    if(produit)
    {
        ui->lineEditProduits->setText(ui->listWidgetProduits->currentItem()->text()); // on met le nom du produit dans la line edit
        QString idProduit=vectorRayonsProduits.value(ui->listWidgetProduits->currentRow()); // on recupere l'id du produit
        chargerComboBoxRayons(); // on charge la liste des rayons (combo box)
        QString rayonLib=getRayonByProduit(idProduit); // on recupere le nom du rayon du produit
        for(int i = 0 ; i< ui->comboBoxProduitsRayons->count() ; i++) // pour tout le rayon
        {
            if(ui->comboBoxProduitsRayons->itemText(i)==rayonLib) // si le rayon à l'indice i est celui du produit
            {
                ui->comboBoxProduitsRayons->setCurrentIndex(i); // on le met en current
            }
        }
        ui->pushButtonProduitsModifier->setEnabled(true);
        ui->pushButtonProduitsSupprimer->setEnabled(true);
        ui->pushButtonProduitsAnnuler->setEnabled(true);
    }
}

void MainWindow::on_comboBoxProduitsRayons_currentIndexChanged()
{
    //gestion des boutons après le clique (passe tout a true)
    ui->pushButtonProduitsAjouter->setEnabled(true);
    ui->pushButtonProduitsModifier->setEnabled(true);
    ui->pushButtonProduitsSupprimer->setEnabled(true);
    ui->pushButtonProduitsAnnuler->setEnabled(true);
}

void MainWindow::on_lineEditProduits_textChanged()
{
    //gestion des boutons après le clique passe le bouton ajouter et annuler a true
    ui->pushButtonProduitsAjouter->setEnabled(true);
    ui->pushButtonProduitsAnnuler->setEnabled(true);
}

// *********************************************************
// ********************* EN ATTENTE ************************
// ************************ TODO ***************************
// ********************* A CLASSER *************************

void MainWindow::on_pushButtonRayonsModifier_clicked()
{
    //vide le champs edit du rayons
    ui->lineEditRayons->clear();
    //gestion des boutons après le clique (passe tout a false)
    ui->pushButtonRayonsSupprimer->setEnabled(false);
    ui->pushButtonRayonsModifier->setEnabled(false);
    ui->pushButtonRayonsAnnuler->setEnabled(false);
    ui->pushButtonRayonsAjouter->setEnabled(false);
    //charge la nouvelle liste de rayons
    //charge la nouvelle liste de rayons dans la combobox de la page produits
}

void MainWindow::on_pushButtonRayonsAjouter_clicked()
{
    //vide le champs edit du rayons
    ui->lineEditRayons->clear();
    //gestion des boutons après le clique (passe tout a false)
    ui->pushButtonRayonsSupprimer->setEnabled(false);
    ui->pushButtonRayonsModifier->setEnabled(false);
    ui->pushButtonRayonsAnnuler->setEnabled(false);
    ui->pushButtonRayonsAjouter->setEnabled(false);
    //charge la nouvelle liste de rayons
    //charge la nouvelle liste de rayons dans la combobox de la page produits
}

void MainWindow::on_pushButtonRayonsSupprimer_clicked()
{
    //vide le champs edit du rayons
    ui->lineEditRayons->clear();
    //gestion des boutons après le clique (passe tout a false)
    ui->pushButtonRayonsSupprimer->setEnabled(false);
    ui->pushButtonRayonsModifier->setEnabled(false);
    ui->pushButtonRayonsAnnuler->setEnabled(false);
    ui->pushButtonRayonsAjouter->setEnabled(false);
    //charge la nouvelle liste de rayons
    //charge la nouvelle liste de rayons dans la combobox de la page produits
}

void MainWindow::on_lineEditRayons_textChanged()
{
    //quand le texte a était changé passe le bouton annuler et ajouter a true
    ui->pushButtonRayonsAnnuler->setEnabled(true);
    ui->pushButtonRayonsAjouter->setEnabled(true);
}

void MainWindow::on_pushButtonProduitsAjouter_clicked()
{
    //vide le champs edit du produit
    ui->lineEditProduits->clear();
    //vide le champs de recherche de produits
    ui->lineEditRechercheProduits->clear();
    //gestion des boutons après le clique (passe tout a false)
    ui->pushButtonProduitsSupprimer->setEnabled(false);
    ui->pushButtonProduitsModifier->setEnabled(false);
    ui->pushButtonProduitsAnnuler->setEnabled(false);
    ui->pushButtonProduitsAjouter->setEnabled(false);
    //déconnecte
    ui->listWidgetProduits->disconnect();
    //charge la nouvelle liste de produits
    chargerListWidgetProduits();
    //reconnecte
    connect(ui->listWidgetProduits,SIGNAL(currentRowChanged()),this,SLOT(on_lineEditProduits_textChanged()));
    connect(ui->listWidgetProduits,SIGNAL(currentRowChanged()),this,SLOT(on_comboBoxProduitsRayons_currentIndexChanged()));
    //perd la selection de la combobox
}

void MainWindow::on_pushButtonProduitsAnnuler_clicked()
{
    //vide le champs edit du produit
    ui->lineEditProduits->clear();
    //vide le champs de recherche de produits
    ui->lineEditRechercheProduits->clear();
    //gestion des boutons après le clique (passe tout a false)
    ui->pushButtonProduitsAjouter->setEnabled(false);
    ui->pushButtonProduitsModifier->setEnabled(false);
    ui->pushButtonProduitsSupprimer->setEnabled(false);
    ui->pushButtonProduitsAnnuler->setEnabled(false);
    //perd la selection du rayon dans la combobox
    /*ui->comboBoxProduitsRayons->clear();
    chargerComboBoxRayons();*/
}

void MainWindow::on_pushButtonProduitsModifier_clicked()
{
    //vide le champs edit du produit
    ui->lineEditProduits->clear();
    //vide le champs de recherche de produits
    ui->lineEditRechercheProduits->clear();
    //gestion des boutons après le clique (passe tout a false)
    ui->pushButtonProduitsAjouter->setEnabled(false);
    ui->pushButtonProduitsModifier->setEnabled(false);
    ui->pushButtonProduitsSupprimer->setEnabled(false);
    ui->pushButtonProduitsAnnuler->setEnabled(false);
    //perd la selection du rayon dans la combobox
    /*ui->comboBoxProduitsRayons->clear();
    chargerComboBoxRayons();*/
}

void MainWindow::on_pushButtonProduitsSupprimer_clicked()
{
    //vide le champs edit du produit
    ui->lineEditProduits->clear();
    //vide le champs de recherche de produits
    ui->lineEditRechercheProduits->clear();
    //gestion des boutons après le clique (passe tout a false)
    ui->pushButtonProduitsAjouter->setEnabled(false);
    ui->pushButtonProduitsModifier->setEnabled(false);
    ui->pushButtonProduitsSupprimer->setEnabled(false);
    ui->pushButtonProduitsAnnuler->setEnabled(false);
    //perd la selection du rayon dans la combobox
    /*ui->comboBoxProduitsRayons->clear();
    chargerComboBoxRayons();*/
}

void MainWindow::on_lineEditRechercheProduits_textChanged()
{
    ui->pushButtonProduitsAnnuler->setEnabled(true);
    //recharge la liste avec la nouvelle requete
}
