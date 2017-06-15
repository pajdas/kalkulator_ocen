#ifndef _OCENY_H_
#define _OCENY_H_

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <cctype>

using namespace std;
class Przedmiot_Szkolny;

istream & operator >>(istream & strumien, Przedmiot_Szkolny p);

class Przedmiot_Szkolny
{
    string nazwa_przedmiotu;
    vector<float>oceny_z_przedmiotu;

    bool poprawnosc_wczytanej_oceny();
    void procedura_blednego_wczytania_oceny();


    float sprawdzenie_jaka_to_ocena(string ocena)
    {
        const char * bufor = ocena.c_str();
        float liczba_zwrotna = 0;

        if(ispunct(bufor[0]))
        {
            cout<<"z przodu"<<endl;
        }
        else if(ispunct(bufor[ocena.size()-1]))
        {
            cout<<"na koncu"<<endl;
        }
        return liczba_zwrotna;
    }

    friend istream & operator >>(istream & strumien, Przedmiot_Szkolny p);
public:

    void ustawNazwe(string nazwa);
    void dodajOcene(string ocena);
    float podajSrednia()const;
};

#endif // _OCENY_H_
