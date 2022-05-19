#pragma once
#include "Protocol.h"
#include "Istoric_Apel.h"
class Protocol_Istoric_Apel_Clienti :
    public Protocol
{
private:
    Istoric_Apel* IA;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Istoric_Apel_Clienti(string username);
    ~Protocol_Istoric_Apel_Clienti();
};

