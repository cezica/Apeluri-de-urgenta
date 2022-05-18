#pragma once
#include "B_D.h"
#include <iostream>
#include <vector>

class Gestionare
{
private:
	vector<string> lista_raspuns;
public:
	Gestionare();
	string cerere(string primit);
};

