#pragma once
#include"Fisiere.h"

class Logare
{
private:
	string username;
	string parola;
	string rezultat;
	bool date_corecte();

public:
	string obtine_rezultat();
	Logare() {};
	Logare(string username, string parola) 
	{
		this->username = username;
		this->parola = parola;
		if (date_corecte())
			rezultat = "v";
		else
			rezultat = "x";

	};
	~Logare() {};
};

