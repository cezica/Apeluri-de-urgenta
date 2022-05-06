#ifndef CEREREINREG_H
#define CEREREINREG_H

#include "icerere.h"
#include "ui_primapag.h"

class CerereInreg : public ICerere
{
protected:
    QString catre;
    Ui::PrimaPag* ui;
public:
    QStringList username;
    QStringList email;
    QStringList nume;
    QStringList prenume;
    QStringList tel;
public:
    CerereInreg(QString user,QString parola,QString nume,QString prenume,QString email,QString telefon);
    CerereInreg();
    bool _cerere();
    //cerere pentru lista de inregistrari a administratorului
    void _cerere_inregistrari(Ui::PrimaPag *afisaj);
    void _cerere_aprobare_inreg(int iterator);
    void _cerere_respingere_inreg(int iterator);
};

#endif // CEREREINREG_H
