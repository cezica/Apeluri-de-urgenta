#ifndef CEREREISTORICADM_H
#define CEREREISTORICADM_H

#include "ui_primapag.h"


class CerereIstoricAdm
{
private:
    Ui::PrimaPag *ui;

public:
    CerereIstoricAdm();
    void _cerere();
    bool _cerere_elim_apel(QString linie);
    void _cerere_sterg_istoric();
    void set_ui(Ui::PrimaPag *afisaj);

    QStringList user_cl;
    QStringList user_dsp;
    QStringList nume_fis;
};

#endif // CEREREISTORICADM_H
