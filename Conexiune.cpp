#include "Conexiune.h"
#include "Protocol_Logare.h"
#include "Protocol_Inregistrare.h"
#include "Protocol_Istoric_Apel.h"
#include "Protocol_Istoric_Apel_Clienti.h"

void Conexiune::creaza_conexiune()
{
	listener.listen(2000); //se conecteaza la portul 2000
	listener.accept(socket); //asteapta un "Client" sa se conecteze la socket

	cout << "Conectat la client" << endl;
}

void Conexiune::start_comunicare()
{
	string raspuns;
	IProtocol* P;
	while (true)
	{
		vector<string>text;
		string cuvinte;
		socket.receive(buffer, sizeof(buffer), received);   //Cerere de la client
		if (received > 0)
		{
			for (int i = 0; i <= strlen(buffer); i++)
			{
				if (buffer[i] == delimitator || buffer[i] == '\0')
				{
					text.push_back(cuvinte);
					cuvinte = "";
					i++;
				}
				cuvinte += buffer[i];
			}
			cout << buffer << endl;
			//buffer=Text de proba*text*inca ceva
			//cuvinte=[Text de proba]
			//text=[[Text de proba], [text], [inca ceva]]

			//logare -> x/v
			if (text[0] == "0")
				P = new Protocol_Logare(text[1], text[2]);

			//inregistrare client -> x/v
			if (text[0] == "1")
				P = new Protocol_Inregistrare(text[1], text[2], text[3], text[4], text[5], text[6]);

			//istoric apel -> x/v
			if (text[0] == "2")
				IProtocol* P = new Protocol_Istoric_Apel(text[1], text[2], text[3], text[4], text[5]);

			//istoric apeluri client -> data+timp inceput_apel$data+timp sfarsit_apel$tip apel*
			if (text[0] == "3")
				IProtocol* P = new Protocol_Istoric_Apel_Clienti(text[1]);

			//istoric dispecer fara detalii -> username_client$data sfarsit_apel$*
			if (text[0] == "4")
			{
				Istoric_Apel IA;
				IA.istoric_apeluri_dispecer(text[1]);
				trimite_raspuns(IA.obtine_rezultat());
				IA.~Istoric_Apel();
			}

			//adaug detalii si mut din asteptare in istoric -> intoarce v/x
			if (text[0] == "5")
			{
				Istoric_Apel IA;
				IA.istoric_asteptare(text[2], text[3]);
				trimite_raspuns(IA.obtine_rezultat());
				IA.~Istoric_Apel();
			}

			//istoric apeluri dispecer -> username_client$data+timp$detalii$fisier_audio$
			if (text[0] == "6")
			{
				Istoric_Apel IA;
				IA.istoric_apeluri_dispecer_cu_detalii(text[1]);
				trimite_raspuns(IA.obtine_rezultat());
				IA.~Istoric_Apel();
			}

			//afiseaza toti utilizatorii pt dispecer -> username$nume$prenume$email$telefon$*
			if (text[0] == "7")
			{
				Istoric_Apel IA;
				IA.istoric_apeluri_pt_dispecer();
				trimite_raspuns(IA.obtine_rezultat());
				IA.~Istoric_Apel();
			}

			//istoric apel -> intoarce toate apelurile sub forma username_client$username_dispecer$nume_fisier_audio$
			if (text[0] == "8")
			{
				Istoric_Apel IA;
				IA.istoric_apeluri_admin();
				trimite_raspuns(IA.obtine_rezultat());
			}

			//stergere dispecer -> intoarce v/x
			if (text[0] == "9")
			{
				ÎnregistrareDispecer I;
				I.sterge_dispecer(text[1]);
				trimite_raspuns(I.obtine_rezultat());
				I.~ÎnregistrareDispecer();
			}

			//adauga dispecer -> intoarce v/x
			if (text[0] == "10")
			{
				ÎnregistrareDispecer I(text[1], text[2], text[4], text[5], text[3], text[6], text[7]);
				trimite_raspuns(I.obtine_rezultat());
				I.~ÎnregistrareDispecer();
			}

			// lista inregistrari asteptare-> intoarce user$email$nume$prenume$telefon$*
			if (text[0] == "11")
			{
				Istoric_Apel IA;
				IA.istoric_inregistrari();
				trimite_raspuns(IA.obtine_rezultat());
				IA.~Istoric_Apel();
			}

			// aprobare inregistrare-> intoarce v sau x
			if (text[0] == "12")
			{
				Fisiere* F = new Fisiere("Lista in astepare inregistari.txt");
				int n = F->obtine_date().size();
				vector<string> Inregistrare;
				F->seteaza_update();
				vector<int> indecsi = F->select_Inregistrare("username", text[1]);
				for (int i = 0; i < indecsi.size(); i++)
				{
					string IUBIRE = F->intoarce_inregistrare(indecsi[i])[0];
					if (IUBIRE == text[1])
					{
						Inregistrare = F->intoarce_inregistrare(indecsi[i]);
					}
				}

				F->delete_Inregistrare(text[1]);

				Fisiere* G = new Fisiere("Înregistrari_Utilizatori.txt");
				int m = G->obtine_date().size();
				G->insert_Inregistrare(Inregistrare);

				if (F->obtine_date().size() == n - 1 && G->obtine_date().size() == m + 1)
					G->seteaza_rezultat("v");
				else
					G->seteaza_rezultat("x");
				trimite_raspuns(G->obtine_rezultat());

				delete F;
				delete G;
			}

			// respinge inregistrare-> intoarce v sau x                              
			if (text[0] == "13")
			{
				Fisiere* F = new Fisiere("Lista in astepare inregistari.txt");
				int n = F->obtine_date().size();
				F->seteaza_update();
				F->delete_Inregistrare(text[1]);

				if (F->obtine_date().size() == n - 1)
					F->seteaza_rezultat("v");
				else
					F->seteaza_rezultat("x");
				trimite_raspuns(F->obtine_rezultat());

				delete F;
			}

			//sterge utilizatorul <=> aprobarea stergerii+ stergerea directa de admin
			if (text[0] == "14")
			{
				Fisiere* F = new Fisiere("Înregistrari_Utilizatori.txt");
				int n = F->obtine_date().size();
				F->seteaza_update();
				F->delete_Inregistrare(text[1]);


				Fisiere* G = new Fisiere("Username+parola.txt.txt");
				int m = G->obtine_date().size();
				G->seteaza_update();
				G->delete_Inregistrare(text[1]);


				if (F->obtine_date().size() == n - 1 && G->obtine_date().size() == m - 1)
					F->seteaza_rezultat("v");
				else
					F->seteaza_rezultat("x");
				trimite_raspuns(F->obtine_rezultat());

				delete F;
				delete G;
			}

			// respingere cerere stergere utilizator -> intoarce v sau x
			if (text[0] == "15")
			{
				Fisiere* F = new Fisiere("Lista in astepare inregistari.txt");
				int n = F->obtine_date().size();
				F->seteaza_update();
				F->delete_Inregistrare(text[1]);

				if (F->obtine_date().size() == n - 1)
					F->seteaza_rezultat("v");
				else
					F->seteaza_rezultat("x");
				trimite_raspuns(F->obtine_rezultat());

				delete F;
			}
		}

		trateaza_raspuns(P);
		delete P;
	}
}