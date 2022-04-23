#include "primapag.h"
#include "ui_primapag.h"

PrimaPag::PrimaPag(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PrimaPag)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(0);
}

PrimaPag::~PrimaPag()
{
    delete ui;
}


void PrimaPag::on_autentificare_clicked()
{
    //trimitere la server
    QString user=ui->username->text();
    QString pass=ui->parola->text();
    //verificare exceptii
    //daca e client
    ui->stackedWidget->setCurrentIndex(4);
    //daca e dispecer

    //daca e administrator
}


void PrimaPag::on_inregistrare_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void PrimaPag::on_sch_parola_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QString email=ui->email_2->text();
    QString n_pass=ui->parola_4->text();
    //trimite cerere catre administrator
}


//schimbarea parolei propriu zisa
void PrimaPag::on_sch_parola_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void PrimaPag::on_spre_autentificare_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


//inregistrarea propriu zisa
void PrimaPag::on_inregistrare_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    //verificare la server
    //exceptie daca exista
}

