//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_HEURYSTYKANAJBLIZSZEGOSASIADA_H
#define PROBLEMKOMIOK_HEURYSTYKANAJBLIZSZEGOSASIADA_H

#include <vector>
#include "Rozwiazanie.h"

class HeurystykaNajblizszegoSasiada : public Rozwiazanie {
public:
    void rozwiaz();

    HeurystykaNajblizszegoSasiada(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy);

private:
    int **macierz;
    int lWierzcholkow;
    int wierzcholekPoczatkowy;

    bool *odwiedzone;
    std::vector<int> *stos;
};


#endif //PROBLEMKOMIOK_HEURYSTYKANAJBLIZSZEGOSASIADA_H
