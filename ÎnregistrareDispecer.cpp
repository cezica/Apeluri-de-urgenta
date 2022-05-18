#include "ĪnregistrareDispecer.h"

bool ĪnregistrareDispecer::acelasi_username() //verific daca se repeta usernamul
{
    Fisiere* F = new Fisiere("Īnregistrari_Dispeceri.txt");
    vector<int> indecsi = F->select_Inregistrare("username", username);
    for (int i = 0; i < indecsi.size(); i++)
    {
        if (F->intoarce_inregistrare(indecsi[i])[1] == username)
        {
            delete F;
            cout << "Username existent!" << endl;
            return true;
        }
    }
    delete F;
    return false;
}

bool ĪnregistrareDispecer::acelasi_individ() //verific nr de telefon
{
    Fisiere* F = new Fisiere("Īnregistrari_Dispeceri.txt");
    vector<int> indecsi = F->select_Inregistrare("telefon", numar_telefon);
    for (int i = 0; i < indecsi.size(); i++)
    {
        if (F->intoarce_inregistrare(indecsi[i])[6] == numar_telefon)
        {
            delete F;
            return true;
        }
    }
    delete F;
    return false;
}

string ĪnregistrareDispecer::obtine_rezultat()
{
    return rezultat;
}

void ĪnregistrareDispecer::sterge_dispecer(string nume)
{
    Fisiere* F = new Fisiere("Īnregistrari_Dispeceri.txt");
    vector<int> indecsi = F->select_Inregistrare("username", nume);
    for (int i = 0; i < indecsi.size(); i++)
    {
        if (F->intoarce_inregistrare(indecsi[i])[0] == nume)
        {
            F->delete_Inregistrare(nume);
            rezultat = 'v';
        }
        else
            rezultat = 'x';
        delete F;
    }
}
