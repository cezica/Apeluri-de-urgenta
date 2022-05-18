#include "cereredisp.h"
#include "Conexiune.h"

CerereDisp::CerereDisp()
{

}

void CerereDisp::set_ui(Ui::PrimaPag *afisaj)
{
    ui=afisaj;
}

std::string CerereDisp::_cerere()
{
    //trimit la server 16$
    QString trimite = "16$";
    Conexiune::getinstance()->trimite_cerere(trimite.toStdString());
    //primesc user_disp$tipul dispecerului$nume$prenume$email$tel*...
    QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());;
    if (raspuns == "x")
        return raspuns.toStdString();

    QStringList lista_d=raspuns.split('*');

    for(int i=0;i<lista_d.count()-1;i++)
    {
        QStringList lista_inf_disp=lista_d[i].split('$');
        //0-user, 1-tip, 2-nume, 3-prenume, 4-email, 5-tel

        lista_user<<lista_inf_disp[0];
        lista_tip<<lista_inf_disp[1];
        lista_nume<<lista_inf_disp[2];
        lista_prenume<<lista_inf_disp[3];
        lista_email<<lista_inf_disp[4];
        lista_tel<<lista_inf_disp[5];

        ui->lista_dispeceri->addItem(lista_inf_disp[0]);
    }
    return "v";
}
