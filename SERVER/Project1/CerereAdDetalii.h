#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereAdDetalii : public ICerere
{
private:
	string u_d;
	string s_apel;
	string detalii;
public:
	CerereAdDetalii(string u, string n, string det);
	string verificare();
};

