#pragma once
#include "Protocol.h"
class Protocol_Respingere_Inregistrare :
    public Protocol
{
private:

public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Respingere_Inregistrare(string username);
    ~Protocol_Respingere_Inregistrare();
};

