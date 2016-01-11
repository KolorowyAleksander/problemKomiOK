//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_METODASILOWAPERMUTACJE_H
#define PROBLEMKOMIOK_METODASILOWAPERMUTACJE_H

#include <vector>
#include "Rozwiazanie.h"

class MetodaSilowaPermutacje : public Rozwiazanie {
public:
    void rozwiaz();
    MetodaSilowaPermutacje(int **macierz, int liczbaWierzcholkow, int wierzcholekPoczatkowy);

private:
    std::vector<int> tablicaWierzcholkow;
    unsigned long long int max;
    bool sprawdzMax(unsigned long long int sprawdzana);
};


#endif //PROBLEMKOMIOK_METODASILOWAPERMUTACJE_H
