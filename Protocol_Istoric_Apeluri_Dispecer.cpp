#include "Protocol_Istoric_Apeluri_Dispecer.h"

void Protocol_Istoric_Apeluri_Dispecer::rezultat()
{
    this->raspuns = IA->obtine_rezultat();
}

string Protocol_Istoric_Apeluri_Dispecer::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Istoric_Apeluri_Dispecer::obtine_eroare()
{
    return this->eroare;
}

Protocol_Istoric_Apeluri_Dispecer::Protocol_Istoric_Apeluri_Dispecer(string user_dispecer)
{
    IA= new Istoric_Apel();
    IA->istoric_apeluri_dispecer_cu_detalii(user_dispecer);
}

Protocol_Istoric_Apeluri_Dispecer::~Protocol_Istoric_Apeluri_Dispecer()
{
    delete IA;
}
