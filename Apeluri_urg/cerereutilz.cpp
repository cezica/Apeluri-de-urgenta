#include "cerereutilz.h"
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

void CerereUtilz::_cerere()
{
    //trimit la server 7$

    //primesc username$nume$prenume$email$tel*...

    QString raspuns="cez.el$Luncanu$Cezica$cez.al@gmail.com$01238*t.el$Tepes$Elena$tep.el@yahoo.ro$07851234*";

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
}

bool CerereUtilz::_cerere_sterge_utl(QString user_stg)
{
    //trimitere la server
    QString trimitere = "14$" + user_stg + "$";
    //verificare daca deja exista la server
    QString raspuns = "v";
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
