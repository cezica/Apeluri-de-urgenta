#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereInregistrare:public ICerere
{
private:
	string u;
	string p;
	string n;
	string pn;
	string e;
	string tel;
public:
	CerereInregistrare(string user, string par, string nume, string pren, string email, string telefon);
	CerereInregistrare();
	string verificare();
	string lista_inregistrari();
};

