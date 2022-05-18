#pragma once
#include <string>
#include <mysql.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class B_D
{
private:
	static B_D* instance;
	int qstate;
	MYSQL* conn;
	MYSQL_ROW rand;
	MYSQL_RES* rezultat;

	B_D()
	{
		conn = mysql_init(0); //initializeaza si aloca o structura MYSQL

		conn = mysql_real_connect(conn, "localhost", "root", "Apel_urgenta", "test1", 3306, NULL, 0); //stabileste o conexiune la un server MySQL care ruleaza pe gazda.
		//3306 - portul, 0 - client flag-ul

	}
public:
	static B_D* create_Instance()
	{
		if (!instance)
			instance = new B_D();
		return instance;
	}
	string logare(string username, string parola);
	bool inregistrare(string user, string par, string nume, string pren, string email, string telefon);
	bool ad_apel(string u, string d, string i_a, string s_a, string f);
	string istoric_cl(string u);
	string lista_asteptare(string u_d);
	bool ad_detalii(string u, string s_apel, string det);
	string istoric_disp(string u_d);
	string utilizatori();
	bool cerere_stergere(string user_cl, string user_disp);
	string istoric_adm();
	string dispeceri();
	bool sterge_disp(string u_d);
	bool sterge_apel(string nr_rand);
	string lista_inregistrari();
	bool aprobare_inregistrare(string nr);
	bool sterge_inregistrare(string nr);//respingere inregistrare
	string lista_stergeri();
	bool aprobare_st(string user);
	bool respingere_st(string user);
};