#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereAdApel:public ICerere
{
private:
	string user;
	string dispecer;
	string i_apel;
	string s_apel;
	string n_fis;
public:
	CerereAdApel(string u, string d, string i_a, string s_a, string f);
	string verificare();
};

