#include "B_D.h"
B_D* B_D::instance = nullptr;

string B_D::logare(string username, string parola)
{
	//testez daca e utilizator
	string query = "SELECT username, parola FROM utilizatori WHERE username=\"" + username + "\" AND parola=\"" + parola + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
		if (!qstate)
		{
			rezultat = mysql_store_result(conn);
			rand = mysql_fetch_row(rezultat);
			if (rand != 0)
			{
				cout << "S-a logat un client!" << endl;
				return "client";
			}
		}

	//testez daca e dispecer
	 query = "SELECT username, parola FROM dispeceri WHERE username=\"" + username + "\" AND parola=\"" + parola + "\";";
	q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand != 0)
		{
			cout << "S-a logat un dispecer!" << endl;
			return "dispecer";
		}
	}

	//testez daca e administrator
	 query = "SELECT username, parola FROM administratori WHERE username=\"" + username + "\" AND parola=\"" + parola + "\";";
	q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand != 0)
		{
			cout << "S-a logat un administrator!" << endl;
			return "administrator";
		}
	}


	//daca nu e niciuna, return x
	return "x";
}

bool B_D::inregistrare(string user, string par, string nume, string pren, string email, string telefon)
{
	//testam daca exista username-ul
	string query = "SELECT username FROM utilizatori WHERE username=\"" + user+ "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand != 0)return false;//exista deja username-ul
	}

	//testam daca exista email-ul
	query = "SELECT email FROM utilizatori WHERE email=\"" + email + "\";";
	q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand != 0)return false;//exista deja email-ul
	}


	//introducerea in tabela 
	query = "INSERT INTO inregistrari (username, parola, nume, prenume, email, telefon) VALUES (\"" +
		user + "\",\"" + par + "\",\"" + nume + "\",\"" + pren + "\",\"" + email + "\",\"" + telefon + "\");";
	q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		return true;
	}

	return false;
}

bool B_D::ad_apel(string u, string d, string i_a, string s_a, string f)
{
	//introducerea in tabela listei de asteptare!
	string query = "INSERT INTO lista_asteptare (user_cl,dispecer,i_apel,s_apel,n_fis) VALUES (\"" +
		u + "\",\"" + d + "\",\"" + i_a + "\",\"" + s_a + "\",\"" + f + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		cout << "S-a efectuat un apel cu succes!" << endl;
		return true;
	}

	return false;
}

string B_D::istoric_cl(string u)
{
	//din tabela istoric_clienti, unde username-ul clientului corespunde
	//apel complet <=> au fost adaugate detalii
	string query = "SELECT * FROM istoric_apeluri WHERE user_cl=\"" + u +"\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> apeluri;
		while (rand)
		{
			//trebuie sa vedem si tipul apelului din dispecer
			string tip_dispecer;
			string query2 = "SELECT tip_dispecer FROM dispeceri WHERE username=\"" + (string)rand[2] + "\";";
			const char* q2 = query2.c_str();
			int qstate2 = mysql_query(conn, q2);
			if (!qstate2)
			{
				MYSQL_ROW rand2;
				MYSQL_RES* rezultat2;
				rezultat2 = mysql_store_result(conn);
				rand2 = mysql_fetch_row(rezultat2);
				if (rand2 != 0)tip_dispecer = (string)rand2[0];
			}

			//crearea stringului de trimitere dupa protocol
			//rand[3]
			//string apel=rand[3]+(string)rand[4]+(string)
			string apel = (string)rand[3] +'$'+ (string)rand[4]+'$' + (string)tip_dispecer;
			apeluri.push_back(apel);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : apeluri)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
}

string B_D::lista_asteptare(string u_d)
{
	//tot din tabela istoric_apeluri
	string query = "SELECT * FROM lista_asteptare WHERE dispecer=\"" + u_d + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> apeluri;
		while (rand)
		{
			//rand[0]-user_cl,rand[3]-s_ape;
			string apel = (string)rand[0] + '$' + (string)rand[3];
			apeluri.push_back(apel);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : apeluri)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
}

bool B_D::ad_detalii(string u, string s_apel, string det)
{
	//introduc o tabela lista_asteptare
	string query = "SELECT * FROM lista_asteptare WHERE dispecer=\"" + u +"\" AND s_apel=\"" +s_apel+ "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		//rand[0]-user cl, 1-dispecer, 2- i_a, 3-s_a, 4-n_fis
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand)
		{
			string query2 = "INSERT INTO istoric_apeluri(user_cl,dispecer,i_apel,s_apel,n_fis,detalii) VALUES (\"" +
				(string)rand[0] + "\",\"" + (string)rand[1] + "\",\"" + (string)rand[2] + "\",\"" + (string)rand[3]
				+ "\",\"" + (string)rand[4] + "\",\"" + det + "\");";
			const char* q2 = query2.c_str();
			int qstate2 = mysql_query(conn, q2);  //executa query-ul
			if (qstate2)
				return false;

			//stergerea din lista de asteptare
			query2 = "DELETE FROM lista_asteptare WHERE dispecer=\"" + u + "\" AND s_apel=\"" + s_apel + "\";";
			q2 = query2.c_str();
			qstate2 = mysql_query(conn, q2);  //executa query-ul
			rand = mysql_fetch_row(rezultat);
			if (qstate2)
				return false;
		}
		else return false;
		cout << "S-au adaugat cu succes detalii la apel!" << endl;
		return true;
	}
	return false;
}

string B_D::istoric_disp(string u_d)
{
	string query = "SELECT * FROM istoric_apeluri WHERE dispecer=\"" + u_d + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> apeluri;
		while (rand)
		{
			//crearea stringului de trimitere dupa protocol
			//string apel=rand[1]-user_cl+(string)rand[4]=s_apel+(string)rand[6]=detalii
			string apel = (string)rand[1] + '$' + (string)rand[4] + '$' + (string)rand[6];
			apeluri.push_back(apel);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : apeluri)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
}

string B_D::utilizatori()
{
	string query = "SELECT * FROM utilizatori;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> utilizatori;
		while (rand)
		{
			//crearea stringului de trimitere dupa protocol
			//utilizator=username(rand[1])+nume(rand[3])+prenume+email+tel
			string utilizator = (string)rand[1] + '$' + (string)rand[3] + '$' + (string)rand[4]+'$' + (string)rand[5]+'$' + (string)rand[6];
			utilizatori.push_back(utilizator);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : utilizatori)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
}

bool B_D::cerere_stergere(string user_cl, string user_disp)
{
	string query = "INSERT INTO stergeri(user_cl,user_disp) VALUES (\"" +
		user_cl + "\",\"" + user_disp + "\");";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		cout << "S-a efectuat o cerere de stergere cu succes!" << endl;
		return true;
	}

	return false;
}

string B_D::istoric_adm()
{
	string query = "SELECT * FROM istoric_apeluri;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> apeluri;
		while (rand)
		{
			//1-user_cl, 2-dispecer, 3- i_apel, 4-s_apel, 5-n_fis, 6 detalii
			//intoarce doar user client, user dispecer, numele fisierului
			string apel = (string)rand[1] + '$' + (string)rand[2] + '$' + (string)rand[5];
			apeluri.push_back(apel);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : apeluri)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
}

string B_D::dispeceri()
{
	string query = "SELECT * FROM dispeceri;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> dispeceri;
		while (rand)
		{
			//user_disp-rand[1] tipul dispecerului-rand[7] nume-rand[4] prenume-rand[5]$email-rand[3]$tel*...
			string d = (string)rand[1] + '$' + (string)rand[7] + '$' + (string)rand[4] 
				+ '$' + (string)rand[5] + '$' + (string)rand[3] + '$' + (string)rand[6];
			dispeceri.push_back(d);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : dispeceri)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
}

bool B_D::sterge_disp(string u_d)
{
	string query = "DELETE FROM dispeceri WHERE dispecer=\"" + u_d + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		//rand[0]-user cl, 1-dispecer, 2- i_a, 3-s_a, 4-n_fis
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand)
		{
			cout << "S-a sters dispecerul cu succes!" << endl;
			return true;
		}
	}
	return false;
}

bool B_D::sterge_apel(string nr_Rand)
{
	string query = "DELETE FROM istoric_apeluri WHERE ROW_COUNT()=\"" + nr_Rand + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand)
		{
			cout << "S-a sters apelul cu succes!" << endl;
			return true;
		}
	}
	return false;
}

string B_D::lista_inregistrari()
{
	string query = "SELECT * FROM inregistrari;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> inregs;
		while (rand)
		{
			//user-rand[1] $email-rand[5] $nume-rand[3]$prenume [4] $tel[6]*...
			string in = (string)rand[1] + '$' + (string)rand[5] + '$' + (string)rand[3] + '$' + (string)rand[4] + '$' + (string)rand[6];
			inregs.push_back(in);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : inregs)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
	return string();
}

bool B_D::sterge_inregistrare(string nr)
{
	string query = "DELETE FROM inregistrari WHERE ROW_COUNT()=\"" + nr + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand)
		{
			cout << "S-a sters inregistrarea cu succes!" << endl;
			return true;
		}
	}
	return false;
}

bool B_D::aprobare_inregistrare(string nr)
{
	string query = "SELECT * FROM inregistrari WHERE idinregistrare=\"" + nr + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand)
		{
			//in inregistrari ordinea
			//rand[0]-id, 1-user, 2-parola, 3-nume, 4-prenume, 5-email, 6-tel 
			// 
			//in utilizatori ordinea
			// rand[0]-id, 1-user, 2-parola, 3-email, 4-nume, 5-prenume, 6-tel
			//il vom pune la utilizatori
			query = "INSERT INTO utilizatori(username, parola, email, nume, prenume, telefon) VALUES (\"" +
				(string)rand[1] + "\",\"" + (string)rand[2] + "\",\"" + (string)rand[5] + "\",\"" + (string)rand[3]
				+ "\",\"" + (string)rand[4] + "\",\"" + (string)rand[6] + "\");";
			q = query.c_str();
			qstate = mysql_query(conn, q);  //executa query-ul
			if (qstate) return false;

			//sterge si din lista de cereri inreg
			query = "DELETE FROM inregistrari WHERE idinregistrare=\"" + nr + "\";";
			q = query.c_str();
			qstate = mysql_query(conn, q);  //executa query-ul
			if (!qstate)
			{
				rezultat = mysql_store_result(conn);
				return true;
			}
		}
	}
	return false;
}

string B_D::lista_stergeri()
{
	string query = "SELECT * FROM stergeri;";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		vector<string> stergeri;
		while (rand)
		{
			//rand[0]-user_cl,rand[1]-user_disp;
			string sters = (string)rand[0] + '$' + (string)rand[1];
			stergeri.push_back(sters);
			rand = mysql_fetch_row(rezultat);
		}
		string raspuns = "";
		for (auto i : stergeri)
		{
			raspuns += i + "*";
		}
		return raspuns;
	}
	return "x";
}

bool B_D::aprobare_st(string user)
{
	string query = "SELECT * FROM stergeri WHERE user_cl=\"" + user + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand)
		{
			//in stergeri ordinea
			//rand[0]-user_cl
			// 
			//in utilizatori ordinea
			// rand[0]-id, 1-user, 2-parola, 3-email, 4-nume, 5-prenume, 6-tel
			//il vom sterge din utilizatori
			query = "DELETE FROM utilizatori WHERE username=\"" + user + "\";";
			q = query.c_str();
			qstate = mysql_query(conn, q);  //executa query-ul
			if (!qstate)
				cout << "S-a aprobat cererea de stergere cu succes!" << endl;
			else return false;

			//sterge si din lista de cereri de stergere
			string query2 = "DELETE FROM stergeri WHERE user_cl=\"" + user + "\";";
			const char* q2 = query2.c_str();
			qstate = mysql_query(conn, q2);  //executa query-ul
			if (!qstate)
				return true;
		}
	}
	return false;
}

bool B_D::respingere_st(string user)
{
	string query = "DELETE FROM stergeri WHERE user_cl=\"" + user + "\";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);  //executa query-ul
	if (!qstate)
	{
		rezultat = mysql_store_result(conn);
		rand = mysql_fetch_row(rezultat);
		if (rand)
		{
			cout << "S-a respins cererea de stergere cu succes!" << endl;
			return true;
		}
	}
	return false;
}
