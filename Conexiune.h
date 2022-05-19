#pragma once
#include <SFML/Network.hpp>
#include <iostream>
#include "Exceptie.h"

#include "Protocol_Logare.h"
#include "Protocol_Inregistrare.h"
#include "Protocol_Istoric_Apel.h"
#include "Protocol_Istoric_Apel_Clienti.h"
#include "Protocol_Istoric_Dispecer_fara_detalii.h"
#include "Protocol_Adauga_detalii_la_apel.h"
#include "Protocol_Istoric_Apeluri_Dispecer.h"
#include "Protocol_afisarea_utilizatorilor.h"
#include "Protocol_Istoric_apeluri.h"
#include "Protocol_Sterge_Dispecer.h"
#include "Protocol_Adauga_Dispecer.h"
#include "Protocol_Lista_Inregistrari_Asteptare.h"
#include "Protocol_aprobare_inregistrari.h"
#include "Protocol_Respinge_Inregistrare.h"
#include "Protocol_Stergere_Utilizator.h"
#include "Protocol_Respingere_Inregistrare.h"

using namespace std;

#define delimitator '$'

class Conexiune
{
private:
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	char buffer[2000];//in ce primesc mesaj de la client
	size_t received;//dimensiune cat primesc
	sf::TcpListener listener;//client
	sf::SocketSelector selector;
	vector<sf::TcpSocket*> clienti;

public:
	void start_comunicare();
	void creeaza_conezxiune();

	Conexiune() {};
	~Conexiune() {};
};