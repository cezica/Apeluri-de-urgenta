#pragma once
#include "Apel.h"
#include<vector>

class Istoric_Apel
{
private:
	vector<Apel> Apeluri;
	string rezultat;
public:
	void citeste_istoric();
	string obtine_rezultat();
	void insert_apel(Apel&A);
	void istoric_apeluri_admin();
	void istoric_apeluri_client(string username);

	Istoric_Apel() {};
	~Istoric_Apel() {};
};

