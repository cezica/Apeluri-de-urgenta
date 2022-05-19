#include "Conexiune.h"

void Conexiune::start_comunicare()
{
	
	string raspuns;
	vector<string>text;
	string cuvinte;
	while (true)
{
		if (selector.wait())
		{
			if (selector.isReady(listener))
			{
				sf::TcpSocket* socket = new sf::TcpSocket;
				listener.accept(*socket); //asteapta un "Client" sa se conecteze la socket


				if (socket->receive(buffer, sizeof(buffer), received) == sf::Socket::Done)   //Cerere de la client
				{
					std::cout << "Un client nou s-a conectat." << endl;
					clienti.push_back(socket);
					selector.add(*socket);
				}
			}
			else
			{
				for (int k = 0; k < clienti.size(); k++)
				{
					if (selector.isReady(*clienti[k]))
					{
						if (clienti[k]->receive(buffer, sizeof(buffer), received) == sf::Socket::Done)
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

								IProtocol* P = NULL;
								//logare -> x/v
								if (text[0] == "0")
									P = new Protocol_Logare(text[1], text[2]);
								else
									//inregistrare client -> x/v
									if (text[0] == "1")
										P = new Protocol_Inregistrare(text[1], text[2], text[3], text[4], text[5], text[6]);
									else
										//istoric apel -> x/v
										if (text[0] == "2")
											P = new Protocol_Istoric_Apel(text[1], text[2], text[3], text[4], text[5]);
										else
											//istoric apeluri client -> data+timp inceput_apel$data+timp sfarsit_apel$tip apel*
											if (text[0] == "3")
												P = new Protocol_Istoric_Apel_Clienti(text[1]);
											else
												//istoric dispecer fara detalii -> username_client$data sfarsit_apel$*
												if (text[0] == "4")
													P = new Protocol_Istoric_Dispecer_fara_detalii(text[1]);
												else
													//adaug detalii si mut din asteptare in istoric -> intoarce v/x
													if (text[0] == "5")
														P = new Protocol_Adauga_detalii_la_apel(text[2], text[3]);
													else
														//istoric apeluri dispecer -> username_client$data+timp$detalii$fisier_audio$
														if (text[0] == "6")
															P = new Protocol_Istoric_Apeluri_Dispecer(text[1]);
														else
															//afiseaza toti utilizatorii pt dispecer -> username$nume$prenume$email$telefon$*
															if (text[0] == "7")
																P = new Protocol_afisarea_utilizatorilor();
															else
																//istoric apel -> intoarce toate apelurile sub forma username_client$username_dispecer$nume_fisier_audio$
																if (text[0] == "8")
																	P = new Protocol_Istoric_apeluri();
																else
																	//stergere dispecer -> intoarce v/x
																	if (text[0] == "9")
																		P = new Protocol_Sterge_Dispecer(text[1]);
																	else
																		//adauga dispecer -> intoarce v/x
																		if (text[0] == "10")
																			P = new Protocol_Adauga_Dispecer(text[1], text[2], text[4], text[5], text[3], text[6], text[7]);
																		else
																			// lista inregistrari asteptare-> intoarce user$email$nume$prenume$telefon$*
																			if (text[0] == "11")
																				P = new Protocol_Lista_Inregistrari_Asteptare();
																			else
																				// aprobare inregistrare-> intoarce v sau x
																				if (text[0] == "12")
																					P = new Protocol_aprobare_inregistrari(text[1]);
																				else
																					// respinge inregistrare-> intoarce v sau x                              
																					if (text[0] == "13")
																						P = new Protocol_Respinge_Inregistrare(text[1]);
																					else
																						//sterge utilizatorul <=> aprobarea stergerii+ stergerea directa de admin
																						if (text[0] == "14")
																							P = new Protocol_Stergere_Utilizator(text[1]);
																						else
																							// respingere cerere stergere utilizator -> intoarce v sau x
																							if (text[0] == "15")
																								P = new Protocol_Respingere_Inregistrare(text[1]);


								if (P->obtine_eroare() == 0) {
									P->rezultat();
									clienti[k]->send(P->obtine_raspuns().c_str(), P->obtine_raspuns().length() + 1);
								}
								else {
									//Tratare erori aparute.
								}
								delete P;
						}
					}
				}
			}
		}
	}
	for (std::vector<sf::TcpSocket*>::iterator it = clienti.begin(); it != clienti.end(); it++)
		delete* it;
}

void Conexiune::creeaza_conezxiune()
{
	listener.listen(2000); //se conecteaza la portul 2001
	selector.add(listener);
}
