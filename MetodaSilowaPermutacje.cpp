//
// Created by A on 2016-01-08.
//

#include "MetodaSilowaPermutacje.h"
#include "Rozwiazanie.h"
#include <iostream>
#include <algorithm>

void MetodaSilowaPermutacje::rozwiaz() {
    max = 0;
    for (int i = 0; i < liczbaWierzcholkow; i++)
        if (i != wierzcholekPoczatkowy)
            tablicaWierzcholkow.push_back(i);
    std::cout << "*";
    do {
        //std::cout << wierzcholekPoczatkowy << " ";
        suma = (unsigned long long int) macierz[wierzcholekPoczatkowy][tablicaWierzcholkow.front()];

        for (int i = 0; i < liczbaWierzcholkow - 2; i++) {
            suma += macierz[tablicaWierzcholkow[i]][tablicaWierzcholkow[i + 1]];
            //std::cout << tablicaWierzcholkow[i] << " ";
        }
        suma += macierz[tablicaWierzcholkow.back()][wierzcholekPoczatkowy];
        //std::cout << tablicaWierzcholkow.back() << " " << wierzcholekPoczatkowy << "\t" << suma << "\n";
        if (sprawdzMax(suma)) {
            rozwiazanie = tablicaWierzcholkow;
            rozwiazanie.push_back(wierzcholekPoczatkowy);
            rozwiazanie.insert(rozwiazanie.begin(), wierzcholekPoczatkowy);
            max = suma;
        }
    } while (std::next_permutation(tablicaWierzcholkow.begin(), tablicaWierzcholkow.end()));
    std::cout << "\n";
}

MetodaSilowaPermutacje::MetodaSilowaPermutacje(Graf *graf)
        : Rozwiazanie(graf) { }

bool MetodaSilowaPermutacje::sprawdzMax(unsigned long long int sprawdzana) {
    return sprawdzana > max;
}