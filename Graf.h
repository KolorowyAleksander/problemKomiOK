//
// Created by A on 2015-10-15.
//

#ifndef PROBLEMKOMIOK_GRAF_H
#define PROBLEMKOMIOK_GRAF_H

#include <stack>

class Graf {
    public:
        Graf(int lWierzcholkow);
        ~Graf();
        void wyswietlanieGrafu();
        void metodaSilowa();
    private:
        int ** macierz;
        bool * odwiedzone;
        int wierzcholekPoczatkowy;
        std::stack <int> *stos;
        int lWierzcholkow;
        int ** generowanieMacierzy(int lWierzcholkow);
        void zwalnianiePamieci(int ** macierz);
        void dfs(int aktualnyWierzcholek);


};


#endif //PROBLEMKOMIOK_GRAF_H
