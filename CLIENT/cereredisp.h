#ifndef CEREREDISP_H
#define CEREREDISP_H

#include "ui_primapag.h"
#include "icerere.h"

class CerereDisp : public ICerere
{
private:
    Ui::PrimaPag *ui;
public:
    QStringList lista_user;
    QStringList lista_nume;
    QStringList lista_prenume;
    QStringList lista_tip;
    QStringList lista_email;
    QStringList lista_tel;
    CerereDisp();
    void set_ui(Ui::PrimaPag *afisaj);
    std::string _cerere();
};

#endif // CEREREDISP_H
