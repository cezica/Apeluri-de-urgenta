#include "apel.h"
#include "ui_apel.h"

apel::apel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apel)
{
    ui->setupUi(this);
    parametru = QTime::currentTime();
    setWindowIcon(QIcon("./apel.png"));
    s_apel = new QTimer(this);
    connect(s_apel, SIGNAL(timeout()), this, SLOT(timp()));
    s_apel->start(1000);
}

apel::~apel()
{
    delete ui;
}

void apel::timp()
{
    QTime timp_cr = QTime::currentTime();
    int min = timp_cr.minute() - parametru.minute();
    int sec = timp_cr.second() - parametru.second();

    QString timp_text = QString::number(min) + " : " + QString::number(sec);
    ui->l_durata_apel->setText(timp_text);
}

void apel::on_inchidere_apel_clicked()
{
    
    //se considera apelul terminat
    this->close();
}

