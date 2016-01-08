//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_ROZWIAZANIE_H
#define PROBLEMKOMIOK_ROZWIAZANIE_H


class Rozwiazanie {
public:
    virtual void rozwiaz() = 0;

    Rozwiazanie(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy);

protected:
    int **macierz;
    int lWierzcholkow;
    int wierzcholekPoczatkowy;
};


#endif //PROBLEMKOMIOK_ROZWIAZANIE_H
