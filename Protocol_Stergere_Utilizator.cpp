#include "Protocol_Stergere_Utilizator.h"

void Protocol_Stergere_Utilizator::rezultat()
{
	if (F->obtine_date().size() == n - 1 && G->obtine_date().size() == m - 1)
	{
		F->seteaza_rezultat("v");
		this->raspuns = "v";
	}
	else
	{
		F->seteaza_rezultat("x");
		this->raspuns = "x";
	}
}

string Protocol_Stergere_Utilizator::obtine_raspuns()
{
	return this->raspuns;
}

int Protocol_Stergere_Utilizator::obtine_eroare()
{
	return this->eroare;
}

Protocol_Stergere_Utilizator::Protocol_Stergere_Utilizator(string username)
{
	 F = new Fisiere("Înregistrari_Utilizatori.txt");
	 n = F->obtine_date().size();
	F->seteaza_update();
	F->delete_Inregistrare(username);


	 G = new Fisiere("Username+parola.txt.txt");
	 m = G->obtine_date().size();
	G->seteaza_update();
	G->delete_Inregistrare(username);
}

Protocol_Stergere_Utilizator::~Protocol_Stergere_Utilizator()
{
	delete F;
	delete G;
}
