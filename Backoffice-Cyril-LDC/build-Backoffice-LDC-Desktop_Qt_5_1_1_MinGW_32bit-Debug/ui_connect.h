/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connect
{
public:
    QLabel *label_3;
    QLabel *labelEroor;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditMdp;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonAnnuler;

    void setupUi(QDialog *connect)
    {
        if (connect->objectName().isEmpty())
            connect->setObjectName(QStringLiteral("connect"));
        connect->resize(400, 300);
        label_3 = new QLabel(connect);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 40, 131, 21));
        label_3->setStyleSheet(QLatin1String("color:white;\n"
"background-color:rgba(0,0,0,0);"));
        labelEroor = new QLabel(connect);
        labelEroor->setObjectName(QStringLiteral("labelEroor"));
        labelEroor->setGeometry(QRect(50, 60, 291, 21));
        labelEroor->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"color:white;"));
        groupBox = new QGroupBox(connect);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 80, 291, 161));
        groupBox->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(8, 16, 256, 113));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color:white;\n"
"background-color:rgba(0,0,0,0);"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color:white;\n"
"background-color:rgba(0,0,0,0);"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEditLogin = new QLineEdit(layoutWidget);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));

        verticalLayout_2->addWidget(lineEditLogin);

        lineEditMdp = new QLineEdit(layoutWidget);
        lineEditMdp->setObjectName(QStringLiteral("lineEditMdp"));

        verticalLayout_2->addWidget(lineEditMdp);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonOK = new QPushButton(layoutWidget);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setEnabled(false);
        pushButtonOK->setStyleSheet(QStringLiteral("background-color:white;"));

        horizontalLayout_2->addWidget(pushButtonOK);

        pushButtonAnnuler = new QPushButton(layoutWidget);
        pushButtonAnnuler->setObjectName(QStringLiteral("pushButtonAnnuler"));
        pushButtonAnnuler->setStyleSheet(QStringLiteral("background-color:white;"));

        horizontalLayout_2->addWidget(pushButtonAnnuler);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(connect);

        QMetaObject::connectSlotsByName(connect);
    } // setupUi

    void retranslateUi(QDialog *connect)
    {
        connect->setWindowTitle(QApplication::translate("connect", "Dialog", 0));
        label_3->setText(QApplication::translate("connect", "Connectez-vous !", 0));
        labelEroor->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("connect", "Login :", 0));
        label_2->setText(QApplication::translate("connect", "Mot de passe :", 0));
        pushButtonOK->setText(QApplication::translate("connect", "OK", 0));
        pushButtonAnnuler->setText(QApplication::translate("connect", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class connect: public Ui_connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
