#pragma once
#include "Protocol.h"
#include "Înregistrare.h"
class Protocol_Inregistrare :
    public Protocol
{
private:
    Înregistrare* I;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Inregistrare(string username, string parola, string nume, string prenume, string email, string nr_telefon);
    ~Protocol_Inregistrare();
};

