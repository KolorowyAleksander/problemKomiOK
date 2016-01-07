//
// Created by A on 2015-10-15.
//

#include <c++/iostream>
#include <time.h>
#include "Graf.h"
#include <algorithm>

std::random_device Graf::rd;
std::mt19937 Graf::gen(rd());
std::uniform_real_distribution<> Graf::dis(0.0,1.0);

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

void Graf::algorytm_mrowkowy(double alfa, double beta, double ro) {
    this -> alfa = alfa;
    this -> beta = beta;
    this -> ro = ro;
    int i = 0;
    int najkrotsza; //czy inicjowac
    feromony = new int *[lWierzcholkow];
    for (int j = 0; j<lWierzcholkow; j++){
        feromony[j]=new int [lWierzcholkow];
        for(int k = 0; k < lWierzcholkow; k++){
            feromony[j][k]=1;
        }
    }
    while (i < 100) {
        std::stack<int> droga = mrowka(wierzcholekPoczatkowy);
        int suma=0;
        int a = droga.top();
        std::cout<<droga.top()<<',';
        droga.pop();
        while(droga.top() != wierzcholekPoczatkowy){

            suma =+ macierz[a][droga.top()];
            a = droga.top();
            std::cout<<droga.top()<<',';
            droga.pop();
        }
        std::cout<<suma<<std::endl;

        if(suma < najkrotsza)
            najkrotsza = suma;
        if (!i % 10)
            zmienFeromon();
        i++;

    }

}

void Graf::algorytm_genetyczny() {
}

std::stack<int> Graf::mrowka(int wierzcholekPoczatkowy) {
    std::stack<int> trasa;
    bool *odw = new bool[lWierzcholkow];
    double *prawdopodobienstwo = new double[lWierzcholkow];
    for(int i = 0; i < lWierzcholkow; i++){
        odw[i]=false;
    }
    int aktualnyWierzcholek = wierzcholekPoczatkowy;
    //pętla szukania następnego
    while (trasa.size() <= lWierzcholkow){
        double suma = 0.0;
        odw[aktualnyWierzcholek] = true;
        std::cout << aktualnyWierzcholek << " ";
        trasa.push(aktualnyWierzcholek);
        for(int i = 0; i < lWierzcholkow; i++){
            if(!odw[i]) {
                suma += pow(feromony[aktualnyWierzcholek][i], alfa) * pow(1.0 / macierz[aktualnyWierzcholek][i], beta);
            }
        }
        for(int i = 0; i < lWierzcholkow; i++){
            if(odw[i])
                prawdopodobienstwo[i] = 0;
            else {
                prawdopodobienstwo[i] = pow(feromony[aktualnyWierzcholek][i], alfa) *
                                        (pow((1.0 / macierz[aktualnyWierzcholek][i]), beta)) / suma;
            }
        }
        double xxx = 0.0;
        for (int x = 0; x < lWierzcholkow; x++) {
            xxx += prawdopodobienstwo[x];
        }

        double generowana = dis(gen);
        int licznik = -1;
        while(generowana >= 0){
            licznik++;
            generowana = generowana - prawdopodobienstwo[licznik];
        }
        if(feromony[aktualnyWierzcholek][licznik] < maksymalny)
            feromony[aktualnyWierzcholek][licznik]++;
        aktualnyWierzcholek = licznik;
    }
    std::cout << aktualnyWierzcholek << "   ";
    trasa.push(wierzcholekPoczatkowy);
    delete[] odw;
    delete[] prawdopodobienstwo;
    return trasa;
}

void Graf::zmienFeromon(){
    for(int i = 0; i < lWierzcholkow; i++){
        for(int j = 0; j <lWierzcholkow; j++){
            feromony[i][j] -= feromony[i][j]*ro;
            if(feromony[i][j]<1)
                feromony[i][j]=1;
        }
    }
}
