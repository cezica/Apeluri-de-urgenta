#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereUtilizatori:public ICerere
{
public:
	CerereUtilizatori();
	string verificare();
};

