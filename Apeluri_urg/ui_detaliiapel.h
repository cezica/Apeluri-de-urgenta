/********************************************************************************
** Form generated from reading UI file 'detaliiapel.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETALIIAPEL_H
#define UI_DETALIIAPEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DetaliiApel
{
public:
    QPushButton *b_audio;
    QLabel *inf_client;
    QLabel *inf_dispecer;
    QFrame *line;
    QLabel *label;
    QFrame *line_2;
    QLabel *label_2;

    void setupUi(QDialog *DetaliiApel)
    {
        if (DetaliiApel->objectName().isEmpty())
            DetaliiApel->setObjectName(QString::fromUtf8("DetaliiApel"));
        DetaliiApel->resize(580, 463);
        b_audio = new QPushButton(DetaliiApel);
        b_audio->setObjectName(QString::fromUtf8("b_audio"));
        b_audio->setGeometry(QRect(260, 430, 93, 29));
        inf_client = new QLabel(DetaliiApel);
        inf_client->setObjectName(QString::fromUtf8("inf_client"));
        inf_client->setGeometry(QRect(30, 70, 221, 311));
        inf_dispecer = new QLabel(DetaliiApel);
        inf_dispecer->setObjectName(QString::fromUtf8("inf_dispecer"));
        inf_dispecer->setGeometry(QRect(330, 70, 221, 311));
        line = new QFrame(DetaliiApel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 50, 231, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(DetaliiApel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 30, 63, 20));
        line_2 = new QFrame(DetaliiApel);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(330, 50, 231, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(DetaliiApel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 30, 71, 20));

        retranslateUi(DetaliiApel);

        QMetaObject::connectSlotsByName(DetaliiApel);
    } // setupUi

    void retranslateUi(QDialog *DetaliiApel)
    {
        DetaliiApel->setWindowTitle(QCoreApplication::translate("DetaliiApel", "Dialog", nullptr));
        b_audio->setText(QCoreApplication::translate("DetaliiApel", "Audio", nullptr));
        inf_client->setText(QString());
        inf_dispecer->setText(QString());
        label->setText(QCoreApplication::translate("DetaliiApel", "Client", nullptr));
        label_2->setText(QCoreApplication::translate("DetaliiApel", "Dispecer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetaliiApel: public Ui_DetaliiApel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETALIIAPEL_H
