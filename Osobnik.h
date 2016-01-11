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
    virtual void generujRozwiazanie() = 0;

    void wyswietlRozwiazanie() {
        std::for_each(rozwiazanie.begin(), rozwiazanie.end(), [](int a) {
            std::cout << a << "  ";
        });
        std::cout << ": " << wynik << "\n";
    };

    void policzWynik() {
        std::accumulate(rozwiazanie.begin(), rozwiazanie.end(), 0);
    };

    int wynik;
protected:
    std::vector<int> rozwiazanie;
};

#endif //PROBLEMKOMIOK_OSOBNIK_H
