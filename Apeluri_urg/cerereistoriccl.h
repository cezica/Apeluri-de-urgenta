#ifndef CEREREISTORICCL_H
#define CEREREISTORICCL_H

#include "primapag.h"
#include "ui_primapag.h"

class CerereIstoricCl
{
private:
    QString username;
public:
    CerereIstoricCl(QString username);
    void _cerere(Ui::PrimaPag *afisaj);
};

#endif // CEREREISTORICCL_H
