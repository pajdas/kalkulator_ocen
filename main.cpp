#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Oceny.h"
#include "Wyszukiwarka.h"
#include "Interface_Ocen.h"
using namespace std;



/// ////////////////////////////////////////////////////////////////////////////////////// main ///
int main()
{
    InterfaceOcen interface;
    interface.wczytaj_rodzaje_ocen("tekst.txt");
    interface.dodajPrzedmiot();
    interface.dodajOcene();
    interface.pokazOceny();
    return 0;
}


