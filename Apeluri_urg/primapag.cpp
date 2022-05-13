#include "primapag.h"
#include "ui_primapag.h"
#include "apel.h"
#include "detaliiapel.h"
#include "icerere.h"
#include "cererelog.h"
#include "cerereinreg.h"
#include "cerereapel.h"
#include "cerereistoriccl.h"
#include "cerereistoricdisp.h"
#include "detalii_suplimentare.h"
#include "cerereistoricadm.h"
#include "addisp.h"

#include <QDateTime>
#include <QMessageBox>
#include <qpalette.h>

PrimaPag::PrimaPag(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PrimaPag)
{
    setWindowIcon(QIcon("./icon_window.png"));
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(0);
}

PrimaPag::~PrimaPag()
{
    delete ui;
}

void PrimaPag::afisare_er(QString mesaj)
{
    QMessageBox::critical(this, "EROARE", mesaj);
}


//autentificarea
void PrimaPag::on_autentificare_clicked()
{
    QString user=ui->username->text();
    QString pass=ui->parola->text();

    if (user.count() == 0 || pass.count() == 0)

    {
        afisare_er("Completati toate campurile!");
        ui->stackedWidget->setCurrentIndex(0);
        return;
    }

    //pentru a obtine date despre el dupa
    username=user;

    //generarea afisarilor in functie de utilizator
    CerereLog c(user,pass);
    QString tip=c._cerere();
    if (tip == "client")
    {
        ui->stackedWidget->setCurrentIndex(4);
        ui->us_pag_client->setText(username);

        //istoric client
        CerereIstoricCl ci(username);
        ci._cerere(ui);
    }
    else if (tip == "dispecer")
    {
        ui->stackedWidget->setCurrentIndex(5);
        ui->u_pag_dis->setText(username);

        //in asteptare lista
        CerereIstoricDisp di(username);
        di._cerere_ist_vechi(ui);

        //istoric lista
        di._cerere_istoric_apeluri(ui);

        //utilizatori lista
        CerereUtilz d_u = CerereUtilz();
        d_u.set_ui(ui);
        d_u.set_tip_user(tip);
        d_u._cerere();
        date_util = d_u;
    }
    else if (tip == "administrator")
    {
        ui->stackedWidget->setCurrentIndex(6);

        //dispeceri
        CerereDisp d_d = CerereDisp();
        d_d.set_ui(ui);
        d_d._cerere();
        date_disp = d_d;

        //utilizatori lista
        CerereUtilz d_u = CerereUtilz();
        d_u.set_ui(ui);
        d_u.set_tip_user(tip);
        d_u._cerere();
        date_util = d_u;

        //istoric apeluri
        CerereIstoricAdm is_adm = CerereIstoricAdm();
        is_adm.set_ui(ui);
        is_adm._cerere();
        is_admin = is_adm;

        //inregistrari
        CerereInreg is_inregis = CerereInreg();
        is_inregis._cerere_inregistrari(ui);
        is_inreg = is_inregis;

        //stergeri
        CerereStergeri stergeri = CerereStergeri();
        stergeri.set_ui(ui);
        stergeri._cerere();
        is_stergeri = stergeri;
    }
    else if (tip == "x")
    {
        afisare_er("Username sau parola gresita!");
        return;
    }
}


//buton
void PrimaPag::on_inregistrare_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//schimbarea parolei propriu zisa
void PrimaPag::on_sch_parola_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

//buton
void PrimaPag::on_sch_parola_2_clicked()
{
    QString email = ui->email_2->text();
    QString n_pass = ui->parola_4->text();

    if (email == "" || n_pass == "")
    {
        afisare_er("Completati toate campurile!");
        return;
    }

    //trimite cerere catre administrator
    int iterator=-1;
    for (int i = 0; i < is_inreg.email.count(); i++)
        if (is_inreg.email[i] == email)iterator = i;

    //eroare
    if (iterator == -1)
    {
        afisare_er("Email-ul nu exista!");
        return;
    }

    CerereInreg inreg(is_inreg.username[iterator], n_pass, is_inreg.nume[iterator], is_inreg.prenume[iterator], is_inreg.email[iterator], is_inreg.tel[iterator]);
    ui->stackedWidget->setCurrentIndex(1);
}

//buton
void PrimaPag::on_spre_autentificare_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


//inregistrarea propriu zisa
void PrimaPag::on_inregistrare_2_clicked()
{
    QString user=ui->username_3->text();
    QString parola=ui->parola_3->text();
    QString nume=ui->nume->text();
    QString prenume=ui->prenume->text();
    QString email=ui->email->text();
    QString tel=ui->telefon->text();
    
    //eroare daca nu completeaza un camp
    if (user=="" || parola == "" || nume == "" || prenume == "" || email == "" || tel == "")
    {
        afisare_er("Completati toate campurile!");
        return;
    }

    CerereInreg c(user,parola,nume,prenume,email,tel);
    if (c._cerere() == true) ui->stackedWidget->setCurrentIndex(1);
    else
    {
        afisare_er("Eroare de la server! Reporniti aplicatia!");
        ui->stackedWidget->setCurrentIndex(0);
        return;
    }
}


void PrimaPag::apel_universal(QString tip_dispecer)
{
    //transmiterea fisierului audio + datele utilizatorului catre server pt a intra in lista de asteptare
    //dispecerul este cunoscut
    QString username_dispecer="maria";
    QDateTime i_apel=QDateTime::currentDateTime();
    QTime sf = QTime::currentTime();
    apel *pag_apel=new apel();
    pag_apel->exec();
    QDateTime s_apel=QDateTime::currentDateTime();

    QString interval_apel=i_apel.toString()+" - " +s_apel.toString();

    CerereApel apel(username,username_dispecer,i_apel,s_apel);
    if(apel._cerere()==true)
    {
        //salvarea istoricului in tabel
        int nr_rand=ui->tbl_istoric_client->rowCount();
        ui->tbl_istoric_client->setRowCount(nr_rand+1);

        ui->tbl_istoric_client->setItem(nr_rand,0,new QTableWidgetItem(interval_apel));
        ui->tbl_istoric_client->setItem(nr_rand,1,new QTableWidgetItem(tip_dispecer));
        ui->tbl_istoric_client->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    else
    {
        afisare_er("Eroare de la server! Reporniti aplicatia!");
        ui->stackedWidget->setCurrentIndex(0);
        return;
    }
}


void PrimaPag::on_apel_112_clicked()
{
    this->apel_universal("universal");
}


void PrimaPag::on_apel_politie_clicked()
{
    this->apel_universal("politie");
}


void PrimaPag::on_apel_pompieri_clicked()
{
    this->apel_universal("politie");
}


void PrimaPag::on_apel_salvamont_clicked()
{
    this->apel_universal("salvamont");
}


void PrimaPag::on_apel_ambulanta_clicked()
{
    this->apel_universal("ambulanta");
}


void PrimaPag::on_apel_smurd_clicked()
{
    this->apel_universal("smurd");
}


void PrimaPag::on_apel_jandarmerie_clicked()
{
    this->apel_universal("jandamerie");
}


//informatii utilizatori PT DISPECER
void PrimaPag::on_but_inf_clicked()
{
    int iterator;

    //eroare daca nu selecteaza un utilizator
    int r = ui->list_utilizatori->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un utilizator!");
        return;
    }

    QString u=ui->list_utilizatori->currentItem()->text();
    //identific al catelea utilizator e din lista
    for(int i=0;i<date_util.lista_user.count();i++)
        if(date_util.lista_user[i]==u)iterator=i;

    QString n=date_util.lista_nume[iterator];
    QString pn=date_util.lista_prenume[iterator];
    QString e=date_util.lista_email[iterator];
    QString t=date_util.lista_tel[iterator];

    QString mesaj;
    mesaj.append("Nume: ");
    mesaj.append(n);
    mesaj.append("\n");
    mesaj.append("Prenume: ");
    mesaj.append(pn);
    mesaj.append("\n");
    mesaj.append("Email: ");
    mesaj.append(e);
    mesaj.append("\n");
    mesaj.append("Telefon: ");
    mesaj.append(t);

    QMessageBox::information(this,"Informatii despre utilizator",mesaj);
}

//sterge utiizatorul ca si dispecer
void PrimaPag::on_but_stergere_clicked()
{
    //eroare daca nu selecteaza un utilizator
    int r = ui->list_utilizatori->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un utilizator!");
        return;
    }

    QString user_selectat = ui->list_utilizatori->currentItem()->text();
    ui->list_utilizatori->item(ui->list_utilizatori->currentRow())->setForeground(Qt::red);

    bool rp=date_util._cerere_sterge_utl(user_selectat);
    if (rp == false)afisare_er("Cerere de stergere deja trimisa!");
}

//informatii despre dispeceri
void PrimaPag::on_b_inf_disp_clicked()
{
    int iterator;

    //eroare daca nu selecteaza un utilizator
    int r = ui->lista_dispeceri->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un dispecer!");
        return;
    }

    QString u=ui->lista_dispeceri->currentItem()->text();
    //identific al catelea dispecer e din lista
    for(int i=0;i<date_disp.lista_user.count();i++)
        if(date_disp.lista_user[i]==u)iterator=i;

    QString tip=date_disp.lista_tip[iterator];
    QString n=date_disp.lista_nume[iterator];
    QString pn=date_disp.lista_prenume[iterator];
    QString e=date_disp.lista_email[iterator];
    QString t=date_disp.lista_tel[iterator];

    QString mesaj;
    mesaj.append("Tipul dispecerului: ");
    mesaj.append(tip+"\n");
    mesaj.append("Nume: ");
    mesaj.append(n);
    mesaj.append("\n");
    mesaj.append("Prenume: ");
    mesaj.append(pn);
    mesaj.append("\n");
    mesaj.append("Email: ");
    mesaj.append(e);
    mesaj.append("\n");
    mesaj.append("Telefon: ");
    mesaj.append(t);

    QMessageBox::information(this,"Informatii despre dispecer",mesaj);
}


void PrimaPag::on_b_stergere_disp_clicked()
{
    int iterator;

    //eroare daca nu selecteaza un utilizator
    int r = ui->lista_dispeceri->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un dispecer!");
        return;
    }

    QString u=ui->lista_dispeceri->currentItem()->text();
    //trimitere la server 
    QString trimitere = "9$" + u + "$";
    //stergerea din lista
    ui->lista_dispeceri->takeItem(ui->lista_dispeceri->currentRow());

    for(int i=0;i<date_disp.lista_user.count();i++)
        if(date_disp.lista_user[i]==u)iterator=i;

    date_disp.lista_user.removeAt(iterator);
    date_disp.lista_email.removeAt(iterator);
    date_disp.lista_nume.removeAt(iterator);
    date_disp.lista_prenume.removeAt(iterator);
    date_disp.lista_tel.removeAt(iterator);
    date_disp.lista_tip.removeAt(iterator);
}


void PrimaPag::on_b_inf_apel_clicked()
{
    DetaliiApel det_apel;

    //eroare daca nu selecteaza
    int r = ui->lista_ist_apeluri_adm->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un apel!");
        return;
    }

    det_apel.set_afisaj(ui);
    QString string_selectat=ui->lista_ist_apeluri_adm->currentItem()->text();
    QStringList s=string_selectat.split(' ');
    //s[0]-user client, s[2]-user dispecer

    int a,b,c;
    int nr = date_util.lista_user.count();
    for(int i=0;i<nr;i++)
        if(s[0]==date_util.lista_user[i])a=i;

    nr = date_disp.lista_user.count();
    for(int i=0;i<nr;i++)
        if(s[2]==date_disp.lista_user[i])b=i;

    nr = is_admin.user_cl.count();
    for(int i=0;i<nr;i++)
        if(s[0]==is_admin.user_cl[i])c=i;

    det_apel.set_iteratori(a,b,c,is_admin, date_util,date_disp);

    det_apel.setModal(true);
    det_apel.exec();
}


void PrimaPag::on_b_sterg_apel_clicked()
{
    //eroare daca nu selecteaza
    int r = ui->lista_ist_apeluri_adm->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un apel!");
        return;
    }

    QString string_selectat = ui->lista_ist_apeluri_adm->currentItem()->text();
    if (is_admin._cerere_elim_apel(string_selectat) == false)
    {
        afisare_er("Eroare de la server!");
    }
}


void PrimaPag::on_b_sterg_istoric_clicked()
{
    is_admin._cerere_sterg_istoric();
    QMessageBox::information(this, "Stergere istoric", "Istoric golit!");
}


void PrimaPag::on_but_inf_2_clicked()
{
    int iterator;

    //eroare daca nu selecteaza
    int r = ui->list_utilizatori_2->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un utilizator!");
        return;
    }

    QString u = ui->list_utilizatori_2->currentItem()->text();
    //identific al catelea utilizator e din lista
    for (int i = 0; i < date_util.lista_user.count(); i++)
        if (date_util.lista_user[i] == u)iterator = i;

    QString n = date_util.lista_nume[iterator];
    QString pn = date_util.lista_prenume[iterator];
    QString e = date_util.lista_email[iterator];
    QString t = date_util.lista_tel[iterator];

    QString mesaj;
    mesaj.append("Nume: ");
    mesaj.append(n);
    mesaj.append("\n");
    mesaj.append("Prenume: ");
    mesaj.append(pn);
    mesaj.append("\n");
    mesaj.append("Email: ");
    mesaj.append(e);
    mesaj.append("\n");
    mesaj.append("Telefon: ");
    mesaj.append(t);

    QMessageBox::information(this, "Informatii despre utilizator", mesaj);
}


//sterge utilizatorii ca si administrator
void PrimaPag::on_but_stergere_2_clicked()
{
    //eroare daca nu selecteaza
    int r = ui->list_utilizatori_2->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un utilizator!");
        return;
    }

    QString user_selectat = ui->list_utilizatori_2->currentItem()->text();
    
    date_util._cerere_sterge_utl(user_selectat);
}


void PrimaPag::on_b_add_disp_clicked()
{
    AdDisp dispecer_nou;
    dispecer_nou.setModal(true);
    dispecer_nou.exec();

    QStringList nou=dispecer_nou.return_informatii();

    date_disp.lista_user.append(nou[0]);
    date_disp.lista_email.append(nou[1]);
    date_disp.lista_nume.append(nou[2]);
    date_disp.lista_prenume.append(nou[3]);
    date_disp.lista_tip.append(nou[4]);
    date_disp.lista_tel.append(nou[5]);

    ui->lista_dispeceri->addItem(nou[0]);
}


void PrimaPag::on_inf_inrg_clicked()
{
    int iterator;

    //eroare daca nu selecteaza
    int r = ui->lista_cereri_inrg->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza o inregistrare!");
        return;
    }

    QString username = ui->lista_cereri_inrg->currentItem()->text();
    for (int i = 0; i < is_inreg.username.count(); i++)
        if (is_inreg.username[i] == username)iterator = i;

    QString mesaj;
    mesaj.append("Nume: " + is_inreg.nume[iterator]+"\n");
    mesaj.append("Prenume: " + is_inreg.prenume[iterator] + "\n");
    mesaj.append("Email: " + is_inreg.email[iterator] + "\n");
    mesaj.append("Telefon: " + is_inreg.tel[iterator]);

    QMessageBox::information(this, "Informatii inregistrare", mesaj);
}


void PrimaPag::on_aprob_inrg_clicked()
{
    int iterator;

    //eroare daca nu selecteaza
    int r = ui->lista_cereri_inrg->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza o inregistrare!");
        return;
    }

    QString username = ui->lista_cereri_inrg->currentItem()->text();
    for (int i = 0; i < is_inreg.username.count(); i++)
        if (is_inreg.username[i] == username)iterator = i;

    date_util.lista_user << is_inreg.username[iterator];
    date_util.lista_email << is_inreg.email[iterator];
    date_util.lista_nume << is_inreg.nume[iterator];
    date_util.lista_prenume << is_inreg.prenume[iterator];
    date_util.lista_tel << is_inreg.tel[iterator];

    ui->lista_cereri_inrg->takeItem(ui->lista_cereri_inrg->currentRow());

    ui->list_utilizatori_2->addItem(username);

    is_inreg._cerere_aprobare_inreg(iterator);

    QMessageBox::information(this, "Aprobare", "Aprobarea inregistrarii s-a realizat cu succes!");
}


void PrimaPag::on_resping_inreg_clicked()
{
    int iterator;

    //eroare daca nu selecteaza
    int r = ui->lista_cereri_inrg->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza o inregistrare!");
        return;
    }

    QString username = ui->lista_cereri_inrg->currentItem()->text();
    for (int i = 0; i < is_inreg.username.count(); i++)
        if (is_inreg.username[i] == username)iterator = i;

    ui->lista_cereri_inrg->takeItem(ui->lista_cereri_inrg->currentRow());

    is_inreg._cerere_respingere_inreg(iterator);

    QMessageBox::critical(this, "Respingere", "Stergerea inregistrarii s-a realizat cu succes!");
}


void PrimaPag::on_inf_strg_clicked()
{
    int r = ui->lista_cereri_st->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza o cerere de stergere!");
        return;
    }

    QString linie = ui->lista_cereri_st->currentItem()->text();
    int iterator_cl;
    int iterator_disp;

    QStringList us_disp = linie.split(" - ");
    //0-user client, 1-user disp

    for (int i = 0; i < date_util.lista_user.count(); i++)
        if (date_util.lista_user[i] == us_disp[0])iterator_cl = i;
    for (int i = 0; i < date_disp.lista_user.count(); i++)
        if (date_disp.lista_user[i] == us_disp[1])iterator_disp = i;

    QString mesaj;
    mesaj.append("UTILIZATOR\n");
    mesaj.append("Nume Prenume: " + date_util.lista_nume[iterator_cl] +" " + date_util.lista_prenume[iterator_cl] + "\n");
    mesaj.append("email: " + date_util.lista_email[iterator_cl] + " telefon: " + date_util.lista_tel[iterator_cl] + "\n\n");

    mesaj.append("DISPECER\n");
    mesaj.append("Nume Prenume: " + date_disp.lista_nume[iterator_disp] +" " + date_disp.lista_prenume[iterator_disp] + "\n");
    mesaj.append("email: " + date_disp.lista_email[iterator_disp] + " telefon: " + date_disp.lista_tel[iterator_disp]);

    QMessageBox::information(this, "Informatii utilizator si dispecer", mesaj);
}


void PrimaPag::on_aprob_strg_clicked()
{
    //eroare daca nu selecteaza
    int r = ui->lista_cereri_st->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza o cerere de stergere!");
        return;
    }
 
    QString user_cl_sters=is_stergeri._cerere_aprob_stergere();

    int iterator;
    for (int i = 0; i < date_util.lista_user.count(); i++)
        if (date_util.lista_user[i] == user_cl_sters)iterator = i;
    date_util.lista_user.removeAt(iterator);
    date_util.lista_nume.removeAt(iterator);
    date_util.lista_prenume.removeAt(iterator);
    date_util.lista_email.removeAt(iterator);
    date_util.lista_tel.removeAt(iterator);

    ui->lista_cereri_st->takeItem(r);
    ui->list_utilizatori_2->takeItem(r);
}


void PrimaPag::on_resping_strg_clicked()
{
    //eroare daca nu selecteaza
    int r = ui->lista_cereri_st->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza o cerere de stergere!");
        return;
    }

    is_stergeri._cerere_resping_stergere();
    ui->lista_cereri_st->takeItem(r);
}


//descriere adaugata de dispecer
void PrimaPag::on_add_descriere_clicked()
{
    //eroare daca nu selecteaza
    int r = ui->lista_in_astp->currentRow();
    if (r == -1)
    {
        afisare_er("Selecteaza un apel in asteptare!");
        return;
    }

    detalii_suplimentare pag_detalii;
    pag_detalii.set(username,ui);
    pag_detalii.setModal(true);
    pag_detalii.exec();
}


void PrimaPag::on_delog_cl_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void PrimaPag::on_delog_disp_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void PrimaPag::on_delog_adm_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
