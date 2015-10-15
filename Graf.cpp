//
// Created by A on 2015-10-15.
//

#include "Graf.h"

Graf::Graf(int lWierzcholkow) {
    this->lWierzcholkow = lWierzcholkow;
    macierz= new macierz*[lWierzcholkow];
    for(int i=0; i<lWierzcholkow; i++)
        macierz[i] = new macierz[i];


}

Graf::~Graf() {
    for(int i=0; i<lWierzcholkow;i++)
        delete [] macierz[i];
    delete macierz[];
}
