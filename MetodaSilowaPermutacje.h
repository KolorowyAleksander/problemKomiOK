//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_METODASILOWAPERMUTACJE_H
#define PROBLEMKOMIOK_METODASILOWAPERMUTACJE_H

#include <vector>
#include "Rozwiazanie.h"

class MetodaSilowaPermutacje : public Rozwiazanie {
public:
    void rozwiaz();

    MetodaSilowaPermutacje(Graf *graf);

private:
    std::vector<int> tablicaWierzcholkow;
    unsigned long long int suma;
protected:
    bool sprawdzMax(unsigned long long int sprawdzana);
};


#endif //PROBLEMKOMIOK_METODASILOWAPERMUTACJE_H
