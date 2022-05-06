#ifndef PRIMAPAG_H
#define PRIMAPAG_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PrimaPag; }
QT_END_NAMESPACE

class PrimaPag : public QMainWindow
{
    Q_OBJECT

public:
    PrimaPag(QWidget *parent = nullptr);
    ~PrimaPag();

private slots:
    void on_autentificare_clicked();

    void on_inregistrare_clicked();

    void on_sch_parola_clicked();

    void on_sch_parola_2_clicked();

    void on_spre_autentificare_clicked();

    void on_inregistrare_2_clicked();

private:
    Ui::PrimaPag *ui;
};
#endif // PRIMAPAG_H
