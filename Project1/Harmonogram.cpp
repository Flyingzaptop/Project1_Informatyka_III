#include <iostream>
#include "Harmonogram.h"
using namespace std;

Harmonogram::Harmonogram() { // konstruktor standartowy. Max rozmiar, czyli max ilosc elementów clasy Czas wynosi 10 (mozna zmienic)
    rozmiar = 10;
    ile = 0;
    czasy = new Czas[rozmiar]; //tworzymy liste z zadanym rozmiarem.
}

Harmonogram::Harmonogram(const Harmonogram& h) {// tworzymy nowy obiek Harmonogram, kopiując dane z innego
    rozmiar = h.rozmiar;
    ile = h.ile;
    czasy = new Czas[rozmiar];
    for (int i = 0; i < ile; i++) {
        czasy[i] = h.czasy[i];
    }
}

Harmonogram& Harmonogram::operator=(const Harmonogram& h) {// zmieniamy istniajacy
    if (this != &h) {
        delete[] czasy;
        rozmiar = h.rozmiar;
        ile = h.ile;
        czasy = new Czas[rozmiar];
        for (int i = 0; i < ile; i++) {
            czasy[i] = h.czasy[i];
        }
    }
    return *this;
}

Harmonogram::~Harmonogram() {//wiadomo :)
    delete[] czasy;
}

void Harmonogram::dodajCzas(Czas c) {//dodaje nowy obiekt tyou Czas do listy, czyli do obiektu Harmonogram,
    //ale sprawdzamy czy jest miejsce;
    if (ile >= rozmiar) {
        Czas* nowe = new Czas[rozmiar + 5];
        for (int i = 0; i < ile; i++) {
            nowe[i] = czasy[i];
        }
        delete[] czasy;
        czasy = nowe;
        rozmiar += 5;
    }
    czasy[ile] = c;
    ile++;
}

int Harmonogram::getIle() { return ile; }//zwracamy aktualną ilosc elementów.

Czas& Harmonogram::operator[](int i) {// dziekie temu mozemy wlasnie interpytowac Hormonogram jako lista 
    //oraz działac na poszczegolnych elementach
    return czasy[i];
}

void Harmonogram::wypisz() {//wypisujemy wszystkie elementy w Harmonogram
    for (int i = 0; i < ile; i++) {
        cout << "Task " << (i + 1) << " - " << czasy[i].getGodziny() << ":"
            << czasy[i].getMinuty() << ":" << czasy[i].getSekundy() << endl;
    }
}

Czas Harmonogram::suma() {//sumujemy znaczenia w Harmonogram
    Czas wynik;
    for (int i = 0; i < ile; i++) {
        wynik += czasy[i];
    }
    return wynik;
}

Harmonogram Harmonogram::kopiaWZakresie(Czas zakres) {//tworzymy nowy Harmonogram oraz przepisujemy Czasy dopoki 
    //miesci sie w zakresie.
    Harmonogram nowy;
    Czas suma;
    for (int i = 0; i < ile; i++) {
        if (suma + czasy[i] <= zakres) {
            nowy.dodajCzas(czasy[i]);
            suma += czasy[i];
        }
        else break;
    }
    return nowy;
}
void Harmonogram::usunOstatni() {
    if (ile > 0) {
        ile--;
    }
}

void Harmonogram::wyczysc() {
    ile = 0;
}