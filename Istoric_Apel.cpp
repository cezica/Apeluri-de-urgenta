#include "Istoric_Apel.h"

void Istoric_Apel::citeste_istoric()
{
    Fisiere* F = new Fisiere("Istoric apeluri.txt");
    vector < vector<string>> date = F->obtine_date();
    for (int i = 0; i < date.size(); i++)
    {
        Apel A(date[i][0], date[i][1], date[i][2], date[i][3], date[i][4]);
        Apeluri.push_back(A);
    }
    delete F;

}

string Istoric_Apel::obtine_rezultat()
{
    return rezultat;
}

void Istoric_Apel::insert_apel(Apel&A)
{
    Apeluri.push_back(A);
    A.seteaza_inserat();
    
    vector <string> aux;
    aux.push_back(A.obtine_nume_client());
    aux.push_back(A.obtine_nume_dispecer());
    aux.push_back(A.obtine_date_inceput_apel());
    aux.push_back(A.obtine_date_sfarsit_apel());
    aux.push_back(A.obtine_nume_fisier());

    Fisiere* F = new Fisiere("Istoric apeluri.txt");
    F->insert_Inregistrare(aux);
    
    vector <string> aux1;
    aux1.push_back(A.obtine_date_inceput_apel());
    aux1.push_back(A.obtine_date_sfarsit_apel());
    aux1.push_back(A.obtine_nume_fisier());
   
    Fisiere* G = new Fisiere(A.obtine_nume_client()+".txt");
    G->insert_Inregistrare(aux1);

    if (A.obtine_inserat())
        A.seteaza__rezultat("v");
    else
        A.seteaza__rezultat("x");
   
    delete F;
    delete G;

}

void Istoric_Apel::istoric_apeluri_admin()
{
    
    citeste_istoric();
    for(int i=0;i<Apeluri.size();i++)
        rezultat = rezultat + Apeluri[i].obtine_nume_client() + '$'+ Apeluri[i].obtine_nume_dispecer() + '$' + Apeluri[i].obtine_nume_fisier() + '$'+'*';
}

void Istoric_Apel::istoric_apeluri_client(string username)
{
    Fisiere* F = new Fisiere(username+".txt");
    if (F->exista == false)
        rezultat = "NU EXISTA ACEST UTILIZATOR";
    else
    { 
        vector < vector<string>> date = F->obtine_date();
        if(date.size()>0)
        for (int i = 0; i < date.size(); i++)
            rezultat = rezultat + date[i][0] + '$' + date[i][1] + '$' + date[i][2] + '$' + '*';
    }
    delete F;

}

void Istoric_Apel::istoric_apeluri_dispecer(string dispecer)
{
    Fisiere* F = new Fisiere(dispecer + ".txt");
    if (F->exista == false)
        rezultat = "NU EXISTA ACEST DISPECER";
    else
    {
        vector < vector<string>> date = F->obtine_date();
        if (date.size() > 0)
            for (int i = 0; i < date.size(); i++)
                rezultat = rezultat + date[i][0] + '$' + date[i][1] + '$' + '*';
    }
    delete F;
}

void Istoric_Apel::istoric_apeluri_dispecer_cu_detalii(string dispecer)
{
    Fisiere* F = new Fisiere("Istoric apeluri.txt");
    if (F->exista == false)
        rezultat = "NU EXISTA ACEST DISPECER";
    else
    {
        vector < vector<string>> date = F->obtine_date();
        if (date.size() > 0)
            for (int i = 0; i < date.size(); i++)
                if(date[i][1]==dispecer)
                rezultat = rezultat + date[i][0] + '$' + date[i][2]+ ' ' + date[i][3]+'$' + date[i][5]+'$'+date[i][4]+'$'+'*';
    }
    delete F;
}

void Istoric_Apel::istoric_apeluri_pt_dispecer()
{
    Fisiere* F = new Fisiere("Înregistrari_Utilizatori.txt");
  
    vector < vector<string>> date = F->obtine_date();
    if (date.size() > 0)
        for (int i = 0; i < date.size(); i++)
            rezultat = rezultat + date[i][0] + '$' + date[i][2] + '$' + date[i][3]+'$'+date[i][4]+'$'+'*';
 
    delete F;
}
