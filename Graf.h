//
// Created by A on 2015-10-15.
//

#ifndef PROBLEMKOMIOK_GRAF_H
#define PROBLEMKOMIOK_GRAF_H

class Graf {
    public:
        Graf(int lWierzcholkow);
        ~Graf();
        void wyswietlanieGrafu();
    private:
        int ** macierz;
        int lWierzcholkow;
        int ** generowanieMacierzy(int lWierzcholkow);
        void zwalnianiePamieci(int ** macierz);

};


#endif //PROBLEMKOMIOK_GRAF_H
