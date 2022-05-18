#include "cerereutilz.h"
#include "Conexiune.h"
#include <qmessagebox.h>

CerereUtilz::CerereUtilz()
{

}

void CerereUtilz::set_ui(Ui::PrimaPag *afisaj)
{
    ui=afisaj;
}

void CerereUtilz::set_tip_user(QString tip)
{
    tip_user=tip;
}

std::string CerereUtilz::_cerere()
{
    //trimit la server 7$
    QString trimite = "7$";
    Conexiune::getinstance()->trimite_cerere(trimite.toStdString());
    //primesc username$nume$prenume$email$tel*...
    QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());
    if (raspuns == "x")return "x";

    QStringList lista_u=raspuns.split('*');

    for(int i=0;i<lista_u.count()-1;i++)
    {
        QStringList date_u=lista_u[i].split('$');
        //0-usern, 1-nume, 2-prenume, 3-email, 4-tel

        //voi retine nume,prenume,email,tel in liste pentru a afisa apoi
        lista_user<<date_u[0];
        lista_nume<<date_u[1];
        lista_prenume<<date_u[2];
        lista_email<<date_u[3];
        lista_tel<<date_u[4];

        //pentru a folosi aceeasi clasa pentru a afisa utilizatorii in functie de dispecer sau administrator
        
        if(tip_user=="dispecer") ui->list_utilizatori->addItem(date_u[0]);
            else ui->list_utilizatori_2->addItem(date_u[0]);
    }
    return "v";
}

bool CerereUtilz::_cerere_sterge_utl(QString user_stg,QString user_disp)
{
    //trimitere la server
    QString trimitere = "17$" + user_stg + "$"+user_disp+"$";
    Conexiune::getinstance()->trimite_cerere(trimitere.toStdString());
    QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());

    if (raspuns == "x") return false;

    int iterator;
    for (int i = 0; i < lista_user.count(); i++)
        if (user_stg == lista_user[i])iterator = i;

    lista_user.removeAt(iterator);
    lista_nume.removeAt(iterator);
    lista_prenume.removeAt(iterator);
    lista_email.removeAt(iterator);
    lista_tel.removeAt(iterator);

    ui->list_utilizatori_2->takeItem(ui->list_utilizatori_2->currentRow());

    return true;
}
