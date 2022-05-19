#include "Protocol_Sterge_Dispecer.h"

void Protocol_Sterge_Dispecer::rezultat()
{
    this->raspuns = ID->obtine_rezultat();
}

string Protocol_Sterge_Dispecer::obtine_raspuns()
{
    return this->raspuns;
}

int Protocol_Sterge_Dispecer::obtine_eroare()
{
    return this->eroare;
}

Protocol_Sterge_Dispecer::Protocol_Sterge_Dispecer(string username_dispecer)
{
    ID = new ÎnregistrareDispecer;
    ID->sterge_dispecer(username_dispecer);
}

Protocol_Sterge_Dispecer::~Protocol_Sterge_Dispecer()
{
    delete ID;
}
