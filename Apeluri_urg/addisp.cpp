#include "addisp.h"
#include "ui_addisp.h"

AdDisp::AdDisp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdDisp)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("./detalii.png"));
}

AdDisp::~AdDisp()
{
    delete ui;
}

QStringList AdDisp::return_informatii()
{
    QStringList lista;
    lista.append(username);
    lista.append(email);
    lista.append(nume);
    lista.append(prenume);
    lista.append(tip);
    lista.append(tel);
    return lista;
}

void AdDisp::on_pushButton_clicked()
{
    username = ui->linie_username->text();
    parola = ui->linie_parola->text();
    email = ui->linie_email->text();
    nume = ui->linie_nume->text();
    prenume = ui->linie_prenume->text();
    tip = ui->linie_tip->text();
    tel = ui->linie_tel->text();

    //trimitere la server

    this->hide();
}

