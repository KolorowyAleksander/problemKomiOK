#include <iostream>
#include "Graf.h"

using namespace std;


int main() {
    int liczbaWierzcholkow;
    cout << "Podaj mi prosze liczbe wierzcholkow" << endl;
    //cin >> liczbaWierzcholkow;
    liczbaWierzcholkow = 5;
    Graf *graf = new Graf(liczbaWierzcholkow);
    //graf->metoda_silowa_DFS();
    //graf->metoda_silowa_permutacje();
    //graf->heurystyka_najblizszego_sasiada();
    graf->algorytm_mrowkowy(2.0, 2.0, 0.1);
    delete graf;
    return 0;
}