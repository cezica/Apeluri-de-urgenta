#include "Protocol_Adauga_Dispecer.h"

void Protocol_Adauga_Dispecer::rezultat()
{
    this->raspuns = ID->obtine_rezultat();
}

string Protocol_Adauga_Dispecer::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Adauga_Dispecer::obtine_eroare()
{
    return this->eroare;
}

Protocol_Adauga_Dispecer::Protocol_Adauga_Dispecer(string username, string parola, string nume, string prenume, string email, string tip, string nr_telefon)
{
    ID = new ÎnregistrareDispecer(username, parola, nume, prenume, email, tip, nr_telefon);
}

Protocol_Adauga_Dispecer::~Protocol_Adauga_Dispecer()
{
    delete ID;
}
