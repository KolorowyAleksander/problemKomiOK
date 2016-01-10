//
// Created by A on 2015-10-15.
//

#ifndef PROBLEMKOMIOK_GRAF_H
#define PROBLEMKOMIOK_GRAF_H

#include <random>
#include <stack>
#include <vector>

class Graf {
public:
    Graf(int lWierzcholkow, int wierzcholekPoczatkowy);

    ~Graf();

    int **get();

    void wyswietl();

private:
    /* rozwiazanie */
    int **macierz;

    int lWierzcholkow;

    int wierzcholekPoczatkowy;

    int **generowanie_macierzy();

    void zwalnianie_pamieci(int **macierz);
};


#endif
//PROBLEMKOMIOK_GRAF_H
