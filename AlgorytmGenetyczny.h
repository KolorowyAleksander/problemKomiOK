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

    AlgorytmGenetyczny(Graf *graf);

private:
    void generujPopulacje();


    class OsobnikDNA : public Osobnik {
    public:
        OsobnikDNA(const OsobnikDNA &obj);

        OsobnikDNA(AlgorytmGenetyczny *parent);

        OsobnikDNA();

        void generujRozwiazanie();

        void setRozwiazanie(std::vector<int> rozwiazanie);

        void policzWynik();

        void mutacja();


        OsobnikDNA &operator=(const OsobnikDNA &a);

        AlgorytmGenetyczny *parent;
    };

    /* populacja */
    std::vector<OsobnikDNA> populacja;
    int liczbaOsobnikow = liczbaWierzcholkow;

    void selekcja();

    void kombinacja();

    void mutacja();

    void krzyzuj(OsobnikDNA ojciec, OsobnikDNA matka);

    std::vector<int> inwersja(const std::vector<int> v);

    std::vector<int> odwrotnaInversja(const std::vector<int> v);
};


#endif //PROBLEMKOMIOK_ALGORYTMGENETYCZNY_H
