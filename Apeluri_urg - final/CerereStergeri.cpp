#include "CerereStergeri.h"
#include "cerereutilz.h"

CerereStergeri::CerereStergeri()
{
}

void CerereStergeri::set_ui(Ui::PrimaPag* afisaj)
{
	ui = afisaj;
}

bool CerereStergeri::_cerere()
{
	//trimitere la server
	QString trimite = "14$";
	//primesc username_cl$user_disp*username_cl..
	QString raspuns = "cez.el$d_grigore*";

	QStringList lista_stergeri = raspuns.split('*');
	for (int i = 0; i < lista_stergeri.count() - 1; i++)
	{
		QStringList date_st = lista_stergeri[i].split('$');

		user_cl << date_st[0];
		user_disp << date_st[1];
		ui->lista_cereri_st->addItem(date_st[0] + " - " + date_st[1]);
	}
	return 0;
}

QString CerereStergeri::_cerere_aprob_stergere()
{
	QString linie = ui->lista_cereri_st->currentItem()->text();
	QStringList us_disp = linie.split(" - ");
	//0-user client, 1-user disp

	//trimitere la server 
	QString trimite = "14$" + us_disp[0] + "$";
	return us_disp[0];
}

void CerereStergeri::_cerere_resping_stergere()
{
	QString linie = ui->lista_cereri_st->currentItem()->text();
	QStringList us_disp = linie.split(" - ");

	//trimitere la server
	QString trimitere = "15$" + us_disp[0] + "$";
}
