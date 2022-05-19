#include "Protocol_Adauga_detalii_la_apel.h"

void Protocol_Adauga_detalii_la_apel::rezultat()
{
    this->raspuns = IA->obtine_rezultat();
}

string Protocol_Adauga_detalii_la_apel::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Adauga_detalii_la_apel::obtine_eroare()
{
    return this->eroare;
}

Protocol_Adauga_detalii_la_apel::Protocol_Adauga_detalii_la_apel(string nr_linie, string detalii)
{
    IA = new Istoric_Apel();
    IA->istoric_asteptare(nr_linie,detalii);
}

Protocol_Adauga_detalii_la_apel::~Protocol_Adauga_detalii_la_apel()
{
    delete IA;
}
