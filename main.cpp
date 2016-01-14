#include <iostream>
#include <time.h>
#include "Graf.h"
#include "MetodaSilowaDFS.h"
#include "MetodaSilowaPermutacje.h"
#include "HeurystykaNajblizszegoSasiada.h"
#include "AlgorytmGenetyczny.h"

using namespace std;


int main() {
    int liczbaWierzcholkow;
    int wierzcholekPoczatkowy;

    srand(time(nullptr));
    /**
     * zaczatki interfejsu
    MetodaSilowaPermutacje m(graf);
    HeurystykaNajblizszegoSasiada n(graf);
    //cout << "Podaj mi prosze liczbe wierzcholkow" << endl;
    //cin >> liczbaWierzcholkow;
    //graf->wyswietl();
     */
    liczbaWierzcholkow = 10;
    wierzcholekPoczatkowy = 5;
    Graf *graf = new Graf(liczbaWierzcholkow, wierzcholekPoczatkowy);

    AlgorytmGenetyczny o(graf);
    o.rozwiaz();

    /*
    m.rozwiaz();
    for (auto i : m.getRozwiazanieWektor())
        cout << i << ' ';
    cout << '\n';
    cout << m.getRozwiazanieSuma();
     */
    //AlgorytmMrowkowy(graf->get(),liczbaWierzcholkow,wierzcholekPoczatkowy,2.0, 2.0, 0.1, 30000).rozwiaz();
    //MetodaSilowaDFS(graf->get(), liczbaWierzcholkow, wierzcholekPoczatkowy).rozwiaz();

    delete graf;
    return 0;
}
