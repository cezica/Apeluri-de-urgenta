#include "Fisiere.h"
#include <string>
#include <filesystem>

vector<string> Fisiere::parseaza_linie(string linie)
{
	vector<string> text;
	string cuvinte;
	for (int i = 0; i < linie.size(); i++)
	{
		if (linie[i] == delimitator || linie[i] == '\0')
		{
			text.push_back(cuvinte);
			cuvinte="";
			i++;
		}
		cuvinte += linie[i];
	}
	return text;
}

void Fisiere::seteaza_update()
{
	update = true;
}

vector<vector<string>> Fisiere::obtine_date()
{
	return date;
}

string Fisiere::obtine_id(string coloana, string text)
{	
	string id;
	for (int i = 0; i < date.size(); i++)
		if (date[0][i] == coloana)
			for(int j=1;j<date[i].size();j++)
				if(date[j][i]==text)
					id = date[0][j];
	return id;
}

void Fisiere::delete_Inregistrare(string prima_variabila)
{
	for (int i = 1; i < date.size(); i++) //pe prima linie sunt trecute numele coloanelor
		if (date[i][0] == prima_variabila)
			date.erase(date.begin() + i);
}

void Fisiere::insert_Inregistrare(vector<string> inregistrare)
{
	date.push_back(inregistrare);
}

void Fisiere::update_Inregistrare(string id, string coloana, string text)
{
	for (int i = 0; i < date.size(); i++)
		if (date[i][0] == id)
			for (int j = 1; j < date[i].size(); i++)
				if (date[i][j] == coloana)
				{
					date[i][j].clear();
					date[i][j]=text;
				}
}

vector<int> Fisiere::select_Inregistrare(string coloana, string text)
{
	vector<int> index;
	for (int i = 0; i < date.size(); i++)
		if (date[0][i] == coloana)
		{
			for (int j = 1; j < date.size(); j++)
				if (date[j][i] == text)
					index.push_back(j);
			break;
		}
	return index;
}

vector<string> Fisiere::intoarce_inregistrare(int index)
{
	return date[index];
}

Fisiere::Fisiere(string numeFisier)
{
	this->numeFisier = numeFisier;
	string linie;
	fisier.open(numeFisier, ios::in);
	if (!fisier.is_open())
	{
		update = false;
		exista = false;
		return;	
	}
	while (!fisier.eof())
	{
		getline(fisier, linie);
		date.push_back(parseaza_linie(linie));
	}
	fisier.close();
}

Fisiere::Fisiere(string numeFisier, bool create)
{
	this->update = false;
	fisier.open(numeFisier, ios::app);
	fisier.close();
}

Fisiere::~Fisiere()
{
	if (update == false)
		return;
	string linie;
	FISIER.open(numeFisier, ios::out);
	
	char del[] = "";
	del[0] = delimitator;
	for (int i = 0; i < date.size(); i++)
	{
		for (int j = 0; j < date[i].size(); j++)
		{
			FISIER << date[i][j];
			FISIER << delimitator;
		}
		FISIER << "\n";
	}

	FISIER.close();
}
