#pragma once
#include "IProtocol.h"
class Protocol :
    public IProtocol
{
protected:
    string raspuns;
    int eroare = 0;
public:
   virtual int obtine_eroare() = 0;
   virtual void rezultat() = 0;
   virtual string obtine_raspuns() = 0;
};

