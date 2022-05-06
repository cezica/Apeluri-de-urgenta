#include "cerereinreg.h"

CerereInreg::CerereInreg(QString user,QString parola,QString nume,QString prenume,QString email,QString telefon)
{
    QString unu="1";
    QString bara="|";

    catre.reserve(unu.length()+bara.length()+user.length()+bara.length()+parola.length()+
        bara.length()+nume.length()+bara.length()+prenume.length()+bara.length()+email.length()+
        bara.length()+telefon.length()+bara.length());
    catre.append(unu);
    catre.append(bara);
    catre.append(user);
    catre.append(bara);
    catre.append(parola);
    catre.append(bara);
    catre.append(nume);
    catre.append(bara);
    catre.append(prenume);
    catre.append(bara);
    catre.append(email);
    catre.append(bara);
    catre.append(telefon);
    catre.append(bara);
}

CerereInreg::CerereInreg()
{
}

bool CerereInreg::_cerere()
{
    //trimitere THIS.CATRE la server
    QString trimitere = catre;
    // primesc v sau x
    QString raspuns="v";
    if(raspuns=="v") return true;
    return false;
}

void CerereInreg::_cerere_inregistrari(Ui::PrimaPag *afisaj)
{
    ui = afisaj;
    //trimitere catre server 
    QString trimite = "11$";
    //primesc user$email$nume$prenume$tel*...
    QString raspuns = "jamila.c$j.covrig@gmail.ro$Covrig$Jamila$0782345123*gh.pop$gh.pop@yahoo.com$Pop$Ghita$0723456789*";

    QStringList useri = raspuns.split('*');

    for (int i = 0; i < useri.count()-1; i++)
    {
        QStringList date_user = useri[i].split('$');
        //0-usern, 1-email, 2-nume, 3-prenume, 4-tel
        username << date_user[0];
        email << date_user[1];
        nume << date_user[2];
        prenume << date_user[3];
        tel << date_user[4];

        ui->lista_cereri_inrg->addItem(date_user[0]);
    }
}

void CerereInreg::_cerere_aprobare_inreg(int iterator)
{
    QString trimitere = "12$" + this->username[iterator]+"$";
    username.removeAt(iterator);
    email.removeAt(iterator);
    nume.removeAt(iterator);
    prenume.removeAt(iterator);
    tel.removeAt(iterator);
}

void CerereInreg::_cerere_respingere_inreg(int iterator)
{
    QString trimite = "13$" + username[iterator] + "$";
    username.removeAt(iterator);
    email.removeAt(iterator);
    nume.removeAt(iterator);
    prenume.removeAt(iterator);
    tel.removeAt(iterator);
}
