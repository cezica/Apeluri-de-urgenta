#include "cerereistoriccl.h"

CerereIstoricCl::CerereIstoricCl(QString use)
{
    username=use;
}

void CerereIstoricCl::_cerere(Ui::PrimaPag *ui)
{
    //trimitere 3|THIS.USERNAME| catre server sa verifice

    //imi intoarce stringul data i_apel|data s_apel|tip_apel*data i_apel|data s_apel...(pentru fiecare apel urmeaza *)
    QString raspuns="19:23:12|19:35:15|politie*12:10:11|12:20:44|jandarmerie*10:09:34|10:10:59|universal*";

    QStringList lista_apeluri=raspuns.split('*');
    for(int i=0;i<lista_apeluri.count()-1;i++)
    {
        QStringList lista_date_apel=lista_apeluri[i].split('|');
        //0-data inceput, 1-data sf, 2-tip apel
        int nr_rand=ui->tbl_istoric_client->rowCount();
        ui->tbl_istoric_client->setRowCount(nr_rand+1);

        ui->tbl_istoric_client->setItem(nr_rand,0,new QTableWidgetItem(lista_date_apel[0]+" - "+lista_date_apel[1]));
        ui->tbl_istoric_client->setItem(nr_rand,1,new QTableWidgetItem(lista_date_apel[2]));
        ui->tbl_istoric_client->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}
