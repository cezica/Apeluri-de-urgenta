#ifndef APEL_H
#define APEL_H

#include <QDialog>
#include <QDateTime>
#include <QTimer>

namespace Ui {
class apel;
}

class apel : public QDialog
{
    Q_OBJECT

public:
    explicit apel(QWidget *parent = nullptr);
    ~apel();

private slots:
    void on_inchidere_apel_clicked();
public slots:
    void timp();

private:
    QTimer *s_apel;
    QTime parametru;
    Ui::apel *ui;
};

#endif // APEL_H
