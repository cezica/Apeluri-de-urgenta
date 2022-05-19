#include "Protocol_Istoric_Dispecer_fara_detalii.h"

void Protocol_Istoric_Dispecer_fara_detalii::rezultat()
{
    this->raspuns = IA->obtine_rezultat();
}

string Protocol_Istoric_Dispecer_fara_detalii::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Istoric_Dispecer_fara_detalii::obtine_eroare()
{
    return this->eroare;
}

Protocol_Istoric_Dispecer_fara_detalii::Protocol_Istoric_Dispecer_fara_detalii(string username)
{
    IA = new Istoric_Apel();
    IA->istoric_apeluri_dispecer(username);
}

Protocol_Istoric_Dispecer_fara_detalii::~Protocol_Istoric_Dispecer_fara_detalii()
{
    delete IA;
}
