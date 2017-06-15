#include <iostream>
#include <vector>
#include "Oceny.h"

using namespace std;

istream & operator >>(istream & strumien, Przedmiot_Szkolny p)
{
    string bufor;
    strumien >> bufor;
    p.dodajOcene(bufor);
    return strumien;
}

/// metody prywatne kasy Przedmiot_Szkolny ///
void Przedmiot_Szkolny::procedura_blednego_wczytania_oceny()
{
    cout<<"Ocena ktora wpisales nie zostala rozpoznana lub przekroczyla zakres: "<<endl;
    cout<<"Oceny ktore rozumiem to:\n1, 2, 3, 4, 5, 6"<<endl;
    cout<<"ndst, dop, dst,db, bdb, cel\noraz znaki '-' i '+' po obu stronach"<<endl;
    cin>>*this;
}

float Przedmiot_Szkolny::sprawdzenie_jaka_to_ocena(string ocena)
{
    const char * bufor = ocena.c_str();
    float liczba_zwrotna = 0;
    if(ocena.size()==1)
    {
        stringstream stream;
        stream<<ocena;
        stream>>liczba_zwrotna;
        if(liczba_zwrotna>6 || liczba_zwrotna<1)
        {
            procedura_blednego_wczytania_oceny();
        }
    }
    if(ispunct(bufor[0]))
    {
        cout<<"z przodu"<<endl;
        if(isalpha(bufor[2]))
        {

        }
    }
    else if(ispunct(bufor[ocena.size()-1]))
    {
        cout<<"na koncu"<<endl;
    }
    return liczba_zwrotna;
}

/// metody publiczne klasy Przedmiot_Szkolny ///
void Przedmiot_Szkolny::ustawNazwe(string nazwa)
{
    nazwa_przedmiotu = nazwa;
}

void Przedmiot_Szkolny::dodajOcene(string ocena)
{
    float bufor = sprawdzenie_jaka_to_ocena(ocena);
    cout<<"bufor to "<<bufor<<endl;
    oceny_z_przedmiotu.push_back(bufor);
}

float Przedmiot_Szkolny::podajSrednia()const
{
    float bufor = 0;
    for(int i=0; i<oceny_z_przedmiotu.size(); i++)
    {
        bufor+=oceny_z_przedmiotu[i];
    }
    return bufor;
}
