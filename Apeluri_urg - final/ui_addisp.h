/********************************************************************************
** Form generated from reading UI file 'addisp.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDISP_H
#define UI_ADDISP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdDisp
{
public:
    QLineEdit *linie_username;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *linie_parola;
    QLabel *label_3;
    QLineEdit *linie_email;
    QLabel *label_4;
    QLineEdit *linie_nume;
    QLabel *label_5;
    QLineEdit *linie_prenume;
    QLabel *label_6;
    QLineEdit *linie_tip;
    QPushButton *pushButton;
    QLabel *label_7;
    QLineEdit *linie_tel;

    void setupUi(QDialog *AdDisp)
    {
        if (AdDisp->objectName().isEmpty())
            AdDisp->setObjectName(QString::fromUtf8("AdDisp"));
        AdDisp->resize(400, 500);
        linie_username = new QLineEdit(AdDisp);
        linie_username->setObjectName(QString::fromUtf8("linie_username"));
        linie_username->setGeometry(QRect(20, 40, 171, 26));
        label = new QLabel(AdDisp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 71, 20));
        label_2 = new QLabel(AdDisp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 71, 20));
        linie_parola = new QLineEdit(AdDisp);
        linie_parola->setObjectName(QString::fromUtf8("linie_parola"));
        linie_parola->setGeometry(QRect(20, 90, 171, 26));
        linie_parola->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(AdDisp);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 170, 71, 20));
        linie_email = new QLineEdit(AdDisp);
        linie_email->setObjectName(QString::fromUtf8("linie_email"));
        linie_email->setGeometry(QRect(20, 190, 171, 26));
        label_4 = new QLabel(AdDisp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 230, 71, 20));
        linie_nume = new QLineEdit(AdDisp);
        linie_nume->setObjectName(QString::fromUtf8("linie_nume"));
        linie_nume->setGeometry(QRect(20, 250, 171, 26));
        label_5 = new QLabel(AdDisp);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 290, 71, 20));
        linie_prenume = new QLineEdit(AdDisp);
        linie_prenume->setObjectName(QString::fromUtf8("linie_prenume"));
        linie_prenume->setGeometry(QRect(20, 310, 171, 26));
        label_6 = new QLabel(AdDisp);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 350, 131, 20));
        linie_tip = new QLineEdit(AdDisp);
        linie_tip->setObjectName(QString::fromUtf8("linie_tip"));
        linie_tip->setGeometry(QRect(20, 370, 171, 26));
        pushButton = new QPushButton(AdDisp);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 450, 93, 29));
        label_7 = new QLabel(AdDisp);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 400, 61, 20));
        linie_tel = new QLineEdit(AdDisp);
        linie_tel->setObjectName(QString::fromUtf8("linie_tel"));
        linie_tel->setGeometry(QRect(20, 420, 171, 26));

        retranslateUi(AdDisp);

        QMetaObject::connectSlotsByName(AdDisp);
    } // setupUi

    void retranslateUi(QDialog *AdDisp)
    {
        AdDisp->setWindowTitle(QCoreApplication::translate("AdDisp", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AdDisp", "username", nullptr));
        label_2->setText(QCoreApplication::translate("AdDisp", "parola", nullptr));
        label_3->setText(QCoreApplication::translate("AdDisp", "email", nullptr));
        label_4->setText(QCoreApplication::translate("AdDisp", "Nume", nullptr));
        label_5->setText(QCoreApplication::translate("AdDisp", "Prenume", nullptr));
        label_6->setText(QCoreApplication::translate("AdDisp", "tipul dispecerului", nullptr));
        pushButton->setText(QCoreApplication::translate("AdDisp", "Adauga", nullptr));
        label_7->setText(QCoreApplication::translate("AdDisp", "telefon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdDisp: public Ui_AdDisp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDISP_H
