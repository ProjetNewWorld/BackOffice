/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quitter;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tabRayons;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBoxListeRayons;
    QGridLayout *gridLayout;
    QListWidget *listWidgetRayons;
    QGroupBox *groupBoxRayonsEdition;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QFormLayout *formLayout_2;
    QLabel *labelRayonsNomDuRayon;
    QLineEdit *lineEditRayons;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonRayonsAjouter;
    QPushButton *pushButtonRayonsModifier;
    QPushButton *pushButtonRayonsSupprimer;
    QPushButton *pushButtonRayonsAnnuler;
    QWidget *tabProduits;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBoxListeProduits;
    QGridLayout *gridLayout_5;
    QListWidget *listWidgetProduits;
    QLineEdit *lineEditRechercheProduits;
    QGroupBox *groupBoxEditionProduits;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *labelProduitNomDuProduit;
    QLineEdit *lineEditProduits;
    QLabel *labelProduitDansLeRayons;
    QComboBox *comboBoxProduitsRayons;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonProduitsAjouter;
    QPushButton *pushButtonProduitsModifier;
    QPushButton *pushButtonProduitsSupprimer;
    QPushButton *pushButtonProduitsAnnuler;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(587, 413);
        action_Quitter = new QAction(MainWindow);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabRayons = new QWidget();
        tabRayons->setObjectName(QStringLiteral("tabRayons"));
        gridLayout_8 = new QGridLayout(tabRayons);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        groupBoxListeRayons = new QGroupBox(tabRayons);
        groupBoxListeRayons->setObjectName(QStringLiteral("groupBoxListeRayons"));
        gridLayout = new QGridLayout(groupBoxListeRayons);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidgetRayons = new QListWidget(groupBoxListeRayons);
        listWidgetRayons->setObjectName(QStringLiteral("listWidgetRayons"));
        listWidgetRayons->setAlternatingRowColors(true);

        gridLayout->addWidget(listWidgetRayons, 0, 0, 1, 1);


        gridLayout_8->addWidget(groupBoxListeRayons, 0, 0, 1, 1);

        groupBoxRayonsEdition = new QGroupBox(tabRayons);
        groupBoxRayonsEdition->setObjectName(QStringLiteral("groupBoxRayonsEdition"));
        gridLayout_4 = new QGridLayout(groupBoxRayonsEdition);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        labelRayonsNomDuRayon = new QLabel(groupBoxRayonsEdition);
        labelRayonsNomDuRayon->setObjectName(QStringLiteral("labelRayonsNomDuRayon"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelRayonsNomDuRayon);

        lineEditRayons = new QLineEdit(groupBoxRayonsEdition);
        lineEditRayons->setObjectName(QStringLiteral("lineEditRayons"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditRayons);


        verticalLayout_2->addLayout(formLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButtonRayonsAjouter = new QPushButton(groupBoxRayonsEdition);
        pushButtonRayonsAjouter->setObjectName(QStringLiteral("pushButtonRayonsAjouter"));
        pushButtonRayonsAjouter->setEnabled(false);

        gridLayout_2->addWidget(pushButtonRayonsAjouter, 0, 0, 1, 1);

        pushButtonRayonsModifier = new QPushButton(groupBoxRayonsEdition);
        pushButtonRayonsModifier->setObjectName(QStringLiteral("pushButtonRayonsModifier"));
        pushButtonRayonsModifier->setEnabled(false);

        gridLayout_2->addWidget(pushButtonRayonsModifier, 0, 1, 1, 1);

        pushButtonRayonsSupprimer = new QPushButton(groupBoxRayonsEdition);
        pushButtonRayonsSupprimer->setObjectName(QStringLiteral("pushButtonRayonsSupprimer"));
        pushButtonRayonsSupprimer->setEnabled(false);
        pushButtonRayonsSupprimer->setCheckable(false);

        gridLayout_2->addWidget(pushButtonRayonsSupprimer, 1, 0, 1, 1);

        pushButtonRayonsAnnuler = new QPushButton(groupBoxRayonsEdition);
        pushButtonRayonsAnnuler->setObjectName(QStringLiteral("pushButtonRayonsAnnuler"));
        pushButtonRayonsAnnuler->setEnabled(false);

        gridLayout_2->addWidget(pushButtonRayonsAnnuler, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_8->addWidget(groupBoxRayonsEdition, 0, 1, 1, 1);

        tabWidget->addTab(tabRayons, QString());
        tabProduits = new QWidget();
        tabProduits->setObjectName(QStringLiteral("tabProduits"));
        gridLayout_7 = new QGridLayout(tabProduits);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBoxListeProduits = new QGroupBox(tabProduits);
        groupBoxListeProduits->setObjectName(QStringLiteral("groupBoxListeProduits"));
        gridLayout_5 = new QGridLayout(groupBoxListeProduits);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        listWidgetProduits = new QListWidget(groupBoxListeProduits);
        listWidgetProduits->setObjectName(QStringLiteral("listWidgetProduits"));
        listWidgetProduits->setAlternatingRowColors(true);

        gridLayout_5->addWidget(listWidgetProduits, 1, 0, 1, 1);

        lineEditRechercheProduits = new QLineEdit(groupBoxListeProduits);
        lineEditRechercheProduits->setObjectName(QStringLiteral("lineEditRechercheProduits"));

        gridLayout_5->addWidget(lineEditRechercheProduits, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBoxListeProduits, 0, 0, 1, 1);

        groupBoxEditionProduits = new QGroupBox(tabProduits);
        groupBoxEditionProduits->setObjectName(QStringLiteral("groupBoxEditionProduits"));
        gridLayout_6 = new QGridLayout(groupBoxEditionProduits);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelProduitNomDuProduit = new QLabel(groupBoxEditionProduits);
        labelProduitNomDuProduit->setObjectName(QStringLiteral("labelProduitNomDuProduit"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelProduitNomDuProduit);

        lineEditProduits = new QLineEdit(groupBoxEditionProduits);
        lineEditProduits->setObjectName(QStringLiteral("lineEditProduits"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditProduits);

        labelProduitDansLeRayons = new QLabel(groupBoxEditionProduits);
        labelProduitDansLeRayons->setObjectName(QStringLiteral("labelProduitDansLeRayons"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelProduitDansLeRayons);

        comboBoxProduitsRayons = new QComboBox(groupBoxEditionProduits);
        comboBoxProduitsRayons->setObjectName(QStringLiteral("comboBoxProduitsRayons"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxProduitsRayons);


        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButtonProduitsAjouter = new QPushButton(groupBoxEditionProduits);
        pushButtonProduitsAjouter->setObjectName(QStringLiteral("pushButtonProduitsAjouter"));
        pushButtonProduitsAjouter->setEnabled(false);

        gridLayout_3->addWidget(pushButtonProduitsAjouter, 0, 0, 1, 1);

        pushButtonProduitsModifier = new QPushButton(groupBoxEditionProduits);
        pushButtonProduitsModifier->setObjectName(QStringLiteral("pushButtonProduitsModifier"));
        pushButtonProduitsModifier->setEnabled(false);

        gridLayout_3->addWidget(pushButtonProduitsModifier, 0, 1, 1, 1);

        pushButtonProduitsSupprimer = new QPushButton(groupBoxEditionProduits);
        pushButtonProduitsSupprimer->setObjectName(QStringLiteral("pushButtonProduitsSupprimer"));
        pushButtonProduitsSupprimer->setEnabled(false);

        gridLayout_3->addWidget(pushButtonProduitsSupprimer, 1, 0, 1, 1);

        pushButtonProduitsAnnuler = new QPushButton(groupBoxEditionProduits);
        pushButtonProduitsAnnuler->setObjectName(QStringLiteral("pushButtonProduitsAnnuler"));
        pushButtonProduitsAnnuler->setEnabled(false);

        gridLayout_3->addWidget(pushButtonProduitsAnnuler, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);


        gridLayout_6->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBoxEditionProduits, 0, 1, 1, 1);

        tabWidget->addTab(tabProduits, QString());

        verticalLayout_3->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 587, 22));
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(listWidgetRayons, lineEditRayons);
        QWidget::setTabOrder(lineEditRayons, pushButtonRayonsAjouter);
        QWidget::setTabOrder(pushButtonRayonsAjouter, pushButtonRayonsModifier);
        QWidget::setTabOrder(pushButtonRayonsModifier, pushButtonRayonsSupprimer);
        QWidget::setTabOrder(pushButtonRayonsSupprimer, pushButtonRayonsAnnuler);
        QWidget::setTabOrder(pushButtonRayonsAnnuler, tabWidget);
        QWidget::setTabOrder(tabWidget, lineEditRechercheProduits);
        QWidget::setTabOrder(lineEditRechercheProduits, listWidgetProduits);
        QWidget::setTabOrder(listWidgetProduits, lineEditProduits);
        QWidget::setTabOrder(lineEditProduits, comboBoxProduitsRayons);
        QWidget::setTabOrder(comboBoxProduitsRayons, pushButtonProduitsAjouter);
        QWidget::setTabOrder(pushButtonProduitsAjouter, pushButtonProduitsModifier);
        QWidget::setTabOrder(pushButtonProduitsModifier, pushButtonProduitsSupprimer);
        QWidget::setTabOrder(pushButtonProduitsSupprimer, pushButtonProduitsAnnuler);

        menuBar->addAction(menu_Fichier->menuAction());
        menu_Fichier->addAction(action_Quitter);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BackOffice - NewWorld", 0));
        action_Quitter->setText(QApplication::translate("MainWindow", "&Quitter", 0));
        groupBoxListeRayons->setTitle(QApplication::translate("MainWindow", "Liste des rayons", 0));
        groupBoxRayonsEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        labelRayonsNomDuRayon->setText(QApplication::translate("MainWindow", "Nom du rayon", 0));
        pushButtonRayonsAjouter->setText(QApplication::translate("MainWindow", "&Ajouter", 0));
        pushButtonRayonsModifier->setText(QApplication::translate("MainWindow", "&Modifier", 0));
        pushButtonRayonsSupprimer->setText(QApplication::translate("MainWindow", "&Supprimer", 0));
        pushButtonRayonsAnnuler->setText(QApplication::translate("MainWindow", "&Annuler", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabRayons), QApplication::translate("MainWindow", "Rayons", 0));
        groupBoxListeProduits->setTitle(QApplication::translate("MainWindow", "Liste des produits", 0));
        groupBoxEditionProduits->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        labelProduitNomDuProduit->setText(QApplication::translate("MainWindow", "Nom du produit", 0));
        labelProduitDansLeRayons->setText(QApplication::translate("MainWindow", "Dans le rayon", 0));
        pushButtonProduitsAjouter->setText(QApplication::translate("MainWindow", "&Ajouter", 0));
        pushButtonProduitsModifier->setText(QApplication::translate("MainWindow", "&Modifier", 0));
        pushButtonProduitsSupprimer->setText(QApplication::translate("MainWindow", "&Supprimer", 0));
        pushButtonProduitsAnnuler->setText(QApplication::translate("MainWindow", "&Annuler", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabProduits), QApplication::translate("MainWindow", "Produits", 0));
        menu_Fichier->setTitle(QApplication::translate("MainWindow", "&Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
