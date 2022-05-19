#pragma once
#include "Protocol.h"
#include "ÎnregistrareDispecer.h"

class Protocol_Adauga_Dispecer :
    public Protocol
{
private:
    ÎnregistrareDispecer* ID;
public:
  void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_Adauga_Dispecer(string username, string parola, string nume, string prenume, string email, string tip, string nr_telefon);
    ~Protocol_Adauga_Dispecer();
};

