/**
  * @date 07/06/2014
  * @author Nicolas Capiaumont
  * @version V1.0
  * @brief Application BackOffice du groupe NewWorld pour l'application des courses
  * Permet de supprimer, modifier et ajouter un rayon ou un produit.
  * https://github.com/ProjetNewWorld/BackOffice
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * Constructeur de la MainWindow
 * Effectue la connexion à la base de données, si tout c'est bien passé crée l'ui et charge les pages rayons et produits
 * Si la connexion est à la base de données n'est pas possible affiche un message d'erreur
 * Initialise l'application sur la page des produits
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
        ui->tabProduits->setFocus();
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

/**
 * @brief MainWindow::on_tabWidget_tabBarClicked
 * Charge au clique sur la tabWidget les deux pages (produits et rayons)
 */
void MainWindow::on_tabWidget_tabBarClicked()
{
    //charge au clique sur la tabWidget les deux pages (produits et rayons)
    this->chargePageProduits();
    this->chargePageRayons();
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
 * @brief MainWindow::getVectorIdProduit
 * @param rayonId
 * @return Revoit un vecteur qui contient l'id de tout les produits qui sont dans le rayon dont l'id est passé en paramétre
 */
QVector<QString> MainWindow::getVecteurIdProduit(QString idRayon)
{
    //déclaration du vecteurIdProduit
    QVector <QString> vecteurIdProduit;
    //requete qui renvoit tous les produits du rayon avec l'id idRayon
    QSqlQuery req("select produitId from produit where rayonId="+idRayon);
    //remplit le vecteur avec chaque produits du rayons
    while(req.next())
    {
        vecteurIdProduit.push_back(req.value(0).toString());
    }
    //retourne le vecteurIdProduit remplit
    return vecteurIdProduit;
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
 * @brief MainWindow::on_pushButtonRayonsAjouter_clicked
 * Recherche voir si le rayon n'existe pas
 * Si il n'y a pas de résultat donc pas de rayon avec ce nom
 * Requete d'ajout d'un rayon
 * Recharge la page des rayons
 * Sinon le rayon existe affiche un message d'erreur (existe déjà)
 */
void MainWindow::on_pushButtonRayonsAjouter_clicked()
{
    //recherche voir si le rayon n'existe pas
    QSqlQuery recherche("select * from rayon where rayonLib='"+ui->lineEditRayons->text()+"'");
    recherche.first();
    //si il n'y a pas de résultat donc pas de rayon avec ce nom
    if(!(recherche.size()>0))
    {
        //requete d'ajout d'un rayon
        QSqlQuery req("insert into rayon (rayonLib) values ('"+ui->lineEditRayons->text()+"')");
        //qDebug()<<"insert into rayon (rayonLib) values ('"+ui->lineEditRayons->text()+"')";
        //recharge la page des rayons
        this->chargePageRayons();
    }
    //sinon le rayon existe affiche un message d'erreur (existe déjà)
    else
    {
        QMessageBox::warning(this,"Erreur", "Ce rayon existe déjà !");
    }
}

/**
 * @brief MainWindow::on_pushButtonRayonsModifier_clicked
 * Requete de vérification, si le rayon n'existe pas déjà
 * Si le rayon n'existe pas on peut le mettre à jour
 * Requete de modification d'un rayon
 * Recharge la page des rayons
 * Sinon affiche un message d'erreur
 */
void MainWindow::on_pushButtonRayonsModifier_clicked()
{
    //déclaration de la requete
    QString requeteVerif="select * from rayon where rayonLib ='"+ui->lineEditRayons->text()+"'";
    //qDebug()<<requeteVerif;
    //requete de vérification, si le rayon n'existe pas déjà
    QSqlQuery requeteVerifExistRayon(requeteVerif);
    requeteVerifExistRayon.first();
    //si le rayon n'existe pas on peut le mettre à jour
    if(!(requeteVerifExistRayon.size()>0))
    {
        //déclaration de la requete
        QString requete="update rayon set rayonLib='"+ui->lineEditRayons->text()+"' where rayonId = "+vectorRayons.value(ui->listWidgetRayons->currentRow());
        //requete de modification d'un rayon
        QSqlQuery requeteModificationRayon(requete);
        //recharge la page des rayons
        this->chargePageRayons();
    }
    //sinon affiche un message d'erreur
    else
    {
        //message d'erreur si le rayon existe déjà
        QMessageBox::warning(this,"Erreur modification","Modification impossible, le nom de rayon est déjà utilisé");
    }
}

/**
 * @brief MainWindow::on_pushButtonRayonsSupprimer_clicked
 * Récupére la ligne selectionné
 * Demande si on est sur de vouloir supprimer le rayon avec tous les produits associés au rayon
 * Si la reponse est oui supprime les produits du rayon, des listes et le rayon
 * Recupére tous les produits dans un vecteur
 * Supprime tous les produits dans contenuliste si le produits était dans une liste, tous les produits dans le rayon et le rayon
 * Recharge la liste des rayons et les produits
 */
void MainWindow::on_pushButtonRayonsSupprimer_clicked()
{
    //récupére la ligne selectionné
    QString rayonId=vectorRayons.value(ui->listWidgetRayons->currentRow());
    //demande si on est sur de vouloir supprimer le rayon avec tous les produits associés au rayon
    int reponse=QMessageBox::question(this, "Confirmation de suppression", "Êtes-vous sûr de vouloir supprimer le rayon '"+ui->listWidgetRayons->currentItem()->text()+"', et tout les produits qu'il contient ? Celà supprimera également ces produits dans les éventuelles listes de courses.", QMessageBox::Yes | QMessageBox::Cancel);
    switch (reponse) {
    //si la reponse est oui supprime les produits du rayon, des listes et le rayon
    case QMessageBox::Yes:
        //recupére tous les produits dans un vecteur
        QVector <QString> vecteurIdProduit=getVecteurIdProduit(rayonId);
        for(int i=0;i<vecteurIdProduit.size();i++)
        {
            //requete qui supprime chaque contenuliste si le produits était dedans
            QSqlQuery requeteSupprimeContenulisteProduits("delete from contenuliste where produitId = "+vecteurIdProduit.value(i));
        }
        //requetes de suppression
        QSqlQuery requeteSupprimeProduitsDansRayons("delete from produit where rayonId = "+rayonId);
        QSqlQuery requeteSupprimeRayons("delete from rayon where rayonId = "+rayonId);
        //charge la page produits
        this->chargePageProduits();
        //charge la page rayons
        this->chargePageRayons();
        break;
    }
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
    requete.first();
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
 * @brief MainWindow::getIdRayonByName
 * @param rayonLib
 * requete de selection de l'id par rapport au nom du rayon
 * @return l'id du rayon par rapport à son libelle
 */
QString MainWindow::getIdRayonByName(QString rayonLib)
{
    //requete de selection de l'id par rapport au nom du rayon
    QSqlQuery requeteRayonIdByName("select rayonId from rayon where rayonLib='"+rayonLib+"'");
    requeteRayonIdByName.first();
    //retourne l'id du rayon par rapport a son libelle
    return requeteRayonIdByName.value(0).toString();
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
        this->chargerComboBoxRayons(); // on charge la liste des rayons (combo box)
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
void MainWindow::on_comboBoxProduitsRayons_currentIndexChanged(int)
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
 * @brief MainWindow::on_pushButtonProduitsAjouter_clicked
 * Requete de verification pour savoir si le produit existe ou pas
 * Si le rayon n'existe pas
 * Recupére l'id du rayon selectionné dans la combobox
 * Requete d'ajout du nouveau produit (produitLib et rayonId)
 * Charge la page des produits
 * Sinon affiche un message d'erreur (existe déjà)
 */
void MainWindow::on_pushButtonProduitsAjouter_clicked()
{
    //requete de verification pour savoir si le produit existe ou pas
    QSqlQuery req("select * from produit where produitLib='"+ui->lineEditProduits->text()+"'");
    req.first();
    //si le rayon n'existe pas
    if(!(req.size()>0))
    {
        //recupére l'id du rayon selectionné dans la combobox
        QString rayonId=getIdRayonByName(ui->comboBoxProduitsRayons->currentText());
        //requete d'ajout du nouveau produit (produitLib et rayonId)
        QSqlQuery requeteAjoutProduit("insert into produit (produitLib, rayonId) values ('"+ui->lineEditProduits->text()+"',"+rayonId+")");
        //charge la page des produits
        this->chargePageProduits();
    }
    //sinon affiche un message d'erreur (existe déjà)
    else
    {
        QMessageBox::warning(this,"Erreur", "Ce produit existe déjà !");
    }
}

/**
 * @brief MainWindow::on_pushButtonProduitsSupprimer_clicked
 * Recupére l'id du produit dans le vecteur grace a la ligne selectionné dans la listWidgetProduits
 * Message de verification du suppression d'un produit
 * Si la réponse est oui
 * Supprime le produit dans les contenuListe
 * Supprime le produits
 * Charge la page des produits
 */
void MainWindow::on_pushButtonProduitsSupprimer_clicked()
{
    //recupére l'id du produit dans le vecteur grace a la ligne selectionné dans la listWidgetProduits
    QString produitId=vectorRayonsProduits.value(ui->listWidgetProduits->currentRow());
    //Message de verification du suppression d'un produit
    int reponse=QMessageBox::question(this, "Confirmation de suppression", "Êtes-vous sûr de vouloir supprimer le produit '"+ui->listWidgetProduits->currentItem()->text()+"'. Celà supprimera également ce produit dans les éventuelles listes de courses.", QMessageBox::Yes | QMessageBox::Cancel);
    switch (reponse) {
    //si la réponse est oui
    case QMessageBox::Yes:
        //supprime le produit dans les contenuListe
        QSqlQuery requeteSuppressionProduitContenuListe("delete from contenuliste where produitId = "+produitId);
        //supprime le produits
        QSqlQuery requeteSuppressionProduit("delete from produit where produitId = "+produitId);
        //charge la page des produits
        this->chargePageProduits();
        break;
    }
}

/**
 * @brief MainWindow::on_pushButtonProduitsModifier_clicked
 * Requete de vérification, si le produit n'existe pas déjà
 * Si le produit n'existe pas on peut le mettre à jour
 * Requete de modification du libellé du produit
 * Recharge la page des produits
 * Sinon affiche un message d'erreur
 * Message d'erreur si le produit existe déjà
 */
void MainWindow::on_pushButtonProduitsModifier_clicked()
{
    //déclaration de la requete
    QString requeteVerifProduit="select * from produit where produitLib ='"+ui->lineEditProduits->text()+"'";
    //requete de vérification, si le produit n'existe pas déjà
    QSqlQuery requeteVerifExistProduit(requeteVerifProduit);
    requeteVerifExistProduit.first();
    //si le produit n'existe pas on peut le mettre à jour
    if(!(requeteVerifExistProduit.size()>0))
    {
        //requete de modification du libellé du produit
        QSqlQuery requeteModificationProduit("update produit set produitLib='"+ui->lineEditProduits->text()+"', rayonId="+getIdRayonByName(ui->comboBoxProduitsRayons->currentText())+" where produitId = "+vectorRayonsProduits.value(ui->listWidgetProduits->currentRow())+"");
        //recharge la page des produits
        this->chargePageProduits();
    }
    //sinon affiche un message d'erreur
    else
    {
        //message d'erreur si le produit existe déjà
        QMessageBox::warning(this,"Erreur modification","Modification impossible, le nom du produit est déjà utilisé");
    }
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
