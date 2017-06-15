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

bool Przedmiot_Szkolny::poprawnosc_wczytanej_oceny()
{

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