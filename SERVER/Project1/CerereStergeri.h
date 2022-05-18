#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereStergeri:public ICerere
{
public:
	CerereStergeri();
	string verificare();
	string lista_st();
	bool cerere_stergere(string user_cl, string user_disp);
};

