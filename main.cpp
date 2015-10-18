#include <iostream>
#include "Graf.h"

using namespace std;

int main() {
    int liczbaWierzcholkow;
    cout << "Podaj mi prosze liczbe wierzcholkow" << endl;
    cin >> liczbaWierzcholkow ;
    Graf *graf = new Graf(liczbaWierzcholkow);
    graf->metodaSilowa();

    delete graf;
    return 0;
}