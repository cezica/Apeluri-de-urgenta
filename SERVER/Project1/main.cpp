#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Gestionare.h"

int main()
{
	//baza.conec();	

	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char mode;
	char buffer[2000];
	std::size_t received;
	std::string text = "Connected to Server ";
	char connectionType = 's';
	string trimite;

	sf::TcpListener listener;
	listener.listen(1906); //se conecteaza la portul 1906
	listener.accept(socket);	//asteapta un "Client" sa se conecteze la socket
	socket.setBlocking(false);

	std::cout << text << std::endl;

	bool done = false;

	while (!done)
	{
		socket.receive(buffer, sizeof(buffer), received);
		if (received > 0)
		{
			std::vector<std::string>sir;
			std::string value;
			for (int i = 0; i <= strlen(buffer); i++)
			{
				if (buffer[i] == ';' || buffer[i] == '\0')
				{
					sir.push_back(value);
					value = "";
					i++;
				}
				value += buffer[i];
			}

			cout << "Primit: " << buffer << endl;

			memset(buffer, 0, sizeof(buffer));

			Gestionare g;
			trimite = g.cerere(sir[0]);
			socket.send(trimite.c_str(), trimite.length() + 1);
		}
		
	}
	return 0;
}