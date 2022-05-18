#pragma once
#include "Protocol.h"
#include "�nregistrare.h"
class Protocol_Inregistrare :
    public Protocol
{
private:
    �nregistrare* I;
public:
    bool rezultat() {
        this->raspuns = I->obtine_rezultat();
    }
    string get_raspuns() {
        return this->raspuns;
    }

    int get_eroare() { return this->eroare; };

    Protocol_Inregistrare(string username, string parola, string nume, string prenume, string email, string nr_telefon) {
        I = new �nregistrare(username, parola, nume, prenume, email, nr_telefon);
    }
    ~Protocol_Inregistrare() {
        delete I;
    }
};

