#pragma once
#include <fstream>
#include <iostream>
#include <vector>

#define delimitator '$'

using namespace std;

class Fisiere
{
private:
	bool update = true;
	string rezultat;
	ifstream fisier;
	ofstream FISIER;
	string numeFisier;
	vector<vector<string>> date;
	vector<string> parseaza_linie(string linie);
public:
	bool exista = true;
	void seteaza_update();
	void seteaza_update_false();

	string obtine_rezultat();
	void seteaza_rezultat(string caracter);

	vector<vector<string>> obtine_date();
	string obtine_id(string coloana, string text);
	void delete_Inregistrare(string prima_variabila);
	void insert_Inregistrare(vector<string> inregistrare);
	void update_Inregistrare(string id, string coloana, string text);
	vector<int> select_Inregistrare(string coloana,string text);
	vector<string> intoarce_inregistrare(int index);

	Fisiere(string numeFisier);
	Fisiere(string numeFisier, bool create);
	~Fisiere();
};

