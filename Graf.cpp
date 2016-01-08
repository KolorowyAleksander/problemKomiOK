//
// Created by A on 2015-10-15.
//

#include <c++/iostream>
#include <time.h>
#include "Graf.h"
#include <algorithm>


Graf::Graf(int lWierzcholkow, int wierzcholekPoczatkowy)
        : lWierzcholkow(lWierzcholkow), wierzcholekPoczatkowy(wierzcholekPoczatkowy) {
    this->macierz = generowanie_macierzy();
}

Graf::~Graf() {
    zwalnianie_pamieci(macierz);
}

int **Graf::generowanie_macierzy() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 999);
    int **macierz = nullptr;
    macierz = new int *[lWierzcholkow];
    for (int i = 0; i < lWierzcholkow; i++) {
        macierz[i] = new int[lWierzcholkow];
        for (int j = 0; j < lWierzcholkow; j++)
            if (i > j) {
                macierz[i][j] = dis(gen);
            }
            else {
                macierz[i][j] = 0;
            }
    }
    for (int i = 0; i < lWierzcholkow; i++)
        for (int j = 0; j < lWierzcholkow; j++)
            macierz[i][j] = macierz[j][i];
    return macierz;
}

void Graf::zwalnianie_pamieci(int **macierz) {
    for (int i = 0; i < lWierzcholkow; i++)
        delete[] macierz[i];
    delete[] macierz;
}

void Graf::wyswietlanie_grafu() {
    for (int i = 0; i < lWierzcholkow; i++) {
        for (int j = 0; j < lWierzcholkow; j++)
            std::cout << macierz[i][j] << " ";
        std::cout << std::endl;
    }
}

int **Graf::get_macierz() {
    return macierz;
}
