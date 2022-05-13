#include "cerereapel.h"

CerereApel::CerereApel(QString user,QString dispecer,QDateTime i_apel, QDateTime s_apel)
{
    QString doi="2";
    QString bara="|";
    QString nume_fis_audio="0011298";

    catre.reserve(doi.length()+bara.length()+user.length()+bara.length()+dispecer.length()+bara.length()+
                  i_apel.toString().length()+bara.length()+s_apel.toString().length()+bara.length()
                  +nume_fis_audio.length());
    catre.append(doi);
    catre.append(bara);
    catre.append(user);
    catre.append(bara);
    catre.append(dispecer);
    catre.append(bara);
    catre.append(i_apel.toString());
    catre.append(bara);
    catre.append(s_apel.toString());
    catre.append(bara);
    catre.append(nume_fis_audio);
    catre.append(bara);
}

bool CerereApel::_cerere()
{
    //trimitere catre server THIS.CATRE
    QString raspuns="v";

    if(raspuns=="v")
        return true;
    return false;
}
