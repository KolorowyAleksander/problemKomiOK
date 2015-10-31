#include <iostream>
#include "Graf.h"

using namespace std;

int main() {
    int liczbaWierzcholkow;
    cout << "Podaj mi prosze liczbe wierzcholkow" << endl;
    cin >> liczbaWierzcholkow;
    Graf *graf = new Graf(liczbaWierzcholkow);
    //graf->metoda_silowa_DFS();
    graf->metoda_silowa_permutacje();

    delete graf;
    return 0;
}