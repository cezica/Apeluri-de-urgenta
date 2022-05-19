#include "Īnregistrare.h"
#include"Exceptie.h"

bool Īnregistrare::acelasi_username() //verific daca se repeta usernamul
{
    Fisiere* F=new Fisiere("Īnregistrari_Utilizatori.txt");
    vector<int> indecsi = F->select_Inregistrare("username", username);
    for (int i = 0; i < indecsi.size(); i++)
    {
        if (F->intoarce_inregistrare(indecsi[i])[0] == username)
        {
            delete F;
            throw new Exceptie(3);

        }
    }
    delete F;
    return false;
}

bool Īnregistrare::acelasi_individ() //verific nr de telefon
{
    Fisiere* F = new Fisiere("Īnregistrari_Utilizatori.txt");
    F->seteaza_update_false();
    vector<int> indecsi = F->select_Inregistrare("telefon", numar_telefon);
    for (int i = 0; i < indecsi.size(); i++)
    {
        if (F->intoarce_inregistrare(indecsi[i])[5] == numar_telefon)
        {
            delete F;
            throw new Exceptie(4);
        }
    }
    delete F;
    return false;
}

string Īnregistrare::obtine_rezultat()
{
    return rezultat;
}

void Īnregistrare::seteaza_aprobat()
{
    aprobat = true;
}
