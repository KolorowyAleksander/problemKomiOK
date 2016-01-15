#include <iostream>
#include <time.h>
#include "Graf.h"
#include "MetodaSilowaPermutacje.h"
#include "HeurystykaNajblizszegoSasiada.h"
#include "AlgorytmGenetyczny.h"
#include "AlgorytmMrowkowy.h"

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
    liczbaWierzcholkow = 5;
    wierzcholekPoczatkowy = 1;
    Graf *graf = new Graf(liczbaWierzcholkow, wierzcholekPoczatkowy);

    AlgorytmMrowkowy m(graf);
    m.rozwiaz(1.0, 2.0, 0.1, 100);
    for (auto i : m.getRozwiazanieWektor())
        cout << i << ' ';
    cout << '\n';
    cout << m.getRozwiazanieSuma();

    delete graf;
    return 0;
}
