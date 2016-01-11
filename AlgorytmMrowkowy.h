//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_ALGORYTMMROWKOWY_H
#define PROBLEMKOMIOK_ALGORYTMMROWKOWY_H


#include "Rozwiazanie.h"
#include "Osobnik.h"
#include <random>
#include <stack>
#include <vector>

class AlgorytmMrowkowy : public Rozwiazanie {
public:
    AlgorytmMrowkowy(int **macierz, int liczbaWierzcholkow, int wierzcholekPoczatkowy,
                     double alfa, double beta, double ro, int maksymalnyFeromon);

    ~AlgorytmMrowkowy();

    void rozwiaz();

private:
    double alfa;
    double beta;
    double ro;
    double q;
    int wierzcholekPoczatkowy;
    int maksymalnyFeromon;
    int **feromony;

    void zmienFeromony();

    void utworzFeromony();

    void usunFeromony();

    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_real_distribution<> dis;

    class Mrowka : public Osobnik {
    public:
        Mrowka(AlgorytmMrowkowy &parent);

        ~Mrowka();

        void generujRozwiazanie();

    private:
        bool *odwiedzone;
        double *prawdopodobienstwo;
        AlgorytmMrowkowy parent;

    };

    /* tablica trzymajaca mrowki */
    std::vector<Mrowka> populacja;
};


#endif //PROBLEMKOMIOK_ALGORYTMMROWKOWY_H
