#ifndef CZAS_H 
#define CZAS_H

//w tym file jest inicjalizacja clasy Czas.

class Czas {
private: // znaczenia prywante - sekundy, minuty i godzieny. Oraz funkcja poprawCzas.
    int sekundy, minuty, godziny;
    void poprawCzas();

public: // znaczenia publiczne 

    //konstruktory zwyczajne i przeciazone
    Czas(); 
    Czas(int s);
    Czas(int m, int s);
    Czas(int h, int m, int s);

    //gettery
    int getSekundy();
    int getMinuty();
    int getGodziny();

    //settery
    void ustawCzas(int h, int m, int s);
    void ustawCzas(int m, int s);
    void ustawCzas(int s);

    void wypisz(); //funkcja a-la "print" dla obiektu

    //dzialania matematyczne z obiektami tego typu bedą obslugowane poprzez te funkcje:
    Czas operator+(Czas c);
    void operator+=(Czas c);
    bool operator<(Czas c);
    bool operator==(Czas c);
    bool operator>(Czas c);
    bool operator<=(Czas c);
    bool operator>=(Czas c);
    bool operator!=(Czas c);

    //sa niezbędne, bo komputer nie wie jak porównywać 11:33:43 oraz 12:44:32, wiec musimy to opisac.
};

#endif