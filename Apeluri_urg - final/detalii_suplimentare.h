#ifndef DETALII_SUPLIMENTARE_H
#define DETALII_SUPLIMENTARE_H

#include <QDialog>
#include "primapag.h"
#include "ui_primapag.h"

namespace Ui {
class detalii_suplimentare;
}

class detalii_suplimentare : public QDialog
{
    Q_OBJECT

public:
    explicit detalii_suplimentare(QWidget *parent = nullptr);
    void set(QString u, Ui::PrimaPag *a);
    ~detalii_suplimentare();

private slots:
    void on_b_trimitere_det_clicked();

    void on_but_inf_clicked();

private:
    Ui::detalii_suplimentare *det;
    Ui::PrimaPag *afisaj;
    QString user_dispecer;
};

#endif // DETALII_SUPLIMENTARE_H
