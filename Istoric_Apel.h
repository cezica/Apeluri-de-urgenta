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
	void istoric_apeluri_dispecer(string dispecer);
	void istoric_apeluri_dispecer_cu_detalii(string dispecer);
	void istoric_apeluri_pt_dispecer();

	Istoric_Apel() {};
	~Istoric_Apel() {};
};

