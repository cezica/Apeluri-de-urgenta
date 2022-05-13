#pragma once
#include <SFML/Network.hpp>
#include"Logare.h"
#include "Īnregistrare.h"
#include "ĪnregistrareDispecer.h"
#include"Istoric_Apel.h"
#include <iostream>


using namespace std;

#define delimitator '$'

class Conexiune
{
private:
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char buffer[2000];//in ce primesc mesaj de la client
	size_t received;//dimensiune cat primesc
	sf::TcpListener listener;//client

	void trimite_raspuns(string raspuns)
	{
		socket.send(raspuns.c_str(), raspuns.length() + 1);
	}
public:
	void creaza_conexiune();
	void start_comunicare();

	Conexiune() {};
	~Conexiune() {};
};

