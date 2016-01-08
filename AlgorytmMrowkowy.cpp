//
// Created by A on 2016-01-08.
//

#include "AlgorytmMrowkowy.h"
#include <iostream>

std::random_device AlgorytmMrowkowy::rd;
std::mt19937 AlgorytmMrowkowy::gen(rd());
std::uniform_real_distribution<> AlgorytmMrowkowy::dis(0.0, 1.0);

AlgorytmMrowkowy::AlgorytmMrowkowy(int **macierz, int lWierzcholkow, int wierzcholekPoczatkowy,
                                   double alfa, double beta, double ro, int maksymalnyFeromon)
        : Rozwiazanie(macierz, lWierzcholkow, wierzcholekPoczatkowy),
          alfa(alfa), beta(beta), ro(ro), maksymalnyFeromon(maksymalnyFeromon) { }

void AlgorytmMrowkowy::algorytm_mrowkowy() {
    int i = 0;
    int najkrotsza; //czy inicjowac - czywiscie, ze inicjowac
    feromony = new int *[lWierzcholkow];
    for (int j = 0; j < lWierzcholkow; j++) {
        feromony[j] = new int[lWierzcholkow];
        for (int k = 0; k < lWierzcholkow; k++) {
            feromony[j][k] = 1;
        }
    }
    while (i < 1000) {
        std::stack<int> droga = mrowka(wierzcholekPoczatkowy);
        int suma = 0;
        int a = droga.top();
        droga.pop();
        while (droga.top() != wierzcholekPoczatkowy) {
            suma = +macierz[a][droga.top()];
            a = droga.top();
            droga.pop();
        }
        std::cout << suma << std::endl;

        if (suma < najkrotsza)
            najkrotsza = suma;
        if (!i % 10)
            zmienFeromon(); // do poprawki
        i++;
    }

}

std::stack<int> AlgorytmMrowkowy::mrowka(int wierzcholekPoczatkowy) {
    std::stack<int> trasa;
    bool *odw = new bool[lWierzcholkow];
    double *prawdopodobienstwo = new double[lWierzcholkow];
    for (int i = 0; i < lWierzcholkow; i++) {
        odw[i] = false;
    }
    int aktualnyWierzcholek = wierzcholekPoczatkowy;
    //pętla szukania następnego
    while (trasa.size() < lWierzcholkow - 1) {
        double suma = 0.0;
        odw[aktualnyWierzcholek] = true;
        std::cout << aktualnyWierzcholek << " ";
        trasa.push(aktualnyWierzcholek);
        for (int i = 0; i < lWierzcholkow; i++) {
            if (!odw[i]) {
                suma += pow(feromony[aktualnyWierzcholek][i], alfa) * pow(1.0 / macierz[aktualnyWierzcholek][i], beta);
            }
        }
        for (int i = 0; i < lWierzcholkow; i++) {
            if (odw[i])
                prawdopodobienstwo[i] = 0;
            else {
                prawdopodobienstwo[i] = pow(feromony[aktualnyWierzcholek][i], alfa) *
                                        (pow((1.0 / macierz[aktualnyWierzcholek][i]), beta)) / suma;
            }
        }

        double generowana = dis(gen);
        int licznik = -1;
        while (generowana >= 0) {
            licznik++;
            generowana = generowana - prawdopodobienstwo[licznik];
        }
        if (feromony[aktualnyWierzcholek][licznik] < maksymalnyFeromon)
            feromony[aktualnyWierzcholek][licznik]++;
        aktualnyWierzcholek = licznik;
    }
    std::cout << aktualnyWierzcholek << "   ";
    trasa.push(wierzcholekPoczatkowy);
    delete[] odw;
    delete[] prawdopodobienstwo;
    return trasa;
}

void AlgorytmMrowkowy::zmienFeromon() {
    for (int i = 0; i < lWierzcholkow; i++) {
        for (int j = 0; j < lWierzcholkow; j++) {
            feromony[i][j] -= feromony[i][j] * ro;
            if (feromony[i][j] < 1)
                feromony[i][j] = 1;
        }
    }
}