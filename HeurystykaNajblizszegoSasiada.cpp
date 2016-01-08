//
// Created by A on 2016-01-08.
//

#include "HeurystykaNajblizszegoSasiada.h"
#include <iostream>

void HeurystykaNajblizszegoSasiada::rozwiaz() {
    int suma;
    stos = new std::vector<int>;
    stos->push_back(wierzcholekPoczatkowy);
    odwiedzone = new bool(lWierzcholkow);
    for (int i = 0; i < lWierzcholkow; i++) {
        odwiedzone[i] = false;
    }
    odwiedzone[wierzcholekPoczatkowy] = true;
    while (stos->size() < lWierzcholkow) {
        int najmniejszy = 10000, index;//dopisac makro max
        for (int i = 0; i < lWierzcholkow; i++) {
            if (macierz[stos->back()][i] < najmniejszy && macierz[stos->back()][i] > 0 && !odwiedzone[i]) {
                najmniejszy = macierz[stos->back()][i];
                index = i;
            }
        }
        stos->push_back(index);
        odwiedzone[index] = true;
        suma += najmniejszy;
    }
    stos->push_back(wierzcholekPoczatkowy);
    delete[]odwiedzone;
    for (int i = 0; i <= lWierzcholkow; i++) {
        std::cout << stos->back() << " ";
        stos->pop_back();
    }

    delete stos;
    std::cout << " suma:" << suma;
}

HeurystykaNajblizszegoSasiada::HeurystykaNajblizszegoSasiada(int **macierz, int lWierzcholkow,
                                                             int wierzcholekPoczatkowy)
        : Rozwiazanie(macierz, lWierzcholkow, wierzcholekPoczatkowy) { }
