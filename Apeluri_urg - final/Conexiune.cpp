#include "Conexiune.h"
Conexiune* Conexiune::singleton_ = nullptr;;

Conexiune* Conexiune::getinstance(const std::string& value)
{
    if (singleton_ == nullptr) {
        singleton_ = new Conexiune(value);
    }
    return singleton_;
}

void Conexiune::trimite_cerere(std::string text)
{
	this->socket.send(text.c_str(), text.length() + 1);
}

std::string Conexiune::obtine_raspuns()
{
    this->socket.receive(this->buffer, sizeof(this->buffer), received);
    if (received > 0)
        std::cout << buffer << std::endl;
    std::string return_string;
    for (int i = 0; i < received - 1; i++)
        return_string += buffer[i];
    return return_string;
}

Conexiune::Conexiune()
{
    //de adaugat de la Elena
    this->ip = sf::IpAddress::getLocalAddress();
    char buffer[2000];
    std::string text = "Connected to Client";
    this->socket.connect(ip, 2000);
    std::cout << text << std::endl;
}

Conexiune::~Conexiune()
{
}
