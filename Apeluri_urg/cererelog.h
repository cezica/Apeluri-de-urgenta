#ifndef CERERELOG_H
#define CERERELOG_H
#include <QString>
#include "Conexiune.h"

//fara icerere pentru ca am nevoie de un string intors
class CerereLog
{
public:
    CerereLog(QString u, QString p);
    QString _cerere();

protected:
    QString catre;
};

#endif // CERERELOG_H
