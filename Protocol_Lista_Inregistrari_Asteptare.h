#pragma once
#include "Protocol.h"
#include"Istoric_Apel.h"
class Protocol_Lista_Inregistrari_Asteptare :
    public Protocol
{
private:
    Istoric_Apel* IA;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Lista_Inregistrari_Asteptare();
    ~Protocol_Lista_Inregistrari_Asteptare();
};

