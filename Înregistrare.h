#pragma once
#include"Fisiere.h"

class Înregistrare
{
private:
	string username;
	string parola;
	string nume;
	string prenume;
	string email;
	string numar_telefon;
	string rezultat;
	bool aprobat=false;

	bool acelasi_username();
	bool acelasi_individ();
public:
	string obtine_rezultat();
	void seteaza_aprobat();

	Înregistrare() {};
	Înregistrare(string username, string parola, string nume, string prenume, string email, string nr_telefon)
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
			Fisiere* G = new Fisiere("Lista in astepare inregistari.txt");
			vector<string> inregistrare;
			inregistrare.push_back(this->username);
			inregistrare.push_back(this->parola);
			inregistrare.push_back(this->nume);
			inregistrare.push_back(this->prenume);
			inregistrare.push_back(this->email);
			inregistrare.push_back(this->numar_telefon);
			G->insert_Inregistrare(inregistrare);
			delete G;
		}
	};
	~Înregistrare(){};
};

