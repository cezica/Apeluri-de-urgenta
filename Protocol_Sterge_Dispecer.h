#pragma once
#include "Protocol.h"
#include "ĪnregistrareDispecer.h"

class Protocol_Sterge_Dispecer :
    public Protocol
{
private:
    ĪnregistrareDispecer* ID;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Sterge_Dispecer(string username_dispecer);
    ~Protocol_Sterge_Dispecer();
};

