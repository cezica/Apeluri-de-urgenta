#pragma once
#include "Protocol.h"
#include "Logare.h"

class Protocol_Logare :
    public Protocol
{
private:
    Logare* L;
public:
    void rezultat();
    string obtine_raspuns();

    int obtine_eroare();

    Protocol_Logare(string username, string parola);
    ~Protocol_Logare();
};