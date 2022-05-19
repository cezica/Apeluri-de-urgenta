#include "Protocol_Logare.h"

void Protocol_Logare::rezultat()
{
   this->raspuns = L->obtine_rezultat();
}

string Protocol_Logare::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Logare::obtine_eroare()
{
    return this->eroare;
}

Protocol_Logare::Protocol_Logare(string username, string parola)
{
    L = new Logare(username, parola);
}

Protocol_Logare::~Protocol_Logare()
{
    delete L;
}
