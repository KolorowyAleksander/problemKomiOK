//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_METODASILOWADFS_H
#define PROBLEMKOMIOK_METODASILOWADFS_H


#include "Rozwiazanie.h"
#include <vector>

class MetodaSilowaDFS : public Rozwiazanie {
public:
    void rozwiaz();

    MetodaSilowaDFS(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy);

    ~MetodaSilowaDFS();

private:
    int **macierz;
    int lWierzcholkow;
    int wierzcholekPoczatkowy;

    bool *odwiedzone;
    std::vector<int> *stos;

    void dfs(int aktualnyWierzcholek);
};


#endif //PROBLEMKOMIOK_METODASILOWADFS_H
