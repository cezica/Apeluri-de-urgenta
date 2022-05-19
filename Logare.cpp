#include "Logare.h"

bool Logare::date_corecte()
{
    Fisiere* F=new Fisiere("Username+parola.txt");
    vector<int> indecsi=F->select_Inregistrare("username", username);
    for (int i = 0; i < indecsi.size(); i++)
    {
        if (F->intoarce_inregistrare(indecsi[i])[1] == parola)
            delete F;
            return true;
    }
    delete F;
    return false;
}

string Logare::obtine_rezultat()
{
    return rezultat;
}
