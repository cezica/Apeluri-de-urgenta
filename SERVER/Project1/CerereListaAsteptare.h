#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereListaAsteptare:public ICerere
{
private:
	string user_dispecer;
public:
	CerereListaAsteptare(string u);
	string verificare();
};

