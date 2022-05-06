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
	Conexiune();
	static Conexiune* getinstance(const std::string& value);
	std::string value() const {
		return value_;
	}

	void trimite_cerere(std::string text);
	std::string obtine_raspuns();

protected:
	Conexiune(const std::string value) : value_(value) {};
	static Conexiune* singleton_;

	std::string value_;
	~Conexiune();
};

