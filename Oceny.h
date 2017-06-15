#ifndef _OCENY_H_
#define _OCENY_H_

#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <cctype>
#include <sstream>

using namespace std;
class Przedmiot_Szkolny;

istream & operator >>(istream & strumien, Przedmiot_Szkolny p);

class Przedmiot_Szkolny
{
    string nazwa_przedmiotu;
    vector<float>oceny_z_przedmiotu;

    void procedura_blednego_wczytania_oceny();
    float sprawdzenie_jaka_to_ocena(string ocena);

    friend istream & operator >>(istream & strumien, Przedmiot_Szkolny p);
public:

    void ustawNazwe(string nazwa);
    void dodajOcene(string ocena);
    float podajSrednia()const;
};

#endif // _OCENY_H_
