#include "Protocol_afisarea_utilizatorilor.h"

void Protocol_afisarea_utilizatorilor::rezultat()
{
    this->raspuns = IA->obtine_rezultat();
}

string Protocol_afisarea_utilizatorilor::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_afisarea_utilizatorilor::obtine_eroare()
{
    return this->eroare;
}

Protocol_afisarea_utilizatorilor::Protocol_afisarea_utilizatorilor()
{
    IA = new Istoric_Apel();
    IA->istoric_apeluri_pt_dispecer();
}

Protocol_afisarea_utilizatorilor::~Protocol_afisarea_utilizatorilor()
{
    delete IA;
}
