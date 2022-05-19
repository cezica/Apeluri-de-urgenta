#pragma once
#include"Fisiere.h"

class Apel
{
private:
	string nume_client;
	string nume_dispecer;
	string date_inceput_apel;
	string date_sfarsit_apel;
	string nume_fisier;
	string detalii;
	string rezultat;
	bool inserat;
public:
	string obtine_rezultat();
	void seteaza_inserat();
	bool obtine_inserat();
	void seteaza__rezultat(string variabila);

	void seteaza_detalii(string detalii);
	void seteaza_nume_client(string nume_client);
	void seteaza_nume_dispecer(string nume_dispecer);
	void seteaza_date_inceput_apel(string date_inceput_apel);
	void seteaza_date_sfarsit_apel(string date_sfarsit_apel);
	void seteaza_nume_fisier(string nume_fisier);

	string obtine_nume_client();
	string obtine_nume_dispecer();
	string obtine_date_inceput_apel();
	string obtine_date_sfarsit_apel();
	string obtine_nume_fisier();
	string obtine_detalii();

	//Apel& operator = (const Apel& A1);
	
	Apel() {};
	Apel(string nume_client, string nume_dispecer, string date_inceput_apel, string date_sfarsit_apel, string nume_fisier) 
	{
		inserat = false;
		this->nume_client=nume_client;
		this->nume_dispecer=nume_dispecer;
		this->date_inceput_apel=date_inceput_apel;
		this->date_sfarsit_apel=date_sfarsit_apel;
		this->nume_fisier=nume_fisier;
	};
	~Apel() {};
};

