#include "cerereistoricadm.h"
#include <qmessagebox.h>

CerereIstoricAdm::CerereIstoricAdm()
{

}

void CerereIstoricAdm::set_ui(Ui::PrimaPag *afisaj)
{
    ui=afisaj;
}

bool CerereIstoricAdm::_cerere_elim_apel(QString linie)
{
    QStringList aux = linie.split(" - ");

    //trimitere catre server 10$user_cl$user_dispecer$

    //primesc daca e ok sau nu
    QString raspuns = "v";
    if (raspuns == "x")return false;

    //elimin 
    //eroare daca nu selecteaza

    int nr = ui->lista_ist_apeluri_adm->currentRow();

    ui->lista_ist_apeluri_adm->takeItem(nr);
    return true;
}

void CerereIstoricAdm::_cerere_sterg_istoric()
{
    int nr = ui->lista_ist_apeluri_adm->count();
    for (int i = nr-1; i >-1; i--)
    {
        ui->lista_ist_apeluri_adm->takeItem(i);
    }
}

void CerereIstoricAdm::_cerere()
{
    //trimitere catre server 8$

    //raspuns user_client$user_dispecer$NUMELE fis audio*...
    QString raspuns="cez.el$d_grigore$f1.wav*cez.el$oana.dima$f2*";

    QStringList lista_apeluri=raspuns.split('*');

    for(int i=0;i<lista_apeluri.count()-1;i++)
    {
        QStringList date=lista_apeluri[i].split('$');
        //0-user utilizator, 1-user dispecer, 2-fis. audio

        user_cl.append(date[0]);
        user_dsp.append(date[1]);
        nume_fis.append(date[2]);

        ui->lista_ist_apeluri_adm->addItem(date[0]+" - "+date[1]);
    }

}


