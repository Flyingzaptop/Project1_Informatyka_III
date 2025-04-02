#include <iostream>
#include "Czas.h"
using namespace std;

//w tym dokumencie bedą opisane te funkcje, z których będziemy korzystali przy działaniu z obiektami clasy Czas:

void Czas::poprawCzas() {// najpierw to - zamieniamy znaczenie 6312 na mormalne 01:45:12
    while (sekundy >= 60) {
        sekundy -= 60;
        minuty++;
    }
    while (minuty >= 60) {
        minuty -= 60;
        godziny++;
    }
    if (sekundy < 0) sekundy = 0;
    if (minuty < 0) minuty = 0;
    if (godziny < 0) godziny = 0;
}
//dalej inicjalizacja konstruktorów (w tym przeciązonych) oraz wywołanie poprawCzas() 
Czas::Czas() : sekundy(0), minuty(0), godziny(0) {}
Czas::Czas(int s) : sekundy(s), minuty(0), godziny(0) { poprawCzas(); }
Czas::Czas(int m, int s) : sekundy(s), minuty(m), godziny(0) { poprawCzas(); }
Czas::Czas(int h, int m, int s) : sekundy(s), minuty(m), godziny(h) { poprawCzas(); }

//inicjalizacja getterów
int Czas::getSekundy() { return sekundy; }
int Czas::getMinuty() { return minuty; }
int Czas::getGodziny() { return godziny; }

//funkcja, która bedzię wpisywała do temp zmiennych znaczenie oraz je poprawienie (12:99:23 -> 13:39:23), a jak wpisujemy 
// tylko 1 lub 2 argumenty - interprytuje to jako minuty:sekundy lub tylko sekundy.
void Czas::ustawCzas(int h, int m, int s) {
    godziny = h;
    minuty = m;
    sekundy = s;
    poprawCzas();
}
void Czas::ustawCzas(int m, int s) { ustawCzas(0, m, s); }
void Czas::ustawCzas(int s) { ustawCzas(0, 0, s); }

void Czas::wypisz() {//wiadomo :)
    cout << "Czas: " << godziny << ":" << minuty << ":" << sekundy << endl;
}

//Dalej bedzie częsc operatorów matematycznych dla obiektów clasy Czas. 

Czas Czas::operator+(Czas c) { //11:23:33 + 11:23:33 = 22:47:02.
    return Czas(godziny + c.godziny, minuty + c.minuty, sekundy + c.sekundy);
}

void Czas::operator+=(Czas c) {//technicznie, jest to samo co ostatnie, ale ta funkcja zwracała nowy obiekt, a ta zamienia istniający.
    sekundy += c.sekundy;
    minuty += c.minuty;
    godziny += c.godziny;
    poprawCzas();
}

bool Czas::operator<(Czas c) { // porównóje oraz zwraca true jezeli C1 < C2;
    if (godziny != c.godziny) return godziny < c.godziny;
    if (minuty != c.minuty) return minuty < c.minuty;
    return sekundy < c.sekundy;
}

bool Czas::operator==(Czas c) {// Zwraca true, jezeli ==
    return sekundy == c.sekundy && minuty == c.minuty && godziny == c.godziny;
}

//dalej robimy funkcje porównywania, ale juz korzystając z tych, które są opisane

bool Czas::operator>(Czas c) { return !(*this < c || *this == c); } //jezeli jest NIEmniejsza lub NIErówna sie, czyli > 
bool Czas::operator<=(Czas c) { return (*this < c || *this == c); }//jezeli jest mniejsza lub rowna sie, czyli <=
bool Czas::operator>=(Czas c) { return (!(*this < c)|| *this == c); }//jezeli jest NIEmniejsza lub rowna sie, czyli >=
bool Czas::operator!=(Czas c) { return !(*this == c); }//jezeli NIErowna sie, czyli !=
