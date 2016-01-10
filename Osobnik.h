//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_OSOBNIK_H
#define PROBLEMKOMIOK_OSOBNIK_H

#include <vector>
#include <algorithm>
#include <iostream>

class Osobnik {
public:
    virtual std::vector<int> generujRozwiazanie() = 0;

    void wyswietlRozwiazanie();

    void policzWynik();

    int wynik;
protected:
    std::vector<int> rozwiazanie;
};


#endif //PROBLEMKOMIOK_OSOBNIK_H

void Osobnik::wyswietlRozwiazanie() {
    std::for_each(rozwiazanie.begin(), rozwiazanie.end(), [](int a) {
        std::cout << a << "  ";
    });
    std::cout << ": " << wynik << "\n";
}

void Osobnik::policzWynik() {
    std::accumulate(rozwiazanie.begin(), rozwiazanie.end(), 0);
}
