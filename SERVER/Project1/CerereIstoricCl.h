#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereIstoricCl:public ICerere
{
private:
	string user;
public:
	CerereIstoricCl(string u);
	string verificare();
};

