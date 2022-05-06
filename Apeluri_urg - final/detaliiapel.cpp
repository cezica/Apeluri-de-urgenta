#include "detaliiapel.h"
#include "ui_detaliiapel.h"

//#define QT_MULTIMEDIA_PREFERRED_PLUGINS
#include <QMediaPlayer>


DetaliiApel::DetaliiApel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetaliiApel)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("./detalii.png"));
}

DetaliiApel::~DetaliiApel()
{
    delete ui;
}

void DetaliiApel::set_afisaj(Ui::PrimaPag *a)
{
    afisaj=a;
}


void DetaliiApel::set_iteratori(int a,int b, int c, CerereIstoricAdm is_ad, CerereUtilz d_u, CerereDisp d_d)
{
    iterator_cl=a;
    iterator_disp=b;
    //iterator_f=c;

    ui->inf_client->setText("Nume: "+d_u.lista_nume[a]+"\nPrenume: "+d_u.lista_prenume[a]+"\nEmail: "+d_u.lista_email[a]
                            +"\nTelefon: "+d_u.lista_tel[a]);
    ui->inf_dispecer->setText("Nume: " + d_d.lista_nume[b] + "\nPrenume: " + d_d.lista_prenume[b] +"\nTip: "+d_d.lista_tip[b]+ 
                            "\nEmail: " + d_d.lista_email[b]+ "\nTelefon: " + d_d.lista_tel[b]);
    n_fis=is_ad.nume_fis[c];
}

void DetaliiApel::on_b_audio_clicked()
{
    QMediaPlayer *player=new QMediaPlayer();
    //pt a pune numele fisierului
    player->setSource(QUrl::fromLocalFile("Fisiere_audio/"+n_fis+".wav"));
    player->play();
}


