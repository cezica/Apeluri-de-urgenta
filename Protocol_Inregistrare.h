#pragma once
#include "Protocol.h"
#include "�nregistrare.h"
class Protocol_Inregistrare :
    public Protocol
{
private:
    �nregistrare* I;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Inregistrare(string username, string parola, string nume, string prenume, string email, string nr_telefon);
    ~Protocol_Inregistrare();
};

