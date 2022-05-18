#ifndef CEREREISTORICADM_H
#define CEREREISTORICADM_H

#include "ui_primapag.h"
#include "icerere.h"


class CerereIstoricAdm: public ICerere
{
private:
    Ui::PrimaPag *ui;

public:
    CerereIstoricAdm();
    std::string _cerere();
    bool _cerere_elim_apel(int nr);
    void _cerere_sterg_istoric();
    void set_ui(Ui::PrimaPag *afisaj);

    QStringList user_cl;
    QStringList user_dsp;
    QStringList nume_fis;
};

#endif // CEREREISTORICADM_H
