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
    Graf(int liczbaWierzcholkow, int wierzcholekPoczatkowy);

    ~Graf();

    int **get();

    int getLiczbaWierzcholkow();

    int getWierzcholekPoczatkowy();

    void wyswietl();

private:
    int **macierz;

    int liczbaWierzcholkow;

    int wierzcholekPoczatkowy;

    void generowanie_macierzy();

    void zwalnianie_pamieci(int **macierz);
};


#endif
//PROBLEMKOMIOK_GRAF_H
