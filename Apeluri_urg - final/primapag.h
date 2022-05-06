#ifndef PRIMAPAG_H
#define PRIMAPAG_H

#include <QMainWindow>
#include "cerereutilz.h"
#include "cereredisp.h"
#include "cerereistoricadm.h"
#include "cerereinreg.h"
#include "detaliiapel.h"
#include "CerereStergeri.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PrimaPag; }
QT_END_NAMESPACE

class PrimaPag : public QMainWindow
{
    Q_OBJECT

public:
    PrimaPag(QWidget *parent = nullptr);
    QString username;
    CerereUtilz date_util;
    CerereDisp date_disp;
    CerereIstoricAdm is_admin;
    CerereInreg is_inreg;
    CerereStergeri is_stergeri;
    void apel_universal(QString tip_dispecer);
    ~PrimaPag();

    //setare erori
    void afisare_er(QString mesaj);
private slots:
    void on_autentificare_clicked();

    void on_inregistrare_clicked();

    void on_sch_parola_clicked();

    void on_sch_parola_2_clicked();

    void on_spre_autentificare_clicked();

    void on_inregistrare_2_clicked();

    void on_apel_112_clicked();

    void on_apel_politie_clicked();

    void on_apel_pompieri_clicked();

    void on_apel_salvamont_clicked();

    void on_apel_ambulanta_clicked();

    void on_apel_smurd_clicked();

    void on_apel_jandarmerie_clicked();

    void on_but_inf_clicked();

    void on_b_inf_disp_clicked();

    void on_b_stergere_disp_clicked();

    void on_b_inf_apel_clicked();

    void on_b_sterg_apel_clicked();

    void on_b_sterg_istoric_clicked();

    void on_but_inf_2_clicked();

    void on_but_stergere_2_clicked();

    void on_b_add_disp_clicked();

    void on_inf_inrg_clicked();

    void on_aprob_inrg_clicked();

    void on_resping_inreg_clicked();

    void on_inf_strg_clicked();

    void on_aprob_strg_clicked();

    void on_resping_strg_clicked();

    void on_add_descriere_clicked();

    void on_delog_cl_clicked();

    void on_delog_disp_clicked();

    void on_delog_adm_clicked();

    void on_but_stergere_clicked();

private:
    Ui::PrimaPag *ui;
};
#endif // PRIMAPAG_H
