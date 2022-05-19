#pragma once
#include "Protocol.h"
#include"Apel.h"
#include"Istoric_Apel.h"
class Protocol_Adauga_detalii_la_apel :
    public Protocol
{
private:
    Istoric_Apel* IA;
public:
   void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Adauga_detalii_la_apel(string nr_linie, string detalii);
    ~Protocol_Adauga_detalii_la_apel();
};

