#pragma once
#include "IProtocol.h"
class Protocol :
    public IProtocol
{
protected:
    string raspuns;
    int eroare = 0;
public:
    int get_eroare() override { return eroare; };
    bool rezultat() override {};
    string get_raspuns() override {};
};

