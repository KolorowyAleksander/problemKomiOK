//
// Created by A on 2015-10-15.
//

#ifndef PROBLEMKOMIOK_GRAF_H
#define PROBLEMKOMIOK_GRAF_H

#include <stack>
#include <vector>

class Graf {
public:
    Graf(int lWierzcholkow);

    ~Graf();

    void wyswietlanie_grafu();

    void metoda_silowa_DFS();

    void metoda_silowa_permutacje();

private:
    int **macierz;
    bool *odwiedzone;
    int wierzcholekPoczatkowy;
    std::stack<int> *stos;
    std::vector<int> *tWierzcholkow;
    int lWierzcholkow;

    int **generowanie_macierzy(int lWierzcholkow);

    void zwalnianie_pamieci(int **macierz);

    void dfs(int aktualnyWierzcholek);


};


#endif //PROBLEMKOMIOK_GRAF_H
