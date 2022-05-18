#include "cererelog.h"
#include <iostream>
using namespace std;

CerereLog::CerereLog(QString u, QString p)
{
    QString zero="0";
    QString bara="$";

    catre.reserve(zero.length()+bara.length()+u.length()+bara.length()+p.length()+bara.length());
    catre.append(zero);
    catre.append(bara);
    catre.append(u);
    catre.append(bara);
    catre.append(p);
    catre.append(bara);
}

std::string CerereLog::_cerere()
{
    //trimitere catre server un string si primesc ce tip de utilizator este
    Conexiune::getinstance()->trimite_cerere(this->catre.toStdString());
    QString raspuns= QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());

    return raspuns.toStdString();
}
