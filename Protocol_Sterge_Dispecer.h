#pragma once
#include "Protocol.h"
#include "�nregistrareDispecer.h"

class Protocol_Sterge_Dispecer :
    public Protocol
{
private:
    �nregistrareDispecer* ID;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Sterge_Dispecer(string username_dispecer);
    ~Protocol_Sterge_Dispecer();
};

