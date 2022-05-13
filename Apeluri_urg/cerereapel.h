#ifndef CEREREAPEL_H
#define CEREREAPEL_H

#include "icerere.h"
#include <QDateTime>

//am nevoie de tipul dispecerului si imi intoarce un string
class CerereApel : public ICerere
{
protected:
    QString catre;
public:
    CerereApel(QString user,QString dispecer,QDateTime i_apel, QDateTime s_apel);
    bool _cerere();
};

#endif // CEREREAPEL_H
