/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidgetRayon;
    QPushButton *pushButtonAjouterRayon;
    QPushButton *pushButtonModifierRayon;
    QPushButton *pushButtonSupprimerRayon;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditSearchRayon;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditNomRayon;
    QWidget *tab_2;
    QListWidget *listWidgetProduits;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEditSearchProduit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEditNomProduit;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBoxRayonProduit;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonAjouterProduit;
    QPushButton *pushButtonModifierProduit;
    QPushButton *pushButtonSupprimerProduit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 579);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: italic 14pt \"Dotum\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        listWidgetRayon = new QListWidget(tab);
        listWidgetRayon->setObjectName(QStringLiteral("listWidgetRayon"));
        listWidgetRayon->setGeometry(QRect(20, 80, 281, 421));
        pushButtonAjouterRayon = new QPushButton(tab);
        pushButtonAjouterRayon->setObjectName(QStringLiteral("pushButtonAjouterRayon"));
        pushButtonAjouterRayon->setGeometry(QRect(420, 190, 75, 23));
        pushButtonModifierRayon = new QPushButton(tab);
        pushButtonModifierRayon->setObjectName(QStringLiteral("pushButtonModifierRayon"));
        pushButtonModifierRayon->setGeometry(QRect(420, 240, 75, 23));
        pushButtonSupprimerRayon = new QPushButton(tab);
        pushButtonSupprimerRayon->setObjectName(QStringLiteral("pushButtonSupprimerRayon"));
        pushButtonSupprimerRayon->setGeometry(QRect(420, 290, 75, 23));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 211, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditSearchRayon = new QLineEdit(layoutWidget);
        lineEditSearchRayon->setObjectName(QStringLiteral("lineEditSearchRayon"));

        horizontalLayout->addWidget(lineEditSearchRayon);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(340, 80, 301, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditNomRayon = new QLineEdit(layoutWidget1);
        lineEditNomRayon->setObjectName(QStringLiteral("lineEditNomRayon"));

        horizontalLayout_2->addWidget(lineEditNomRayon);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        listWidgetProduits = new QListWidget(tab_2);
        listWidgetProduits->setObjectName(QStringLiteral("listWidgetProduits"));
        listWidgetProduits->setGeometry(QRect(30, 80, 341, 391));
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 40, 224, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEditSearchProduit = new QLineEdit(layoutWidget2);
        lineEditSearchProduit->setObjectName(QStringLiteral("lineEditSearchProduit"));

        horizontalLayout_3->addWidget(lineEditSearchProduit);

        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(420, 100, 224, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEditNomProduit = new QLineEdit(layoutWidget3);
        lineEditNomProduit->setObjectName(QStringLiteral("lineEditNomProduit"));

        horizontalLayout_4->addWidget(lineEditNomProduit);

        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(420, 140, 231, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        comboBoxRayonProduit = new QComboBox(layoutWidget4);
        comboBoxRayonProduit->setObjectName(QStringLiteral("comboBoxRayonProduit"));

        horizontalLayout_5->addWidget(comboBoxRayonProduit);

        layoutWidget5 = new QWidget(tab_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(470, 230, 151, 171));
        verticalLayout = new QVBoxLayout(layoutWidget5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAjouterProduit = new QPushButton(layoutWidget5);
        pushButtonAjouterProduit->setObjectName(QStringLiteral("pushButtonAjouterProduit"));

        verticalLayout->addWidget(pushButtonAjouterProduit);

        pushButtonModifierProduit = new QPushButton(layoutWidget5);
        pushButtonModifierProduit->setObjectName(QStringLiteral("pushButtonModifierProduit"));

        verticalLayout->addWidget(pushButtonModifierProduit);

        pushButtonSupprimerProduit = new QPushButton(layoutWidget5);
        pushButtonSupprimerProduit->setObjectName(QStringLiteral("pushButtonSupprimerProduit"));

        verticalLayout->addWidget(pushButtonSupprimerProduit);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Backoffice - Liste de courses", 0));
        label->setText(QApplication::translate("MainWindow", "Backoffice : G\303\251rer votre application de liste de courses", 0));
        pushButtonAjouterRayon->setText(QApplication::translate("MainWindow", "Ajouter", 0));
        pushButtonModifierRayon->setText(QApplication::translate("MainWindow", "Modifier", 0));
        pushButtonSupprimerRayon->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        label_2->setText(QApplication::translate("MainWindow", "Nom du Rayon : ", 0));
#ifndef QT_NO_TOOLTIP
        lineEditSearchRayon->setToolTip(QApplication::translate("MainWindow", "Ex : Boucherie", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "Nom du Rayon", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Les Rayons", 0));
        label_4->setText(QApplication::translate("MainWindow", "Nom du Produit : ", 0));
        label_5->setText(QApplication::translate("MainWindow", "Nom du produit : ", 0));
        label_6->setText(QApplication::translate("MainWindow", "Rayon du Produit : ", 0));
        pushButtonAjouterProduit->setText(QApplication::translate("MainWindow", "Ajouter", 0));
        pushButtonModifierProduit->setText(QApplication::translate("MainWindow", "Modifier", 0));
        pushButtonSupprimerProduit->setText(QApplication::translate("MainWindow", "Supprimer", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Les Produits", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
