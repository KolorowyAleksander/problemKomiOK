//
// Created by A on 2015-10-15.
//

#include <c++/iostream>
#include <time.h>
#include "Graf.h"

Graf::Graf(int lWierzcholkow) {
    this->lWierzcholkow = lWierzcholkow;
    this->macierz = generowanieMacierzy(lWierzcholkow);
    std::cout << "Konstuktor\n";
}

Graf::~Graf() {
    zwalnianiePamieci(macierz);
    std::cout << "Destruktor\n";
}

int **Graf::generowanieMacierzy(int lWierzcholkow) {
    srand((unsigned int) time(NULL));
    int ** macierz = nullptr;
    macierz = new int *[lWierzcholkow];
    for (int i = 0; i<lWierzcholkow; i++) {
        macierz[i] = new int[lWierzcholkow];
        for (int j = 0; j < lWierzcholkow; j++)
            if (i > j) {
                macierz[i][j] = rand() % 1000;
            }
            else {
                macierz[i][j] = 0;
            }
    }
    for (int i = 0; i<lWierzcholkow; i++)
        for (int j = 0; j < lWierzcholkow; j++)
            macierz[i][j] = macierz [j][i];
    return macierz;
}

void Graf::zwalnianiePamieci(int **macierz) {
    for(int i=0; i<lWierzcholkow; i++)
        delete [] macierz [i];
    delete [] macierz;
}

void Graf::wyswietlanieGrafu() {
    for(int i=0; i<lWierzcholkow; i++) {
        for (int j = 0; j < lWierzcholkow; j++)
            std::cout << macierz[i][j] << " ";
        std::cout << std::endl;
    }
}

void Graf::dfs(int aktualnyWierzcholek) {
    //do zrobienia zliczanie wag i zapamietywanie najkrotszej sciezki
    stos->push(aktualnyWierzcholek);
    if(stos->size() < lWierzcholkow){
        odwiedzone[aktualnyWierzcholek] = true;
        for(int i=0; i<lWierzcholkow; i++){
            if(macierz[aktualnyWierzcholek][i] && !odwiedzone[i]){
                dfs(i);
            }
        }
        odwiedzone[aktualnyWierzcholek]=false;

    }else{
        if(macierz[aktualnyWierzcholek][0]){
            return;
        }
    }
}

void Graf::metodaSilowa() {
    std::cout << "Podaj mi prosze wierzcholek poczatkowy" << std::endl;
    std::cin >> this->wierzcholekPoczatkowy;
    std::cout << this->wierzcholekPoczatkowy;
    stos = new std::stack<int>();
    odwiedzone = new bool [lWierzcholkow];
    //wywolanie funkcji znajdujacej cykle
    dfs(wierzcholekPoczatkowy);
    while(stos->size() > 0) {
        std::cout << stos->top() << ", ";
        stos->pop();
    }
    delete [] odwiedzone;
}
