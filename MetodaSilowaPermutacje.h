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

    MetodaSilowaPermutacje(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy);

private:
    int **macierz;
    int lWierzcholkow;
    int wierzcholekPoczatkowy;
    std::vector<int> *tWierzcholkow;
};


#endif //PROBLEMKOMIOK_METODASILOWAPERMUTACJE_H
