//
// Created by A on 2015-10-15.
//

#include <c++/iostream>
#include "Graf.h"

Graf::Graf(int lWierzcholkow) {
    this->lWierzcholkow = lWierzcholkow;
    this->macierz = generowanieMacierzy(lWierzcholkow);
}

Graf::~Graf() {

}

int **Graf::generowanieMacierzy(int lWierzcholkow) {
    int ** macierz = nullptr;
    macierz = new int *[lWierzcholkow];
    for (int i = 0; i<lWierzcholkow; i++)
        macierz[i] = new int [lWierzcholkow];
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
