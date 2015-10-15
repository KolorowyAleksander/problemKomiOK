//
// Created by A on 2015-10-15.
//

#ifndef PROBLEMKOMIOK_GRAF_H
#define PROBLEMKOMIOK_GRAF_H

class Graf {
    public:
        Graf(int lWierzcholkow);
        ~Graf();
    private:
        int ** macierz;
        int lWierzcholkow;

};


#endif //PROBLEMKOMIOK_GRAF_H
