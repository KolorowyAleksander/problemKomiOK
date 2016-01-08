//
// Created by A on 2016-01-08.
//

#include "MetodaSilowaPermutacje.h"
#include "Rozwiazanie.h"
#include <iostream>
#include <algorithm>

void MetodaSilowaPermutacje::rozwiaz() {
    int suma;
    tWierzcholkow = new std::vector<int>();
    for (int i = 0; i < lWierzcholkow; i++)
        if (i != wierzcholekPoczatkowy)
            tWierzcholkow->push_back(i);
    do {
        suma = macierz[wierzcholekPoczatkowy][tWierzcholkow->front()];
        for (auto i: *tWierzcholkow) {
            suma += macierz[i][i + 1];
            std::cout << i << " ";
        }
        std::cout << "    ";
        suma += macierz[tWierzcholkow->back()][wierzcholekPoczatkowy];
        std::cout << suma;
        std::cout << std::endl;

    } while (std::next_permutation(tWierzcholkow->begin(), tWierzcholkow->end()));
}

MetodaSilowaPermutacje::MetodaSilowaPermutacje(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy)
        : Rozwiazanie(macierz, lWierzcholkow, wierzcholekPoczatkowy) { }
