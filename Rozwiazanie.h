//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_ROZWIAZANIE_H
#define PROBLEMKOMIOK_ROZWIAZANIE_H

#include <vector>

class Rozwiazanie {
public:
    virtual void rozwiaz() = 0;
    void getRozwiazanie();
    Rozwiazanie(int **macierz, int liczbaWierzcholkow, int wierzcholekPoczatkowy);

protected:
    int **macierz;
    int liczbaWierzcholkow;
    int wierzcholekPoczatkowy;
    std::vector<int> rozwiazanie;
};


#endif //PROBLEMKOMIOK_ROZWIAZANIE_H
