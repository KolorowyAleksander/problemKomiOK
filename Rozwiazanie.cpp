//
// Created by A on 2016-01-08.
//

#include "MetodaSilowaPermutacje.h"
#include "Rozwiazanie.h"
#include <iostream>

Rozwiazanie::Rozwiazanie(Graf *graf)
        : macierz(graf->get()), liczbaWierzcholkow(graf->getLiczbaWierzcholkow()),
          wierzcholekPoczatkowy(graf->getWierzcholekPoczatkowy()), sumaOdleglosci(0) { }

std::vector<int> Rozwiazanie::getRozwiazanieWektor() {
    return rozwiazanie;
}

unsigned long long int Rozwiazanie::getRozwiazanieSuma() {
    return sumaOdleglosci;
}

