//
// Created by A on 2015-10-15.
//

#include "Graf.h"
#include <iostream>
#include <algorithm>

Graf::Graf(int liczbaWierzcholkow, int wierzcholekPoczatkowy)
        : liczbaWierzcholkow(liczbaWierzcholkow), wierzcholekPoczatkowy(wierzcholekPoczatkowy) {
    generowanie_macierzy();
}

Graf::~Graf() {
    zwalnianie_pamieci(macierz);
}

void Graf::generowanie_macierzy() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 999);
    macierz = new int *[liczbaWierzcholkow];
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        macierz[i] = new int[liczbaWierzcholkow];
        for (int j = 0; j < liczbaWierzcholkow; j++)
            if (i > j)
                macierz[i][j] = dis(gen);
            else
                macierz[i][j] = 0;
    }
    for (int i = 0; i < liczbaWierzcholkow; i++)
        for (int j = 0; j < liczbaWierzcholkow; j++)
            macierz[i][j] = macierz[j][i];
}

void Graf::zwalnianie_pamieci(int **macierz) {
    for (int i = 0; i < liczbaWierzcholkow; i++)
        delete[] macierz[i];
    delete[] macierz;
}

void Graf::wyswietl() {
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        for (int j = 0; j < liczbaWierzcholkow; j++)
            std::cout << macierz[i][j] << " ";
        std::cout << std::endl;
    }
}

int **Graf::get() {
    return macierz;
}

int Graf::getLiczbaWierzcholkow() {
    return liczbaWierzcholkow;
}

int Graf::getWierzcholekPoczatkowy() {
    return wierzcholekPoczatkowy;
}
