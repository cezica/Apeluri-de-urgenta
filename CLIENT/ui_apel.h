/********************************************************************************
** Form generated from reading UI file 'apel.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APEL_H
#define UI_APEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_apel
{
public:
    QPushButton *inchidere_apel;
    QLabel *l_durata_apel;

    void setupUi(QDialog *apel)
    {
        if (apel->objectName().isEmpty())
            apel->setObjectName(QString::fromUtf8("apel"));
        apel->resize(320, 240);
        inchidere_apel = new QPushButton(apel);
        inchidere_apel->setObjectName(QString::fromUtf8("inchidere_apel"));
        inchidere_apel->setGeometry(QRect(110, 170, 101, 41));
        inchidere_apel->setStyleSheet(QString::fromUtf8("background: rgb(255, 0, 0)"));
        l_durata_apel = new QLabel(apel);
        l_durata_apel->setObjectName(QString::fromUtf8("l_durata_apel"));
        l_durata_apel->setGeometry(QRect(70, 60, 181, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        l_durata_apel->setFont(font);

        retranslateUi(apel);

        QMetaObject::connectSlotsByName(apel);
    } // setupUi

    void retranslateUi(QDialog *apel)
    {
        apel->setWindowTitle(QCoreApplication::translate("apel", "Dialog", nullptr));
        inchidere_apel->setText(QCoreApplication::translate("apel", "Inchide", nullptr));
        l_durata_apel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class apel: public Ui_apel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APEL_H
