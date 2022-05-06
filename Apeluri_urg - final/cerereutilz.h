#ifndef CEREREUTILZ_H
#define CEREREUTILZ_H

#include "ui_primapag.h"

class CerereUtilz
{
private:
    Ui::PrimaPag *ui;
    //daca cere un dispecer sau administrator
    QString tip_user;
public:
    QStringList lista_user;
    QStringList lista_nume;
    QStringList lista_prenume;
    QStringList lista_email;
    QStringList lista_tel;
    CerereUtilz();
    void set_ui(Ui::PrimaPag *afisaj);
    void set_tip_user(QString tip);
    void _cerere_sterge_utl(QString user_stg);

    void _cerere();

};

#endif // CEREREUTILZ_H
