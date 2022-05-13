#pragma once
#include <iostream>
#include <SFML/Network.hpp>
class Conexiune
{
private:
	sf::IpAddress ip;
	sf::TcpSocket socket;
	std::size_t received;
	char buffer[2000];
	std::string data;

public:
	Conexiune(Conexiune& other) = delete;
	static Conexiune* getinstance();

	void trimite_cerere(std::string text);
	std::string obtine_raspuns();

protected:
	Conexiune();
	static Conexiune* singleton_;

	~Conexiune();
};

