//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_OSOBNIK_H
#define PROBLEMKOMIOK_OSOBNIK_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Rozwiazanie.h"

class Osobnik {
public:

    Osobnik() { }

    virtual void generujRozwiazanie() = 0;

    virtual void policzWynik() = 0;

    void wyswietlRozwiazanie() {
        std::for_each(rozwiazanie.begin(), rozwiazanie.end(), [](int a) {
            std::cout << a << "  ";
        });
        std::cout << "\t" << wynik << "\n";
    };

    unsigned long long int getWynik() {
        return wynik;
    }

    unsigned long long int wynik = 0;

    std::vector<int> getRozwiazanie() {
        return rozwiazanie;
    }

protected:
    std::vector<int> rozwiazanie;
};

#endif //PROBLEMKOMIOK_OSOBNIK_H
