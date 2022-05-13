#pragma once
#include "icerere.h"
#include <qstringlist.h>
#include "ui_primapag.h"

class CerereStergeri :
    public ICerere
{
private:
    Ui::PrimaPag* ui;
public:
    CerereStergeri();

    QStringList user_cl;
    QStringList user_disp;
    void set_ui(Ui::PrimaPag* afisaj);

    bool _cerere();
    QString _cerere_aprob_stergere();
    void _cerere_resping_stergere();
};

