#include "CerereStergeri.h"

CerereStergeri::CerereStergeri()
{
}

string CerereStergeri::verificare()
{
    return string();
}

string CerereStergeri::lista_st()
{
    return B_D::create_Instance()->lista_stergeri();
}

bool CerereStergeri::cerere_stergere(string user_cl,string user_disp)
{
    return B_D::create_Instance()->cerere_stergere(user_cl, user_disp);
}
