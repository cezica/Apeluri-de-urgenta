#pragma once
#include "Protocol.h"
#include "Istoric_Apel.h"

class Protocol_afisarea_utilizatorilor :
    public Protocol
{
private:
    Istoric_Apel* IA;
public:
    void rezultat();
    string obtine_raspuns();
    int obtine_eroare();

    Protocol_afisarea_utilizatorilor();
    ~Protocol_afisarea_utilizatorilor();
};

