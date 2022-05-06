#include "cererelog.h"

CerereLog::CerereLog(QString u, QString p)
{
    QString zero="0";
    QString bara="|";

    catre.reserve(zero.length()+bara.length()+u.length()+bara.length()+p.length()+bara.length());
    catre.append(zero);
    catre.append(bara);
    catre.append(u);
    catre.append(bara);
    catre.append(p);
    catre.append(bara);
}

QString CerereLog::_cerere()
{
    //trimitere catre server un string si primesc ce tip de utilizator este
    //trimitere THIS.CATRE la server si primesc raspuns
    QString raspuns="administrator";
    //client,dispecer,utilizator, x
    //x-username sau parola gresita

    return raspuns;
}
