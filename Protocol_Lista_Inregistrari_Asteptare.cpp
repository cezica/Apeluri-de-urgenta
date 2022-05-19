#include "Protocol_Lista_Inregistrari_Asteptare.h"

void Protocol_Lista_Inregistrari_Asteptare::rezultat()
{
    this->raspuns = IA->obtine_rezultat();
}

string Protocol_Lista_Inregistrari_Asteptare::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Lista_Inregistrari_Asteptare::obtine_eroare()
{
    return this->eroare;
}

Protocol_Lista_Inregistrari_Asteptare::Protocol_Lista_Inregistrari_Asteptare()
{
    IA = new Istoric_Apel();
    IA->istoric_inregistrari();
}

Protocol_Lista_Inregistrari_Asteptare::~Protocol_Lista_Inregistrari_Asteptare()
{
    delete IA;
}
