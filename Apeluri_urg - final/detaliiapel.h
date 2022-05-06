#ifndef DETALIIAPEL_H
#define DETALIIAPEL_H
#include "ui_primapag.h"
#include "cerereistoricadm.h"
#include "cerereutilz.h"
#include "cereredisp.h"

#include <QDialog>

namespace Ui {
class DetaliiApel;
}

class DetaliiApel : public QDialog
{
    Q_OBJECT

public:
    explicit DetaliiApel(QWidget *parent = nullptr);
    void set_afisaj(Ui::PrimaPag *a);
    void set_iteratori(int a, int b, int c, CerereIstoricAdm is_ad, CerereUtilz d_u, CerereDisp d_d);
    ~DetaliiApel();

private slots:
    void on_b_audio_clicked();

private:
    Ui::DetaliiApel *ui;
    Ui::PrimaPag *afisaj;
    int iterator_cl;
    int iterator_disp;
    int iterator_f;
    QString n_fis;
};

#endif // DETALIIAPEL_H
