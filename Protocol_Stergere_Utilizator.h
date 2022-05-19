#pragma once
#include "Protocol.h"

class Protocol_Stergere_Utilizator :
    public Protocol
{
private:
    Fisiere* F;
    int n;
    Fisiere* G;
    int m;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Stergere_Utilizator(string username);
    ~Protocol_Stergere_Utilizator();
};

