#include "CerereInregistrare.h"

CerereInregistrare::CerereInregistrare(string user, string par, string nume, string pren, string email, string telefon)
{
	u = user; p = par; n = nume; pn = pren; e = email; tel = telefon;
}

CerereInregistrare::CerereInregistrare()
{
}

string CerereInregistrare::verificare()
{
	if( B_D::create_Instance()->inregistrare(u, p, n, pn, e, tel)==true)
		return "v";
	return "x";
}

string CerereInregistrare::lista_inregistrari()
{
	return B_D::create_Instance()->lista_inregistrari();
}
