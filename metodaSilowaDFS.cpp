//
// Created by A on 2016-01-08.
//

#include "MetodaSilowaDFS.h"
#include <stack>
#include <iostream>
#include <algorithm>

void MetodaSilowaDFS::dfs(int aktualnyWierzcholek) {
    stos->push_back(aktualnyWierzcholek);
    if (stos->size() < liczbaWierzcholkow) {
        odwiedzone[aktualnyWierzcholek] = true;
        for (int i = 0; i < liczbaWierzcholkow; i++) {
            if (macierz[aktualnyWierzcholek][i] && !odwiedzone[i]) {
                dfs(i);
                odwiedzone[i] = false;
            }
        }
        odwiedzone[aktualnyWierzcholek] = false;
    }
    return;
}

void MetodaSilowaDFS::rozwiaz() {
    stos = new std::vector<int>();
    //wywolanie funkcji znajdujacej cykle
    dfs(wierzcholekPoczatkowy);
    for_each(stos->begin(), stos->end(), [](int i) {
        std::cout << i << ", ";
    });
    std::cout << "\n";
}


MetodaSilowaDFS::MetodaSilowaDFS(Graf *graf)
        : Rozwiazanie(graf) {
    odwiedzone = new bool[liczbaWierzcholkow];
    for (int i = 0; i < liczbaWierzcholkow; i++)
        odwiedzone[i] = false;
}

MetodaSilowaDFS::~MetodaSilowaDFS() {
    delete[] odwiedzone;
}
