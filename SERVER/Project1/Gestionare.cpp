#include "Gestionare.h"
#include "CerereLogare.h"
#include "CerereInregistrare.h"
#include "CerereAdApel.h"
#include "CerereIstoricCl.h"
#include "CerereListaAsteptare.h"
#include "CerereAdDetalii.h"
#include "CerereIstoricDisp.h"
#include "CerereUtilizatori.h"
#include "CerereIstoricAdm.h"
#include "CerereDispeceri.h"
#include "CerereStergeri.h"


Gestionare::Gestionare()
{
}

string Gestionare::cerere(string primit)
{
	string protocol="";
	for (int i = 0; i < primit.length(); i++)
	{
		if (primit[i] == '$')i = primit.length();
		protocol += primit[i];
	}

	//logare

	if (stoi(protocol)==0)
	{
		string username;
		string parola;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)username += primit[i];
			else if (nr_del == 2)parola += primit[i];
			else if (nr_del == 3)break;
		}
		CerereLogare log(username, parola);
		return log.verificare();
	}
	//inregistrare+sch parola
	if (stoi(protocol) == 1)
	{
		string username, parola, nume, prenume, email, tel;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++) {
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)username += primit[i];
			else if (nr_del == 2)parola += primit[i];
			else if (nr_del == 3)nume += primit[i];
			else if (nr_del == 4)prenume += primit[i];
			else if (nr_del == 5)email += primit[i];
			else if (nr_del == 6)tel += primit[i];
		}
		CerereInregistrare inreg(username, parola, nume, prenume, email, tel);
		return inreg.verificare();
	}

	//parte client
	//ad apel in istoric
	if (stoi(protocol) == 2)
	{
		string u, d, i_a, s_a, f;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)u += primit[i];
			else if (nr_del == 2)d += primit[i];
			else if (nr_del == 3)i_a += primit[i];
			else if (nr_del == 4)s_a += primit[i];
			else if (nr_del == 5)f += primit[i];
		}
		CerereAdApel apel(u, d, i_a, s_a, f);
		return apel.verificare();
	}
	//istoric pt client
	if (stoi(protocol)==3)
	{
		string u;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)u += primit[i];
		}
		CerereIstoricCl is_cl(u);
		return is_cl.verificare();
	}

	//parte dispecer
	//lista in asteptare pentru dispecer
	if(stoi(protocol) == 4)
	{
		string u_d;
		int nr_del=0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)u_d += primit[i];
		}
		CerereListaAsteptare lista(u_d);
		return lista.verificare();
	}
	//adaugare detalii de dispecer
	if (stoi(protocol) == 5)
	{
		string u_d;
		string s_apel;
		string detalii;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)u_d += primit[i];
			else if (nr_del == 2)s_apel += primit[i];
			else if (nr_del == 3)detalii += primit[i];
		}
		CerereAdDetalii ad_det(u_d, s_apel, detalii);
		return ad_det.verificare();
	}
	//istoricul dispecerului
	if (stoi(protocol) == 6)
	{
		string u_d;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)u_d += primit[i];
		}
		CerereIstoricDisp istoric_disp(u_d);
		return istoric_disp.verificare();
	}
	//lista utilizatori
	if (stoi(protocol) == 7)
	{
		CerereUtilizatori ut;
		return ut.verificare();
	}
	//cerere stergere utilizator
	if (stoi(protocol) == 17)
	{
		//17$user_cl$user_disp
		string user_cl, user_disp;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)user_cl += primit[i];
			if (nr_del == 2)user_disp += primit[i];
		}
		CerereStergeri cerere_st;
		if (cerere_st.cerere_stergere(user_cl, user_disp) == true)
			return "v";
		return "x";
	}

	//parte administrator
	//istoric apeluri pentru administrator
	if (stoi(protocol) == 8)
	{
		CerereIstoricAdm is_Adm;
		return is_Adm.verificare();
	}
	//lista dispeceri
	if (stoi(protocol) == 16)
	{
		CerereDispeceri disp;
		return disp.verificare();
	}
	//sterge dispecer
	if (stoi(protocol) == 9)
	{
		string u_d;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)u_d += primit[i];
		}
		if(B_D::create_Instance()->sterge_disp(u_d)==true) return "v";
		return "x";
	}
	//sterge apel
	if (stoi(protocol) == 10)
	{
		//10$nr randului din lista de asteptare$
		string nr;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)nr += primit[i];
		}
		if (B_D::create_Instance()->sterge_apel(nr) == true)return "v";
		return "x";
	}
	//lista inregistrari
	if (stoi(protocol) == 11)
	{
		CerereInregistrare inreg;
		return inreg.lista_inregistrari();
	}
	//aproba inregistrare
	if (stoi(protocol) == 12)
	{//ma iau dupa numarul din lista de inregistrare
		string nr;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)nr += primit[i];
		}
		if (B_D::create_Instance()->aprobare_inregistrare(nr) == true)
			return "v";
		return "x";
	}
	//respinge inregistrarea
	if (stoi(protocol) == 13)
	{
		string nr;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)nr += primit[i];
		}
		if (B_D::create_Instance()->sterge_inregistrare(nr) == true)return "v";
		return "x";
	}
	//lista stergerilor
	if (stoi(protocol) == 14)
	{
		CerereStergeri stergeri;
		return stergeri.lista_st();
	}
	//aprobare stergere utilizator
	if (stoi(protocol) == 15)
	{
		string user;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)user += primit[i];
		}
		if (B_D::create_Instance()->aprobare_st(user) == true)return "v";
		return "x";
	}
	//respingere stergere utilizator
	if (stoi(protocol) == 18)
	{
		string user;
		int nr_del = 0;
		for (int i = 0; i < primit.length(); i++)
		{
			if (primit[i] == '$')
			{
				nr_del++;
				i++;
			}
			if (nr_del == 1)user += primit[i];
		}
		if (B_D::create_Instance()->respingere_st(user) == true)return "v";
		return "x";
	}

	return "x";
}