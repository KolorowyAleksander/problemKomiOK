//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_ALGORYTMMROWKOWY_H
#define PROBLEMKOMIOK_ALGORYTMMROWKOWY_H


#include "Rozwiazanie.h"
#include <random>
#include <stack>

class AlgorytmMrowkowy : public Rozwiazanie {
public:
    AlgorytmMrowkowy(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy,
                     double alfa, double beta, double ro, int maksymalnyFeromon);

    void algorytm_mrowkowy();

private:
    double alfa;
    double beta;
    double ro;
    int maksymalnyFeromon;
    int **feromony;
    bool *odwiedzone;

    std::stack<int> mrowka(int wierzcholekPoczatkowy);

    std::stack<int> *stos;

    void zmienFeromon();

    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_real_distribution<> dis;
};


#endif //PROBLEMKOMIOK_ALGORYTMMROWKOWY_H
