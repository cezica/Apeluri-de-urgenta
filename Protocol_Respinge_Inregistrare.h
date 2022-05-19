#pragma once
#include "Protocol.h"

class Protocol_Respinge_Inregistrare :
    public Protocol
{
private:
    Fisiere* F;
    int n;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Respinge_Inregistrare(string username);
    ~Protocol_Respinge_Inregistrare();
};

