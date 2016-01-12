//
// Created by A on 2016-01-08.
//

#ifndef PROBLEMKOMIOK_HEURYSTYKANAJBLIZSZEGOSASIADA_H
#define PROBLEMKOMIOK_HEURYSTYKANAJBLIZSZEGOSASIADA_H

#include <vector>
#include "Rozwiazanie.h"

class HeurystykaNajblizszegoSasiada : public Rozwiazanie {
public:
    void rozwiaz();

    HeurystykaNajblizszegoSasiada(Graf *graf);

private:
    bool *odwiedzone;
};


#endif //PROBLEMKOMIOK_HEURYSTYKANAJBLIZSZEGOSASIADA_H
