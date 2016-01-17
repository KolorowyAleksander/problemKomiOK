//
// Created by A on 2016-01-08.
//

#include "MetodaSilowaPermutacje.h"
#include <chrono>
#include <climits>

void MetodaSilowaPermutacje::rozwiaz() {
    auto start = std::chrono::system_clock::now();
    sumaOdleglosci = ULLONG_MAX;
    for (int i = 0; i < liczbaWierzcholkow; i++)
        if (i != wierzcholekPoczatkowy)
            tablicaWierzcholkow.push_back(i);

    do {
        suma = (unsigned long long int) macierz[wierzcholekPoczatkowy][tablicaWierzcholkow.front()];

        for (int i = 0; i < liczbaWierzcholkow - 2; i++) {
            suma += macierz[tablicaWierzcholkow[i]][tablicaWierzcholkow[i + 1]];
        }
        suma += macierz[tablicaWierzcholkow.back()][wierzcholekPoczatkowy];
        if (sprawdzMax(suma)) {
            rozwiazanie = tablicaWierzcholkow;
            rozwiazanie.push_back(wierzcholekPoczatkowy);
            rozwiazanie.insert(rozwiazanie.begin(), wierzcholekPoczatkowy);
            sumaOdleglosci = suma;
        }
    } while (std::next_permutation(tablicaWierzcholkow.begin(), tablicaWierzcholkow.end()));

    auto end = std::chrono::system_clock::now();
    czas = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

MetodaSilowaPermutacje::MetodaSilowaPermutacje(Graf *graf)
        : Rozwiazanie(graf) { }

bool MetodaSilowaPermutacje::sprawdzMax(unsigned long long int sprawdzana) {
    return sprawdzana < sumaOdleglosci;
}
