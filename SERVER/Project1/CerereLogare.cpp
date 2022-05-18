#include "CerereLogare.h"

CerereLogare::CerereLogare(string us, string par)
{
	username = us;
	parola = par;
}

string CerereLogare::verificare()
{
	return B_D::create_Instance()->logare(username, parola);
}
