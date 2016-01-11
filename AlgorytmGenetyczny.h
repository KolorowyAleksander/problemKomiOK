//
// Created by A on 2016-01-10.
//

#ifndef PROBLEMKOMIOK_ALGORYTMGENETYCZNY_H
#define PROBLEMKOMIOK_ALGORYTMGENETYCZNY_H


#include "Rozwiazanie.h"
#include "Osobnik.h"
#include <vector>

class AlgorytmGenetyczny : public Rozwiazanie {
public:
    void rozwiaz();

    AlgorytmGenetyczny(int **macierz, int liczbaWierzcholkow, int wierzcholekPoczatkowy);

private:
    void generujPopulacje();

    class OsobnikDNA : public Osobnik {
    public:
        OsobnikDNA(AlgorytmGenetyczny &parent);

        void generujRozwiazanie();

        OsobnikDNA &operator = (const OsobnikDNA &a);
    private:
        AlgorytmGenetyczny &parent;
    };

    /* populacja */
    std::vector<OsobnikDNA> populacja;
    int liczbaOsobnikow = 10;

    void selekcja();
};


#endif //PROBLEMKOMIOK_ALGORYTMGENETYCZNY_H
