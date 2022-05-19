#include "Protocol_aprobare_inregistrari.h"

void Protocol_aprobare_inregistrari::rezultat()
{
	if (F->obtine_date().size() == n - 1 && G->obtine_date().size() == m + 1)
	{
		G->seteaza_rezultat("v");
		this->raspuns = "v";
	}

	else
	{
		G->seteaza_rezultat("x");
		this->raspuns = "x";
	}
}

string Protocol_aprobare_inregistrari::obtine_raspuns()
{
	return this->raspuns;
}

int Protocol_aprobare_inregistrari::obtine_eroare()
{
	return this->eroare;
}

Protocol_aprobare_inregistrari::Protocol_aprobare_inregistrari(string username)
{
	F = new Fisiere("Lista in astepare inregistari.txt");
	n = F->obtine_date().size();
	vector<string> Inregistrare;
	F->seteaza_update();
	vector<int> indecsi = F->select_Inregistrare("username", username);
	for (int i = 0; i < indecsi.size(); i++)
	{
		string cuvant = F->intoarce_inregistrare(indecsi[i])[0];
		if (cuvant == username)
		{
			Inregistrare = F->intoarce_inregistrare(indecsi[i]);
		}
	}

	F->delete_Inregistrare(username);

	G = new Fisiere("Înregistrari_Utilizatori.txt");
	m = G->obtine_date().size();
	G->insert_Inregistrare(Inregistrare);
}

Protocol_aprobare_inregistrari::~Protocol_aprobare_inregistrari()
{
	delete F;
	delete G;
}
