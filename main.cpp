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

    //graf->wyswietl();
    //MetodaSilowaDFS(graf->get(), liczbaWierzcholkow, wierzcholekPoczatkowy).rozwiaz();
    //MetodaSilowaPermutacje(graf->get(), liczbaWierzcholkow, wierzcholekPoczatkowy).rozwiaz();
    //HeurystykaNajblizszegoSasiada(graf->get(), liczbaWierzcholkow, wierzcholekPoczatkowy).rozwiaz();
    //AlgorytmMrowkowy(graf->get(),liczbaWierzcholkow,wierzcholekPoczatkowy,2.0, 2.0, 0.1, 30000).rozwiaz();

    delete graf;
    return 0;
}