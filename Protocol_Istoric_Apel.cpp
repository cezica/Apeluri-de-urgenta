#include "Protocol_Istoric_Apel.h"

void Protocol_Istoric_Apel::rezultat()
{
	this->raspuns = A->obtine_rezultat();
}

string Protocol_Istoric_Apel::obtine_raspuns()
{
	return this->raspuns;
}

int Protocol_Istoric_Apel::obtine_eroare()
{
	return this->eroare;
}

Protocol_Istoric_Apel::Protocol_Istoric_Apel(string nume_client, string nume_dispecer, string date_inceput_apel, string date_sfarsit_apel, string nume_fisier)
{
	A = new Apel(nume_client, nume_dispecer, date_inceput_apel, date_sfarsit_apel, nume_fisier);
	IA = new Istoric_Apel();
	IA->insert_apel(*A);
}

Protocol_Istoric_Apel::~Protocol_Istoric_Apel()
{
	delete A;
	delete IA;
}
