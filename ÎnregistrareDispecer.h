#pragma once
#include"Fisiere.h"

class �nregistrareDispecer
{
private:
	string username;
	string parola;
	string nume;
	string prenume;
	string email;
	string tip;
	string numar_telefon;
	string rezultat;

	bool acelasi_username();
	bool acelasi_individ();
public:
	string obtine_rezultat();
	void sterge_dispecer(string nume);

	�nregistrareDispecer() {};
	�nregistrareDispecer(string username, string parola, string nume, string prenume, string email, string nr_telefon)
	{
		this->username = username;
		this->parola = parola;
		this->nume = nume;
		this->prenume = prenume;
		this->email = email;
		this->numar_telefon = nr_telefon;
		if (acelasi_individ() && acelasi_username())
			rezultat = "x";
		else
		{
			rezultat = "v";

			vector<string> aux;
			aux.push_back(username);
			aux.push_back(parola);
			aux.push_back(nume);
			aux.push_back(prenume);
			aux.push_back(email);
			aux.push_back(numar_telefon);

			Fisiere* F = new Fisiere("�nregistrari_Dispeceri.txt");
			F->insert_Inregistrare(aux);
			F->seteaza_update();
			delete F;


			Fisiere* G = new Fisiere(username + ".txt", true);
			delete G;
		}
	};
	~�nregistrareDispecer() {};
};

