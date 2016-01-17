//
// Created by A on 2016-01-08.
//

#include "HeurystykaNajblizszegoSasiada.h"
#include <chrono>

void HeurystykaNajblizszegoSasiada::rozwiaz() {
    auto start = std::chrono::system_clock::now();
    odwiedzone = new bool(liczbaWierzcholkow);
    rozwiazanie.push_back(wierzcholekPoczatkowy);
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        odwiedzone[i] = false;
    }
    odwiedzone[wierzcholekPoczatkowy] = true;
    while (rozwiazanie.size() < liczbaWierzcholkow) {
        int min = INT_MAX, index = 0;
        for (int i = 0; i < liczbaWierzcholkow; i++) {
            if (macierz[rozwiazanie.back()][i] < min && macierz[rozwiazanie.back()][i] > 0 && !odwiedzone[i]) {
                min = macierz[rozwiazanie.back()][i];
                index = i;
            }
        }
        rozwiazanie.push_back(index);
        odwiedzone[index] = true;
        sumaOdleglosci += min;
    }
    rozwiazanie.push_back(wierzcholekPoczatkowy);
    //delete odwiedzone;
    auto end = std::chrono::system_clock::now();
    czas = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

HeurystykaNajblizszegoSasiada::HeurystykaNajblizszegoSasiada(Graf *graf)
        : Rozwiazanie(graf) { }
