#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * Constructeur de la MainWindow
 * Effectue la connexion à la base de données, si tout c'est bien passé crée l'ui et charge les pages rayons et produits
 * Si la connexion est à la base de données n'est pas possible affiche un message d'erreur
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    if(connectBase()) // si la connexion c'est bien passé
    {
        ui->setupUi(this);
        this->chargerListWidgetRayons();
        this->chargerListWidgetProduits();
    }
    else // sinon on affiche un message d'erreur
    {
        QMessageBox::critical(this,"Erreur critique", "Impossible d'ouvrir la base de données.");
    }
}

/**
 * @brief MainWindow::~MainWindow
 * Destructeur de la MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

// *********************************************************
// ****************** Base de données **********************
/**
 * @brief MainWindow::connectBase , permet la connexion a la base de données
 * @return TRUE si la connexion à la base à marché , retourne FALSE sinon
 */
bool MainWindow::connectBase()
{
    //varibles contenant l'hote, le nom, le mot de passe, le nom de la base de données
    QString hote="127.0.0.1";
    QString name="userLDC";
    QString pass="passLDC";
    QString bdd="listedescourses";
    //connexion à la base de données avec les variables
    listedescourses=QSqlDatabase::addDatabase("QMYSQL");
    listedescourses.setHostName(hote);
    listedescourses.setPassword(pass);
    listedescourses.setUserName(name);
    listedescourses.setDatabaseName(bdd);
    //connexion
    return listedescourses.open();
}

// *********************************************************
// *********************** Commun **************************
/**
 * @brief MainWindow::on_action_Quitter_triggered
 * Ferme l'application
 */
void MainWindow::on_action_Quitter_triggered()
{
    this->close();
}

/**
 * @brief MainWindow::chargerComboBoxRayons
 * Vide la combobox : comboBoxProduitsRayons
 * Charger la combobox : comboBoxProduitsRayons
 */
void MainWindow::chargerComboBoxRayons()
{
    //vide la combo box
    ui->comboBoxProduitsRayons->clear();
    //ajoute une valeur selectionnez un rayon
    ui->comboBoxProduitsRayons->addItem("Selectionnez un rayon");
    //requete de selection sur le libellé des rayons
    QSqlQuery req("select rayonLib from rayon");
    while(req.next())
    {
        ui->comboBoxProduitsRayons->addItem(req.value(0).toString());
    }
}

// *********************************************************
// *********************** Rayons **************************
/**
 * @brief MainWindow::chargerListWidgetRayons
 * Vide la listWidgetRayons, la lineEditRayons, le vectorRayons
 */
void MainWindow::chargerListWidgetRayons()
{
    //Vide la listWidgetRayons, la lineEditRayons, le vectorRayons
    ui->listWidgetRayons->clear();
    ui->lineEditRayons->clear();
    vectorRayons.clear();
    int i=0;
    //requete pour récupérer l'id et le lib des rayons
    QSqlQuery req("select rayonId, rayonLib from rayon order by rayonLib");
    while(req.next())
    {
        QListWidgetItem *item=new QListWidgetItem(req.value(1).toString());
        i++;
        ui->listWidgetRayons->addItem(item);
        vectorRayons.push_back(req.value(0).toString());
    }
    if(i==0)//s'il n'y a pas de rayons
    {
        ui->listWidgetRayons->addItem("Pas de rayon");
    }
}

/**
 * @brief MainWindow::chargePageRayons
 * Vide le champ : lineEditRayons
 * Recharge la liste des rayons
 * Passe tous les boutons de la page rayons a enable false
 */
void MainWindow::chargePageRayons()
{
    //vide le champ
    ui->lineEditRayons->clear();
    //recharge la liste des rayons
    this->chargerListWidgetRayons();
    //passe tous les boutons de la page rayons a enable false
    ui->pushButtonRayonsSupprimer->setEnabled(false);
    ui->pushButtonRayonsModifier->setEnabled(false);
    ui->pushButtonRayonsAnnuler->setEnabled(false);
    ui->pushButtonRayonsAjouter->setEnabled(false);
}

/**
 * @brief MainWindow::on_listWidgetRayons_clicked
 * Rempli lineEditRayons avec ce qui a été cliqué dans la listWidgetRayons
 * Passe les boutons modifier, supprimer, annuler, ajouter à TRUE
 */
void MainWindow::on_listWidgetRayons_clicked()
{
    //rempli lineEditRayons avec ce qui a été cliqué
    ui->lineEditRayons->setText(ui->listWidgetRayons->currentItem()->text());
    //Passe les boutons modifier, supprimer, annuler, ajouter à TRUE
    ui->pushButtonRayonsModifier->setEnabled(true);
    ui->pushButtonRayonsSupprimer->setEnabled(true);
    ui->pushButtonRayonsAnnuler->setEnabled(true);
    ui->pushButtonRayonsAjouter->setEnabled(true);
}

/**
 * @brief MainWindow::on_lineEditRayons_textChanged
 * Quand le texte a été changé passe le bouton annuler et ajouter a TRUE
 */
void MainWindow::on_lineEditRayons_textChanged()
{
    //quand le texte a été changé passe le bouton annuler et ajouter a true
    ui->pushButtonRayonsAnnuler->setEnabled(true);
    ui->pushButtonRayonsAjouter->setEnabled(true);
}

/**
 * @brief MainWindow::on_pushButtonRayonsAnnuler_clicked
 * Recharge la page rayon
 */
void MainWindow::on_pushButtonRayonsAnnuler_clicked()
{
    //recharge la page rayon
    this->chargePageRayons();
}

// *********************************************************
// ********************** Produits *************************
/**
 * @brief MainWindow::chargerListWidgetProduits
 * Vide la liste widget produit
 * Charge la combobox avec les rayons
 * Vide les vecteur associés a la liste widget produits
 * Charge la listWidgetProduits avec les produits dans les rayons
 */
void MainWindow::chargerListWidgetProduits(){
    //vide la liste widget produit
    ui->listWidgetProduits->clear();
    //charge la combobox avec les rayons
    chargerComboBoxRayons();
    //vide les vecteur associés a la liste widget produits
    vectorRayonsProduits.clear();
    vectorPositionInListOfRayon.clear();
    int i=0;
    QString rayon;
    //requete qui permet d'afficher les produits dans les rayons
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
    if(i==0)
    {
        ui->listWidgetProduits->addItem("Aucun produit");
    }
}

/**
 * @brief MainWindow::chargePageProduits
 * Vide les champs : lineEditRechercheProduits, lineEditProduits
 * Recharge la liste des produits dans les rayons
 * Passe tous les boutons de la page produits a enable false
 */
void MainWindow::chargePageProduits()
{
    //vide tous les champs
    ui->lineEditRechercheProduits->clear();
    ui->lineEditProduits->clear();
    //recharge la liste des produits dans les rayons
    this->chargerListWidgetProduits();
    //passe tous les boutons de la page produits a enable false
    ui->pushButtonRayonsSupprimer->setEnabled(false);
    ui->pushButtonRayonsModifier->setEnabled(false);
    ui->pushButtonRayonsAnnuler->setEnabled(false);
    ui->pushButtonRayonsAjouter->setEnabled(false);
}

/**
 * @brief MainWindow::getRayonByProduit
 * @param idProd
 * @return rayonLib s'il y a un rayon avec l'idProd
 * @return Message qui dit qu'il n'y a pas de produit avec l'id qui existe ou alors il n'a pas de rayons
 */
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

/**
 * @brief MainWindow::on_listWidgetProduits_clicked
 * Rempli les champs : lineEditProduits, comboBoxProduitsRayons
 * Quand on clique sur la listWidgetProduits
 */
void MainWindow::on_listWidgetProduits_clicked()
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

/**
 * @brief MainWindow::on_comboBoxProduitsRayons_currentIndexChanged
 * Gestion des boutons quand changement d'index sur la comboBoxProduitsRayons passe tout à true
 */
void MainWindow::on_comboBoxProduitsRayons_currentIndexChanged()
{
    //gestion des boutons après le clique (passe tout a true)
    ui->pushButtonProduitsAjouter->setEnabled(true);
    ui->pushButtonProduitsModifier->setEnabled(true);
    ui->pushButtonProduitsSupprimer->setEnabled(true);
    ui->pushButtonProduitsAnnuler->setEnabled(true);
}

/**
 * @brief MainWindow::on_lineEditRechercheProduits_textChanged
 * Met le bouton annuler à true
 * Recharge la liste avec la nouvelle requete (lineEditRechercheProduits)
 */
void MainWindow::on_lineEditRechercheProduits_textChanged()
{
    //met le bouton annuler à true
    ui->pushButtonProduitsAnnuler->setEnabled(true);
    //recharge la liste avec la nouvelle requete
    this->chargerListWidgetProduits();
}

/**
 * @brief MainWindow::on_pushButtonProduitsAnnuler_clicked
 * Recharge la page des produits
 */
void MainWindow::on_pushButtonProduitsAnnuler_clicked()
{
    //recharge la page des produits
    this->chargePageProduits();
}

/**
 * @brief MainWindow::on_lineEditProduits_textChanged
 * Gestion des boutons après modification de la lineEditProduits passe le bouton ajouter et annuler a true
 */
void MainWindow::on_lineEditProduits_textChanged()
{
    //gestion des boutons après modification de la lineEditProduits passe le bouton ajouter et annuler a true
    ui->pushButtonProduitsAjouter->setEnabled(true);
    ui->pushButtonProduitsAnnuler->setEnabled(true);
}

// *********************************************************
// ********************* EN ATTENTE ************************
// ************************ TODO ***************************
// ********************* A CLASSER *************************
void MainWindow::on_pushButtonRayonsModifier_clicked()
{
    //recharge la page des rayons
    this->chargePageRayons();
    //requete de modification d'un rayon
}

void MainWindow::on_pushButtonRayonsAjouter_clicked()
{
    //recharge la page des rayons
    this->chargePageRayons();
    //requete d'ajout d'un rayon
}

void MainWindow::on_pushButtonRayonsSupprimer_clicked()
{
    //recharge la page des rayons
    this->chargePageRayons();
    //requete de suppression d'un rayon
}

void MainWindow::on_pushButtonProduitsAjouter_clicked()
{
    //recharge la page des produits
    this->chargePageProduits();
    //requete d'ajout d'un produit
}

void MainWindow::on_pushButtonProduitsModifier_clicked()
{
    //recharge la page des produits
    this->chargePageProduits();
    //requete de modification d'un produit
}

void MainWindow::on_pushButtonProduitsSupprimer_clicked()
{
    //recharge la page des produits
    this->chargePageProduits();
    //requete de suppression d'un produit
}
