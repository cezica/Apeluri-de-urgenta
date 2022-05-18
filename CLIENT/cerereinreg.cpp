#include "cerereinreg.h"
#include "Conexiune.h"
#include <QMessageBox>

CerereInreg::CerereInreg(QString user,QString parola,QString nume,QString prenume,QString email,QString telefon)
{
    QString unu="1";
    QString bara="$";

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

std::string CerereInreg::_cerere()
{
    //trimitere THIS.CATRE la server
    Conexiune::getinstance()->trimite_cerere(catre.toStdString());
    QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());
    return raspuns.toStdString();
}

void CerereInreg::_cerere_inregistrari(Ui::PrimaPag *afisaj)
{
    ui = afisaj;
    //trimitere catre server 
    catre = "11$";
    Conexiune::getinstance()->trimite_cerere(catre.toStdString());
    //primesc user$email$nume$prenume$tel*...
    QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());
    //QString raspuns = "jamila.c$j.covrig@gmail.ro$Covrig$Jamila$0782345123*gh.pop$gh.pop@yahoo.com$Pop$Ghita$0723456789*";

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

bool CerereInreg::_cerere_aprobare_inreg(int iterator, int nr_rand)
{
    //protocol$nr_rand

    //IMI DA 0 DIN LISTA, DAR IN TABEL SQL E 1
    catre = "12$" + QString::number(nr_rand+1) + '$';
    Conexiune::getinstance()->trimite_cerere(catre.toStdString());
    QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());
    if (raspuns == "x")
        return false;
    username.removeAt(iterator);
    email.removeAt(iterator);
    nume.removeAt(iterator);
    prenume.removeAt(iterator);
    tel.removeAt(iterator);
    return true;
}

bool CerereInreg::_cerere_respingere_inreg(int iterator,int nr_rand)
{
    catre = "13$" + QString::number(nr_rand+1) + '$';
    Conexiune::getinstance()->trimite_cerere(catre.toStdString());
    QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());
    if (raspuns == "x")
        return false;
    username.removeAt(iterator);
    email.removeAt(iterator);
    nume.removeAt(iterator);
    prenume.removeAt(iterator);
    tel.removeAt(iterator);
    return true;
}
