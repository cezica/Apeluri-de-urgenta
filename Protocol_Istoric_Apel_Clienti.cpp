#include "Protocol_Istoric_Apel_Clienti.h"

void Protocol_Istoric_Apel_Clienti::rezultat()
{
    this->raspuns = IA->obtine_rezultat();
}

string Protocol_Istoric_Apel_Clienti::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Istoric_Apel_Clienti::obtine_eroare()
{
    return this->eroare;
}

Protocol_Istoric_Apel_Clienti::Protocol_Istoric_Apel_Clienti(string username)
{
    IA = new Istoric_Apel();
    IA->istoric_apeluri_client(username);
}

Protocol_Istoric_Apel_Clienti::~Protocol_Istoric_Apel_Clienti()
{
    delete IA;
}
