#pragma once
#include "Protocol.h"
class Protocol_aprobare_inregistrari :
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

    Protocol_aprobare_inregistrari(string username);
    ~Protocol_aprobare_inregistrari();
};

