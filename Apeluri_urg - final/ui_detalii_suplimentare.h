/********************************************************************************
** Form generated from reading UI file 'detalii_suplimentare.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETALII_SUPLIMENTARE_H
#define UI_DETALII_SUPLIMENTARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_detalii_suplimentare
{
public:
    QLineEdit *line_detalii;
    QPushButton *b_trimitere_det;

    void setupUi(QDialog *detalii_suplimentare)
    {
        if (detalii_suplimentare->objectName().isEmpty())
            detalii_suplimentare->setObjectName(QString::fromUtf8("detalii_suplimentare"));
        detalii_suplimentare->resize(400, 300);
        line_detalii = new QLineEdit(detalii_suplimentare);
        line_detalii->setObjectName(QString::fromUtf8("line_detalii"));
        line_detalii->setGeometry(QRect(50, 40, 291, 201));
        b_trimitere_det = new QPushButton(detalii_suplimentare);
        b_trimitere_det->setObjectName(QString::fromUtf8("b_trimitere_det"));
        b_trimitere_det->setGeometry(QRect(280, 250, 93, 29));

        retranslateUi(detalii_suplimentare);

        QMetaObject::connectSlotsByName(detalii_suplimentare);
    } // setupUi

    void retranslateUi(QDialog *detalii_suplimentare)
    {
        detalii_suplimentare->setWindowTitle(QCoreApplication::translate("detalii_suplimentare", "Dialog", nullptr));
        b_trimitere_det->setText(QCoreApplication::translate("detalii_suplimentare", "Trimite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class detalii_suplimentare: public Ui_detalii_suplimentare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETALII_SUPLIMENTARE_H
