//
// Created by A on 2015-10-15.
//

#include <c++/iostream>
#include <time.h>
#include "Graf.h"
#include <algorithm>

Graf::Graf(int lWierzcholkow) {
    this->lWierzcholkow = lWierzcholkow;
    this->macierz = generowanie_macierzy(lWierzcholkow);
    this->wierzcholekPoczatkowy = 1;
    //std::cout << "Konstuktor\n";
}

Graf::~Graf() {
    zwalnianie_pamieci(macierz);
    //std::cout << "Destruktor\n";
}

int **Graf::generowanie_macierzy(int lWierzcholkow) {
    srand((unsigned int) time(NULL));
    int **macierz = nullptr;
    macierz = new int *[lWierzcholkow];
    for (int i = 0; i < lWierzcholkow; i++) {
        macierz[i] = new int[lWierzcholkow];
        for (int j = 0; j < lWierzcholkow; j++)
            if (i > j) {
                macierz[i][j] = rand() % 1000;
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

void Graf::dfs(int aktualnyWierzcholek) {
    //do zrobienia zliczanie wag i zapamietywanie najkrotszej sciezki
    stos->push(aktualnyWierzcholek);
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

void Graf::metoda_silowa_DFS() {
    stos = new std::stack<int>();
    odwiedzone = new bool[lWierzcholkow];
    for (int i = 0; i < lWierzcholkow; i++)
        odwiedzone[i] = false;
    //wywolanie funkcji znajdujacej cykle
    dfs(wierzcholekPoczatkowy);
    while (stos->size() > 0) {
        //std::cout << stos->top() << ", ";
        stos->pop();
    }
    delete[] odwiedzone;
}

void Graf::metoda_silowa_permutacje() {
    int suma;
    tWierzcholkow = new std::vector<int>();
    for (int i = 0; i < lWierzcholkow; i++)
        if (i != wierzcholekPoczatkowy)
            tWierzcholkow->push_back(i);
    do {
        suma = macierz[wierzcholekPoczatkowy][tWierzcholkow->front()];
        for (auto i: *tWierzcholkow) {
            suma += macierz[i][i + 1];
            std::cout << i << " ";
        }
        std::cout << "    ";
        suma += macierz[tWierzcholkow->back()][wierzcholekPoczatkowy];
        std::cout << suma;
        std::cout << std::endl;

    } while (std::next_permutation(tWierzcholkow->begin(), tWierzcholkow->end()));
}

void Graf::heurystyka_najblizszego_sasiada() {
    int suma;
    stos = new std::stack<int>;
    stos->push(wierzcholekPoczatkowy);
    odwiedzone = new bool(lWierzcholkow);
    for (int i = 0; i < lWierzcholkow; i++) {
        odwiedzone[i] = false;
    }
    odwiedzone[wierzcholekPoczatkowy] = true;
    while (stos->size() < lWierzcholkow) {
        int najmniejszy = 10000, index;//dopisac makro max
        for (int i = 0; i < lWierzcholkow; i++) {
            if (macierz[stos->top()][i] < najmniejszy && macierz[stos->top()][i] > 0 && !odwiedzone[i]) {
                najmniejszy = macierz[stos->top()][i];
                index = i;
            }
        }
        stos->push(index);
        odwiedzone[index] = true;
        suma += najmniejszy;
    }
    stos->push(wierzcholekPoczatkowy);
    delete[]odwiedzone;
    for (int i = 0; i <= lWierzcholkow; i++) {
        std::cout << stos->top() << " ";
        stos->pop();
    }

    delete stos;
    std::cout << " suma:" << suma;
}

void Graf::algorytm_mrowkowy() {
    int i = 0;
    //feromony[lWierzcholkow][lWierzcholkow];
    while (i < 100) {
        mrowka();
        //zmienic feromony
        i++;
    }
}

void Graf::algorytm_genetyczny() {

}

void Graf::mrowka(int wierzcholekPoczatkowy) {
    std::stack<int> trasa;
    bool *odw = new bool[lWierzcholkow];
    int aktualnyWierzcholek = wierzcholekPoczatkowy;
    //wybrac nastepny

}
