#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereIstoricAdm:public ICerere
{
public:
	CerereIstoricAdm();
	string verificare();
};

