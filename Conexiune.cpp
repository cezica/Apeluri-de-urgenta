#include "Conexiune.h"

void Conexiune::creaza_conexiune()
{
	listener.listen(2000); //se conecteaza la portul 2000
	listener.accept(socket); //asteapta un "Client" sa se conecteze la socket

	cout << "Conectat la client" << endl;
}

void Conexiune::start_comunicare()
{
	string raspuns;
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
			{
				Logare L(text[1], text[2]);
				trimite_raspuns(L.obtine_rezultat());
				L.~Logare();
			}

			//inregistrare client -> x/v
			if (text[0] == "1")
			{
				Înregistrare I(text[1], text[2],text[3],text[4],text[5],text[6]);
				trimite_raspuns(I.obtine_rezultat());
				I.~Înregistrare();
			}
			
			//istoric apel -> x/v
			if (text[0] == "2")
			{
				Apel A(text[1],text[2],text[3],text[4],text[5]);
				Istoric_Apel IA;
				IA.insert_apel(A);
				trimite_raspuns(A.obtine_rezultat());
				A.~Apel();
				IA.~Istoric_Apel();
			}

			//istoric apeluri client -> data+timp inceput_apel$data+timp sfarsit_apel$tip apel*
			if (text[0] == "3")
			{
				Istoric_Apel IA;
				IA.istoric_apeluri_client(text[1]);
				trimite_raspuns(IA.obtine_rezultat());
				IA.~Istoric_Apel();
			}

			//
			if (text[0] == "4")
			{

			}

			//
			if (text[0] == "5")
			{

			}

			//istoric apeluri dispecer -> username_client$data+timp$detalii
			if (text[0] == "6")
			{

			}

			//
			if (text[0] == "7")
			{

			}

			//istoric apel -> intoarce toate apelurile sub forma username_client$username_dispecer$nume_fisier_audio$
			if (text[0] == "8")
			{
				Istoric_Apel IA;
				IA.istoric_apeluri_admin();
				trimite_raspuns(IA.obtine_rezultat());
			}

			if (text[0] == "9")
			{

			}

			if (text[0] == "10")
			{

			}

			if (text[0] == "11")
			{

			}

			if (text[0] == "12")
			{

			}

			if (text[0] == "13")
			{

			}

			if (text[0] == "14")
			{

			}

			if (text[0] == "15")
			{

			}
		}
	}
}