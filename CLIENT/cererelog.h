#ifndef CERERELOG_H
#define CERERELOG_H
#include <QString>
#include "Conexiune.h"
#include "icerere.h"

//fara icerere pentru ca am nevoie de un string intors
class CerereLog: public ICerere
{
public:
    CerereLog(QString u, QString p);
    std::string _cerere();

protected:
    QString catre;
};

#endif // CERERELOG_H
