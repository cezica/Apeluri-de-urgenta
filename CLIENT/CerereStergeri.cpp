#include "CerereStergeri.h"
#include "cerereutilz.h"
#include "Conexiune.h"

CerereStergeri::CerereStergeri()
{
}

void CerereStergeri::set_ui(Ui::PrimaPag* afisaj)
{
	ui = afisaj;
}

std::string CerereStergeri::_cerere()
{
	//trimitere la server
	QString trimite = "14$";
	//primesc username_cl$user_disp*username_cl..
	Conexiune::getinstance()->trimite_cerere(trimite.toStdString());
	QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());
	//QString raspuns = "cez.el$d_grigore*";
	if (raspuns == "x")
		return raspuns.toStdString();

	QStringList lista_stergeri = raspuns.split('*');
	for (int i = 0; i < lista_stergeri.count() - 1; i++)
	{
		QStringList date_st = lista_stergeri[i].split('$');

		user_cl << date_st[0];
		user_disp << date_st[1];
		ui->lista_cereri_st->addItem(date_st[0] + " - " + date_st[1]);
	}
	return "v";
}

QString CerereStergeri::_cerere_aprob_stergere()
{
	QString linie = ui->lista_cereri_st->currentItem()->text();
	QStringList us_disp = linie.split(" - ");
	//0-user client, 1-user disp

	//trimitere la server 
	QString trimite = "15$" + us_disp[0] + "$";

	Conexiune::getinstance()->trimite_cerere(trimite.toStdString());
	QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());

	return us_disp[0];
}

bool CerereStergeri::_cerere_resping_stergere()
{
	QString linie = ui->lista_cereri_st->currentItem()->text();
	QStringList us_disp = linie.split(" - ");

	//trimitere la server
	QString trimitere = "18$" + us_disp[0] + "$";

	Conexiune::getinstance()->trimite_cerere(trimitere.toStdString());
	QString raspuns = QString::fromStdString(Conexiune::getinstance()->obtine_raspuns());
	
	if (raspuns == "v")return true;
	return false;
}
