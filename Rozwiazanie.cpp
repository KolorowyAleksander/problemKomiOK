//
// Created by A on 2016-01-08.
//

#include "Rozwiazanie.h"
#include <iostream>

Rozwiazanie::Rozwiazanie(int **macierz, int liczbaWierzcholkow, int wierzcholekPoczatkowy)
        : macierz(macierz), liczbaWierzcholkow(liczbaWierzcholkow), wierzcholekPoczatkowy(wierzcholekPoczatkowy) { }

void Rozwiazanie::getRozwiazanie() {
    for (int i = 0; i < liczbaWierzcholkow +1; i++)
        std::cout << rozwiazanie[i] << ' ';
}
