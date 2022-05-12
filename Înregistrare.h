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

	bool acelasi_username();
	bool acelasi_individ();
public:
	string obtine_rezultat();

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
			Fisiere* F=new Fisiere(username + ".txt", true);
			delete F;
		}
	};
	~Înregistrare() {};
};

