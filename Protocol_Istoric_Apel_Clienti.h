#pragma once
#include "Protocol.h"
#include "Istoric_Apel.h"
class Protocol_Istoric_Apel_Clienti :
    public Protocol
{
    Istoric_Apel* IA;
public:
    bool rezultat() {
        this->raspuns = IA->obtine_rezultat();
    }
    string get_raspuns() {
        return this->raspuns;
    }

    int get_eroare() { return this->eroare; };

    Protocol_Istoric_Apel_Clienti(string username) {
        IA = new Istoric_Apel();
        IA->istoric_apeluri_client(username);
    }
    ~Protocol_Istoric_Apel_Clienti() {
        delete IA;
    }
};

