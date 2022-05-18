#pragma once
#include "Protocol.h"
#include "Logare.h"

class Protocol_Logare :
    public Protocol
{
private:
    Logare* L;
public:
    bool rezultat() {
        this->raspuns = L->obtine_rezultat();
    }
    string get_raspuns() {
        return this->raspuns;
    }

    int get_eroare() { return this->eroare; };

    Protocol_Logare(string username, string parola) {
        L = new Logare(username, parola);
    }
    ~Protocol_Logare() {
        delete L;
    }
};

