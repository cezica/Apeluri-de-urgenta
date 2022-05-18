#pragma once
#include "B_D.h"
#include "ICerere.h"

class CerereLogare:public ICerere
{
private:
	string username;
	string parola;
public:
	CerereLogare(string us, string par);
	string verificare();
};

