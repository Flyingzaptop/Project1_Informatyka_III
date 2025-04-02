#include <iostream>
#include "Czas.h"
#include "Harmonogram.h"
using namespace std;

int main() {
    Harmonogram h;  // najpierw tworzymy obiekt h z classy Harmonogram, szczególy ktorej są w Harmonogram.cpp
    int choice;     
    int h_temp, m_temp, s_temp;
    // tworzymy zmienne dla wyboru z menu (choice) oraz czasowe zmienne dla godzin, minut i secund 
    do {
        cout << "Menu:" << endl;
        cout << "1. Add time to schedule" << endl;
        cout << "2. Print schedule" << endl;
        cout << "3. Calculate total time" << endl;
        cout << "4. Copy within range" << endl;
        cout << "5. Remove last task" << endl;      
        cout << "6. Clear schedule" << endl;        
        cout << "7. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;  //wyciągamy z menu wybor 

        if (choice == 1) {  
            cout << "Enter hours: ";
            cin >> h_temp;
            cout << "Enter minutes: ";
            cin >> m_temp;
            cout << "Enter seconds: ";
            cin >> s_temp;
            Czas nowy(h_temp, m_temp, s_temp);
            h.dodajCzas(nowy);
            cout << "Time added!" << endl;
        }//jezeli opcja 1 - user wpisuje godziny, minuty i secundy do zmiennych oraz tworzy sie obiekt clasy Czas z tymi znaczeniami.
        //dalej do obiektu h, który jest jakby listą, dodajemy ten element, Czas który stworzylismy.
        else if (choice == 2) {
            cout << "Schedule:" << endl;
            h.wypisz();
        }// opcja 2 wywoluje .wypisz() i po prostu wypisuje wszystko co jest w obiekcie h
        else if (choice == 3) {
            Czas suma = h.suma();
            cout << "Total time: ";
            suma.wypisz();
        }// opcja 3 - wypisuje sumę elementów z obiektu h
        else if (choice == 4) {
            cout << "Enter range - hours: ";
            cin >> h_temp;
            cout << "Enter range - minutes: ";
            cin >> m_temp;
            cout << "Enter range - seconds: ";
            cin >> s_temp;
            Czas zakres(h_temp, m_temp, s_temp);
            Harmonogram kopia = h.kopiaWZakresie(zakres);
            cout << "Copy within range:" << endl;
            kopia.wypisz();
        }// opcja 4 jest trochy trudna. User wpisuje zakres godziny, minuty, secundy. Dalej tworzy sie obiek zakres clasy Czas z tymi
        // znaczeniami. Dalej tworzymy nowy obiekt clasy Harmonogram - kopia, do której zapisujemy tylko to co wchodzi do zakresu.
        else if (choice == 5) {//opcja do usuniecia ostatniego Tasku
            h.usunOstatni();
            cout << "Last task removed!" << endl;
        }
        else if (choice == 6) {//Wyczysczenie Harmonogramu.
            h.wyczysc();
            cout << "Schedule cleared!" << endl;
        }
        else if (choice == 7) {
            cout << "Program ended!" << endl;
        }//opcja 7 - wyjscie
        else {
            cout << "Wrong option, try again!" << endl;
        }
    } while (choice != 7);

    return 0;

    // wyjasnienie jak to działa:
    // najpierw, user widzi menu, które jest takie, jak robiłem zawsze :)
    // Opcja 1 - dodaje "czas" do listy, opcja 2 - wypisuje całą liste, opcja 3 - podbija całość (total), opcja 4 - 
    // wypisuje tylko te taski, którzy miescią sie w pewnym zakresie, ktory wpisuje user, opcja 5 - wyjscie.
    //
    //Proszę patrzyć na dokumenty w następnej kolejności:
    //Project1.cpp -> Czas.h -> Czas.cpp -> Harmonogram.h -> Harmonogram.cpp
    // 
    // Bedzie to łatwiej do zrozumienia :)

}