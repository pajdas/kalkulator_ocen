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
    cout<<"ndst, dop, dst, db, bdb, cel\noraz znaki \"-\" i \"+\" po obu stronach"<<endl;
    cin>>*this;
}

float Przedmiot_Szkolny::sprawdzenie_jaka_to_ocena(string ocena)
{
    const char * bufor = ocena.c_str();
    float liczba_zwrotna = 0;

    stringstream stream;

    switch(ocena.size())
    {
    case 1:
        stream<<ocena;
        stream>>liczba_zwrotna;
        if(liczba_zwrotna>6 || liczba_zwrotna<1)
        {
            procedura_blednego_wczytania_oceny();
        }
        break;
    case 2:
        if(ocena == "db")
        {
            liczba_zwrotna = 4;
            return liczba_zwrotna;
        }

        if(ispunct(bufor[0]))
        {
            cout<<"z przodu"<<endl;
            float wspolczynnik = 0;
            if(bufor[0]=='-')
            {
                wspolczynnik = -0.25;
            }
            else if(bufor[0]=='+')
            {
                wspolczynnik = 0.5;
            }
            else{procedura_blednego_wczytania_oceny();}
            stringstream stream;
            stream<<ocena[1];
            stream>>liczba_zwrotna;
            liczba_zwrotna+=wspolczynnik;
            if(liczba_zwrotna>6 || liczba_zwrotna<1)
            {
                procedura_blednego_wczytania_oceny();
            }
            break;
        }
        else if(ispunct(bufor[1]))
        {
            cout<<"na koncu"<<endl;
            float wspolczynnik = 0;
            if(bufor[1]=='-')
            {
                wspolczynnik = -0.25;
            }
            else if(bufor[1]=='+')
            {
                wspolczynnik = 0.5;
            }
            else{procedura_blednego_wczytania_oceny();}

            stream<<ocena[0];
            stream>>liczba_zwrotna;
            liczba_zwrotna+=wspolczynnik;
            if(liczba_zwrotna>6 || liczba_zwrotna<1)
            {
                procedura_blednego_wczytania_oceny();
            }
            break;
        }
        else{procedura_blednego_wczytania_oceny();}
        break;
    case 3:
        if(ispunct(bufor[0]))
        {
            string buf;
            buf.insert(0,ocena,1,2);
            if(buf=="db")
            {
                if(bufor[0]=='-')
                {
                    liczba_zwrotna = 3.75;
                }
                else if(bufor[0]=='+')
                {
                    liczba_zwrotna = 4.5;
                }
                else{procedura_blednego_wczytania_oceny();}
            }
            else{procedura_blednego_wczytania_oceny();}
            return liczba_zwrotna;
            break;
        }
        else if(ispunct(bufor[2]))
        {
            string buf;
            buf.insert(0,ocena,0,2);
            if(buf=="db")
            {
                if(bufor[2]=='-')
                {
                    liczba_zwrotna = 3.75;
                }
                else if(bufor[2]=='+')
                {
                    liczba_zwrotna = 4.5;
                }
                else{procedura_blednego_wczytania_oceny();}
            }
            else{procedura_blednego_wczytania_oceny();}
            break;
        }
        if(ocena=="dop")
        {
            liczba_zwrotna = 2;
            return liczba_zwrotna;
        }
        else if(ocena=="dst")
        {
            liczba_zwrotna = 3;
            return liczba_zwrotna;
        }
        else if(ocena=="bdb")
        {
            liczba_zwrotna = 5;
            return liczba_zwrotna;
        }
        else if(ocena=="cel")
        {
            liczba_zwrotna = 6;
            return liczba_zwrotna;
        }
        else{procedura_blednego_wczytania_oceny();}
        break;
    case 4:
        if(ocena == "ndst")
        {
            liczba_zwrotna = 1;
            return liczba_zwrotna;
            break;
        }
        if(ispunct(bufor[0]))
        {
            cout<<"znak z przodu"<<endl;

            float wspolczynnik = 0;
            if(bufor[0]=='-')
            {
                wspolczynnik = -0.25;
            }
            else if(bufor[0]=='+')
            {
                wspolczynnik = 0.5;
            }

            string buf;
            buf.insert(0,ocena,1,3);
            if(buf=="dop")
            {
                liczba_zwrotna = 2;
            }
            else if(buf=="dst")
            {
                liczba_zwrotna = 3;
            }
            else if(buf=="bdb")
            {
                liczba_zwrotna = 5;
            }
            else if(buf=="cel")
            {
                liczba_zwrotna = 6;
            }
            else{procedura_blednego_wczytania_oceny();}
            liczba_zwrotna+=wspolczynnik;
            if(liczba_zwrotna>6 || liczba_zwrotna<1)
            {
                procedura_blednego_wczytania_oceny();
            }
            else{return liczba_zwrotna;}

        }
        else if(ispunct(bufor[3]))
        {
            cout<<"znak z tylu"<<endl;

            float wspolczynnik = 0;
            if(bufor[3]=='-')
            {
                wspolczynnik = -0.25;
            }
            else if(bufor[3]=='+')
            {
                wspolczynnik = 0.5;
            }

            string buf;
            buf.insert(0,ocena,0,3);
            if(buf=="dop")
            {
                liczba_zwrotna = 2;
            }
            else if(buf=="dst")
            {
                liczba_zwrotna = 3;
            }
            else if(buf=="bdb")
            {
                liczba_zwrotna = 5;
            }
            else if(buf=="cel")
            {
                liczba_zwrotna = 6;
            }
            else{procedura_blednego_wczytania_oceny();}
            liczba_zwrotna+=wspolczynnik;
            if(liczba_zwrotna>6 || liczba_zwrotna<1)
            {
                procedura_blednego_wczytania_oceny();
            }
            else{return liczba_zwrotna;}
        }
        break;
    case 5:
        if(ocena=="+ndst"||ocena=="ndst+")
        {
            liczba_zwrotna == 1.5;
        }
        else{
            procedura_blednego_wczytania_oceny();
        }
        return liczba_zwrotna;
        break;
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
