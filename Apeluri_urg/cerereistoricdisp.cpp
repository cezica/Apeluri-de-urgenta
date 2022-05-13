#include "cerereistoricdisp.h"

CerereIstoricDisp::CerereIstoricDisp(QString u)
{
    user_dispecer=u;
}

//in asteptare
void CerereIstoricDisp::_cerere_ist_vechi(Ui::PrimaPag *ui)
{
    //trimite 4$THIS.USER_DISP$ ca sa verifice istoricul IN ASTEPTARE

    //imi intoarce un string username|data s_apel*username|data s_apel..(dupa fiecare apel *)
    QString raspuns="viorel.m$Sat 30 May 19:29:02*o.paul$Fri 29 May 10:10:21*";

    QStringList lista_apeluri=raspuns.split('*');


    for(int i=0;i<lista_apeluri.count()-1;i++)
    {
        QStringList lista_date_apel=lista_apeluri[i].split('$');
        //0-username, 1-data s_apel
        ui->lista_in_astp->addItem(lista_date_apel[0]+" - "+lista_date_apel[1]);
    }

    //pentru a prelua detaliile adaugate de dispecer in tabel
}

bool CerereIstoricDisp::_cerere_elim_apel(Ui::PrimaPag *ui,QString detalii)
{
    //trimitere catre server 5$username_dispecer$nr_rand din tabelul de asteptare$string detalii$
    QString trimitere;
    QString cinci="5";
    QString bara="$";
    trimitere.reserve(cinci.length()+(4*bara.length())+user_dispecer.length()+1+detalii.length());
    trimitere.append(cinci);
    trimitere.append(bara);
    trimitere.append(user_dispecer);
    trimitere.append(bara);
    //DACA AJUTA
    trimitere.append(QString::number(ui->lista_in_astp->currentRow()));
    trimitere.append(bara);
    trimitere.append(detalii);
    trimitere.append(bara);

    //intoarce daca s-a efectuat cu succes v/x
    QString raspuns="v";
    //EROARE DACA E x
    if (raspuns == "x")return false;

    QString line=ui->lista_in_astp->currentItem()->text();
    QStringList sp_line=line.split(" - ");
    //0-user client, 1-user dispecer

    ui->lista_in_astp->takeItem(ui->lista_in_astp->currentRow());
    int new_row = ui->tbl_istoric_dispecer->rowCount();
    ui->tbl_istoric_dispecer->insertRow(new_row);
    ui->tbl_istoric_dispecer->setItem(new_row,0,new QTableWidgetItem(sp_line[0]));
    ui->tbl_istoric_dispecer->setItem(new_row,1,new QTableWidgetItem(sp_line[1]));
    ui->tbl_istoric_dispecer->setItem(new_row,2,new QTableWidgetItem(detalii));
    ui->tbl_istoric_dispecer->update();
}

//istoricul apelurilor complete
void CerereIstoricDisp::_cerere_istoric_apeluri(Ui::PrimaPag *ui)
{
    //trimit 6$user_dispecer$

    //primesc user_cl$d+t s_apel$detalii*...
    QString raspuns="geo_pi$Sat 20 May 09:29:02$apel cu detalii adaugate*grigore$Sat 01 June 09:09:21$detalii puse*";

    QStringList lista_apeluri=raspuns.split('*');
    //0-user, 1-d+t, 2-detalii

    ui->tbl_istoric_dispecer->setRowCount(lista_apeluri.count()-1);
    int nr_rand=0;
    for(int i=0;i<lista_apeluri.count()-1;i++)
    {
        QStringList lista_date_apel=lista_apeluri[i].split('$');
        ui->tbl_istoric_dispecer->setItem(nr_rand,0,new QTableWidgetItem(lista_date_apel[0]));
        ui->tbl_istoric_dispecer->setItem(nr_rand,1,new QTableWidgetItem(lista_date_apel[1]));
        ui->tbl_istoric_dispecer->setItem(nr_rand,2,new QTableWidgetItem(lista_date_apel[2]));

        nr_rand++;
    }
}
