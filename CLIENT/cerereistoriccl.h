#ifndef CEREREISTORICCL_H
#define CEREREISTORICCL_H

#include "primapag.h"
#include "ui_primapag.h"

class CerereIstoricCl : public ICerere
{
private:
    QString username;
    Ui::PrimaPag* ui;
public:
    CerereIstoricCl(QString username, Ui::PrimaPag* afisaj);
    std::string _cerere();
};

#endif // CEREREISTORICCL_H
