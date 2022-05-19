#include "Protocol_Respinge_Inregistrare.h"

void Protocol_Respinge_Inregistrare::rezultat()
{

	if (F->obtine_date().size() == n - 1)
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

string Protocol_Respinge_Inregistrare::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Respinge_Inregistrare::obtine_eroare()
{
    return this->eroare;
}

Protocol_Respinge_Inregistrare::Protocol_Respinge_Inregistrare(string username)
{
	 F = new Fisiere("Lista in astepare inregistari.txt");
	int n = F->obtine_date().size();
	F->seteaza_update();
	F->delete_Inregistrare(username);
}

Protocol_Respinge_Inregistrare::~Protocol_Respinge_Inregistrare()
{
    delete F;
}
