//
// Created by A on 2016-01-08.
//

#include "MetodaSilowaPermutacje.h"

Rozwiazanie::Rozwiazanie(Graf *graf)
        : macierz(graf->get()), liczbaWierzcholkow(graf->getLiczbaWierzcholkow()),
          wierzcholekPoczatkowy(graf->getWierzcholekPoczatkowy()), sumaOdleglosci(0) { }

std::vector<int> Rozwiazanie::getRozwiazanieWektor() {
    rozwiazanie.shrink_to_fit();
    return rozwiazanie;
}

long long int Rozwiazanie::getRozwiazanieSuma() {
    return sumaOdleglosci;
}

unsigned long long int Rozwiazanie::getCzas() {
    return (unsigned long long int) czas;
}

