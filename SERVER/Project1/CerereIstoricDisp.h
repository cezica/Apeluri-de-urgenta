#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereIstoricDisp:public ICerere
{
private:
	string user_dispecer;
public:
	CerereIstoricDisp(string u_d);
	string verificare();
};

