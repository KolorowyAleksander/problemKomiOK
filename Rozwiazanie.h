//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_ROZWIAZANIE_H
#define PROBLEMKOMIOK_ROZWIAZANIE_H

#include <vector>
#include "Graf.h"
#include "Osobnik.h"
class Rozwiazanie {

public:
    virtual void rozwiaz() = 0;

    std::vector<int> getRozwiazanieWektor();

    unsigned long long int getRozwiazanieSuma();

    Rozwiazanie(Graf *graf);

protected:
    int **macierz;
    int liczbaWierzcholkow;
    int wierzcholekPoczatkowy;
    std::vector<int> rozwiazanie;
    unsigned long long int sumaOdleglosci;
};


#endif //PROBLEMKOMIOK_ROZWIAZANIE_H
