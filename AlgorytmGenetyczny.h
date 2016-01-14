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

        void policzWynik();

        void mutacja();

        OsobnikDNA &operator=(const OsobnikDNA &a);

        AlgorytmGenetyczny *parent;
    };

    /* populacja */
    std::vector<OsobnikDNA> populacja;
    int liczbaOsobnikow = 10; // ile osobnikow w populacji?

    void selekcja();

    void kombinacja();

    void mutacja();
};


#endif //PROBLEMKOMIOK_ALGORYTMGENETYCZNY_H
