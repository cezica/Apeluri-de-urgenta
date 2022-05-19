#pragma once
#include "Protocol.h"
#include "Istoric_Apel.h"
class Protocol_Istoric_Dispecer_fara_detalii :
    public Protocol
{
private:
    Istoric_Apel* IA;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Istoric_Dispecer_fara_detalii(string username);
    ~Protocol_Istoric_Dispecer_fara_detalii();
};

