//
// Created by A on 2015-10-15.
//

#ifndef PROBLEMKOMIOK_GRAF_H
#define PROBLEMKOMIOK_GRAF_H

#include <random>
#include <stack>
#include <vector>

class Graf {
public:
    Graf(int lWierzcholkow);

    ~Graf();

    void wyswietlanie_grafu();

    void metoda_silowa_DFS();

    void metoda_silowa_permutacje();

    void heurystyka_najblizszego_sasiada();

    void algorytm_mrowkowy(int alfa, int beta, double ro);

    void algorytm_genetyczny();


private:
    int alfa;
    int beta;
    double ro;
    int maksymalny;
    int **macierz;
    int **feromony;
    bool *odwiedzone;
    int wierzcholekPoczatkowy;
    std::stack<int> *stos;
    std::vector<int> *tWierzcholkow;
    int lWierzcholkow;

    std::stack<int> mrowka(int wierzcholekPoczatkowy);

    int **generowanie_macierzy(int lWierzcholkow);

    void zmienFeromon();

    void zwalnianie_pamieci(int **macierz);

    void dfs(int aktualnyWierzcholek);
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_real_distribution<> dis;



};


#endif
//PROBLEMKOMIOK_GRAF_H
