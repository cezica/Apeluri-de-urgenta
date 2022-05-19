#pragma once
#include "Protocol.h"
#include "Apel.h"
#include "Istoric_Apel.h"
class Protocol_Istoric_Apel :
    public Protocol
{
private:
    Apel* A;
    Istoric_Apel* IA;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Istoric_Apel(string nume_client, string nume_dispecer, string date_inceput_apel, string date_sfarsit_apel, string nume_fisier);
    ~Protocol_Istoric_Apel();
};

