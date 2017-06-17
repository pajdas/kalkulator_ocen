#ifndef _INTERFACE_OCEN_H_
#define _INTERFACE_OCEN_H_

#include <iostream>
#include <string>
#include <vector>
#include "Oceny.h"

using namespace std;

struct TypOceny
{
    string nazwaTypu;
    float wartosc;
};

struct PrzedmiotSzkolny
{
    string nazwa_przedmiotu;
    vector<float>oceny;
};

class InterfaceOcen
{
    vector<PrzedmiotSzkolny>przedmioty;
    vector<TypOceny>rodzajOcen;

    void otworzListOcen();
    void otworzListePrzedmiotow();
    string rozpoznaj_ocene(string ocena);
public:
    void dodajPrzedmiot();
    void usunPrzedmiot();

    void wczytaj_rodzaje_ocen(string txt_file_adress);

    void dodajOcene();
    void usunOcene();

    void pokazOceny();


    void ustawNazwe(string nazwa);


    float podajSrednia()const;
    string podajNazwe()const;
};
#endif // _INTERFACE_OCEN_H_
