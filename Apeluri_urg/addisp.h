#ifndef ADDISP_H
#define ADDISP_H

#include <QDialog>

namespace Ui {
class AdDisp;
}

class AdDisp : public QDialog
{
    Q_OBJECT

public:
    explicit AdDisp(QWidget *parent = nullptr);
    QString username;
    QString parola;
    QString email;
    QString nume;
    QString prenume;
    QString tip;
    QString tel;
    QStringList return_informatii();
    ~AdDisp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdDisp *ui;
};

#endif // ADDISP_H
