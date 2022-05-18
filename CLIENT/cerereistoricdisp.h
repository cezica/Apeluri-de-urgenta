#ifndef CEREREISTORICDISP_H
#define CEREREISTORICDISP_H

#include "primapag.h"
#include "ui_primapag.h"

class CerereIstoricDisp:public ICerere
{
private:
    QString user_dispecer;
public:
    CerereIstoricDisp(QString u);
    std::string _cerere();
    //ist in asteptare vechi
    void _cerere_ist_vechi(Ui::PrimaPag *afisaj);
    //eliminare apel dupa adaugare
    bool _cerere_elim_apel(Ui::PrimaPag *afisaj,QString detalii);
    //istoric apeluri complete
    void _cerere_istoric_apeluri(Ui::PrimaPag *afisaj);
    //cerere stergere cont

};

#endif // CEREREISTORICDISP_H
