#include "Apel.h"

void Apel::seteaza_inserat()
{
	inserat = true;
}

bool Apel::obtine_inserat()
{
	return inserat;
}

void Apel:: seteaza__rezultat(string variabila)
{
	rezultat = variabila;
}


string Apel::obtine_nume_client()
{
	return nume_client;
}


string Apel::obtine_nume_dispecer()
{
	return nume_dispecer;
}

string Apel::obtine_date_inceput_apel()
{
	return date_inceput_apel;
}

string Apel::obtine_date_sfarsit_apel()
{
	return date_sfarsit_apel;
}

string Apel::obtine_nume_fisier()
{
	return nume_fisier;
}

string Apel::obtine_rezultat()
{
	return rezultat;
}
