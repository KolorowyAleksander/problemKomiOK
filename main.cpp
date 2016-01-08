#include <iostream>
#include "Graf.h"
#include "MetodaSilowaDFS.h"
#include "MetodaSilowaPermutacje.h"
#include "HeurystykaNajblizszegoSasiada.h"

using namespace std;


int main() {
    int liczbaWierzcholkow;
    int wierzcholekPoczatkowy;
    /**
     * zaczatki interfejsu
     */
    //cout << "Podaj mi prosze liczbe wierzcholkow" << endl;
    //cin >> liczbaWierzcholkow;
    liczbaWierzcholkow = 5;
    wierzcholekPoczatkowy = 0;
    Graf *graf = new Graf(liczbaWierzcholkow, wierzcholekPoczatkowy);
    graf->wyswietlanie_grafu();
    //MetodaSilowaDFS(graf->get_macierz(), liczbaWierzcholkow, wierzcholekPoczatkowy).rozwiaz();
    //MetodaSilowaPermutacje(graf->get_macierz(), liczbaWierzcholkow, wierzcholekPoczatkowy).rozwiaz();
    //HeurystykaNajblizszegoSasiada(graf->get_macierz(), liczbaWierzcholkow, wierzcholekPoczatkowy).rozwiaz();
    //graf->algorytm_mrowkowy(2.0, 2.0, 0.1, 30000);
    delete graf;
    return 0;
}