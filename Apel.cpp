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


void Apel::seteaza_detalii(string detalii)
{
	this->detalii = detalii;
}

string Apel::obtine_detalii()
{
	return detalii;
}

void Apel::seteaza_nume_client(string nume_client)
{
	this->nume_client = nume_client;
}

void Apel::seteaza_nume_dispecer(string nume_dispecer)
{
	this->nume_dispecer = nume_dispecer;
}
void Apel::seteaza_date_inceput_apel(string date_inceput_apel)
{
	this->date_inceput_apel = date_inceput_apel;
}
void  Apel::seteaza_date_sfarsit_apel(string date_sfarsit_apel)
{
	this->date_sfarsit_apel = date_sfarsit_apel;
}
void  Apel::seteaza_nume_fisier(string nume_fisier)
{
	this->nume_fisier = nume_fisier;
}

string  Apel::obtine_nume_client()
{
	return nume_client;
}
string  Apel::obtine_nume_dispecer()
{
	return nume_dispecer;
}
string  Apel::obtine_date_inceput_apel()
{
	return date_inceput_apel;
}
string  Apel::obtine_date_sfarsit_apel()
{
	return date_sfarsit_apel;
}
string  Apel::obtine_nume_fisier()
{
	return nume_fisier;
}

string Apel::obtine_rezultat()
{
	return rezultat;
}
