#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Interface_Ocen.h"

using namespace std;

/// funkcje obslugujace oceny ///

string InterfaceOcen::rozpoznaj_ocene(string ocena)
{
    int no_error_counter = 0;
    float liczba;
    stringstream wartosc_zwracana;
    for(int i=0; i<rodzajOcen.size(); i++)
    {
        if(ocena==rodzajOcen[i].nazwaTypu)
        {
            liczba=rodzajOcen[i].wartosc;
            wartosc_zwracana<<liczba;
            no_error_counter++;
            break;
        }
    }
    if(no_error_counter>0)
    {
        return wartosc_zwracana.str();
    }
    else{return "error";}
}

void InterfaceOcen::wczytaj_rodzaje_ocen(string txt_file_adress)
{
    fstream plik;
    plik.open(txt_file_adress.c_str());
    while(!plik.eof())
    {
        TypOceny t;
        plik>>t.nazwaTypu;
        plik>>t.wartosc;
        rodzajOcen.push_back(t);
    }

    plik.close();
}

void InterfaceOcen::dodajOcene()
{
    otworzListePrzedmiotow();
    cout<<"Wybierz do jakiego przedmiotu chcesz dodac ocene"<<endl;
    int nr;
    do{
        cout<<"wcztuje"<<endl;
        cin>>nr;
    }while(nr < 0 || nr > przedmioty.size());

    cout<<"wczytalem - "<<nr<<endl;
    string ocena;
    string bufor;
    do{
        cout<<"Wybierz jaka ocene chesz dodac"<<endl;
        cin>>ocena;
        bufor = rozpoznaj_ocene(ocena);
    }while(bufor == "error");
    cout<<"wczytalem tresc - "<<ocena<<endl;
    cout<<"jest ona warta - "<<bufor<<endl;
    float f_zwracane = atof(bufor.c_str());
    cout<<"wczytalem ocene - "<<f_zwracane<<endl;
    przedmioty[nr].oceny.push_back(f_zwracane);
}

void InterfaceOcen::usunOcene()
{
    otworzListePrzedmiotow();
    int nr;
    while(!(nr >= 0&& nr <= przedmioty.size()))
    {
        cin>>nr;
    }
    przedmioty.erase(przedmioty.begin()+nr);
}

void InterfaceOcen::pokazOceny()
{
    otworzListePrzedmiotow();
}

/// funkcje obslugujace przedmioty ///
void InterfaceOcen::otworzListePrzedmiotow()
{
    for(int i=0; i<przedmioty.size(); i++)
    {
        cout<<"Przedmiot nr. "<<i<<" - "<<przedmioty[i].nazwa_przedmiotu<<endl;
    }
}

void InterfaceOcen::dodajPrzedmiot()
{
    cout<<"Otwarto funkcje dodajPrzedmiot - podaj nazwe przedmiotu: "<<endl;
    string bufor;
    cin >> bufor;
    PrzedmiotSzkolny p;
    p.nazwa_przedmiotu = bufor;
    przedmioty.push_back(p);
}

void InterfaceOcen::usunPrzedmiot()
{

}



