#include "detalii_suplimentare.h"
#include "ui_detalii_suplimentare.h"
#include "cerereistoricdisp.h"

#include <QMessageBox>

detalii_suplimentare::detalii_suplimentare(QWidget *parent) :
    QDialog(parent),
    det(new Ui::detalii_suplimentare)
{
    det->setupUi(this);
    setWindowIcon(QIcon("./detalii.png"));
}

detalii_suplimentare::~detalii_suplimentare()
{
    delete det;
}

void detalii_suplimentare::set(QString u, Ui::PrimaPag *a)
{
    user_dispecer=u;
    afisaj=a;
}

void detalii_suplimentare::on_b_trimitere_det_clicked()
{
    QString d=det->line_detalii->text();
    CerereIstoricDisp di(user_dispecer);
    di._cerere_elim_apel(afisaj,d);
    this->hide();
}


void detalii_suplimentare::on_but_inf_clicked()
{
    QMessageBox::information(afisaj->list_utilizatori,"informatii",afisaj->list_utilizatori->currentItem()->text());
}

