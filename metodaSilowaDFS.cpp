//
// Created by A on 2016-01-08.
//

#include "MetodaSilowaDFS.h"
#include <stack>
#include <iostream>
#include <algorithm>

void MetodaSilowaDFS::dfs(int aktualnyWierzcholek) {
    //do zrobienia zliczanie wag i zapamietywanie najkrotszej sciezki
    stos->push_back(aktualnyWierzcholek);
    if (stos->size() < lWierzcholkow) {
        odwiedzone[aktualnyWierzcholek] = true;
        for (int i = 0; i < lWierzcholkow; i++) {
            if (macierz[aktualnyWierzcholek][i] && !odwiedzone[i]) {
                dfs(i);
            }
        }
        odwiedzone[aktualnyWierzcholek] = false;
    } else {
        if (macierz[aktualnyWierzcholek][0]) {
            return;
        }
    }
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


MetodaSilowaDFS::MetodaSilowaDFS(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy)
        : Rozwiazanie(macierz, lWierzcholkow, wierzcholekPoczatkowy) {
    odwiedzone = new bool[lWierzcholkow];
    for (int i = 0; i < lWierzcholkow; i++)
        odwiedzone[i] = false;
}

MetodaSilowaDFS::~MetodaSilowaDFS() {
    delete odwiedzone;
}
