#ifndef HARMONOGRAM_H
#define HARMONOGRAM_H
#include "Czas.h"
//w tyl dokumencie opisujemy clase Harmonogram, która de-facto jest listą obiektów clasy Czas.
class Harmonogram {
private:// znaczenie prywatne - wskaznik na poczatek listy, rozmiar - max ilosc elemetów oraz ile - ilosc elementow w tej chwili.
    Czas* czasy;
    int rozmiar;
    int ile;

public:  
    Harmonogram();// konstrukor
    Harmonogram(const Harmonogram& h); // konstruktor, który tworzy nowy obiekt, z dannymi z innego.
    Harmonogram& operator=(const Harmonogram& h);//prawie to samo, ale nie tworzy nowy obiekt, a zmienia istniajacy.
    ~Harmonogram();//destruktor

    //customowe funkcje, z których korzystamy.
    void dodajCzas(Czas c);
    int getIle();
    Czas& operator[](int i);
    void wypisz();
    Czas suma();
    Harmonogram kopiaWZakresie(Czas zakres);
    void usunOstatni(); 
    void wyczysc();
};

#endif