#include "Protocol_Istoric_apeluri.h"

void Protocol_Istoric_apeluri::rezultat()
{
    this->raspuns = IA->obtine_rezultat();
}

string Protocol_Istoric_apeluri::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Istoric_apeluri::obtine_eroare()
{
    return this->eroare;
}

Protocol_Istoric_apeluri::Protocol_Istoric_apeluri()
{
    IA = new Istoric_Apel();
    IA->istoric_apeluri_admin();
}

Protocol_Istoric_apeluri::~Protocol_Istoric_apeluri()
{
    delete IA;
}
