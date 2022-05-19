#include "Protocol_Inregistrare.h"

void Protocol_Inregistrare::rezultat()
{
    this->raspuns = I->obtine_rezultat();
}

string Protocol_Inregistrare::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Inregistrare::obtine_eroare()
{
    return this->eroare;
}

Protocol_Inregistrare::Protocol_Inregistrare(string username, string parola, string nume, string prenume, string email, string nr_telefon)
{
    I = new Înregistrare(username, parola, nume, prenume, email, nr_telefon);
}

Protocol_Inregistrare::~Protocol_Inregistrare()
{
    delete I;
}
