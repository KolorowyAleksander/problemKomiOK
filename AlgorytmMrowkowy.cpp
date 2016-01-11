//
// Created by A on 2016-01-08.
//

#include "AlgorytmMrowkowy.h"

std::random_device AlgorytmMrowkowy::rd;
std::mt19937 AlgorytmMrowkowy::gen(rd());
std::uniform_real_distribution<> AlgorytmMrowkowy::dis(0.0, 1.0);

AlgorytmMrowkowy::AlgorytmMrowkowy(int **macierz, int liczbaWierzcholkow, int wierzcholekPoczatkowy, double alfa,
                                   double beta, double ro, int maksymalnyFeromon)
        : Rozwiazanie(macierz, liczbaWierzcholkow, wierzcholekPoczatkowy), alfa(alfa), beta(beta), ro(ro),
          maksymalnyFeromon(maksymalnyFeromon) {
    utworzFeromony();
}

void AlgorytmMrowkowy::rozwiaz() {
    for (int i = 0; i < (liczbaWierzcholkow / 2); i++) {
        populacja.emplace_back(Mrowka(*this));
    }
    while (true) { //!termination()
        //generacja rozwiazania.
        for (int i = 0; i < (liczbaWierzcholkow / 2); i++) {
            populacja[i].generujRozwiazanie();
            //populacja[i].wyswietlRozwiazanie();
        }
        zmienFeromony(); // do poprawki
        //przejscie tablicy w poszukiwaniu zlotego graala -- czyli generacja / pokazanie wlasciwego rozwiazania
    }
}

void AlgorytmMrowkowy::Mrowka::generujRozwiazanie() {
    int aktualnyWierzcholek = parent.wierzcholekPoczatkowy;
    //pętla szukania następnego
    while (rozwiazanie.size() < parent.liczbaWierzcholkow - 1) {
        double suma = 0.0;
        odwiedzone[aktualnyWierzcholek] = true;
        std::cout << aktualnyWierzcholek << " ";
        rozwiazanie.push_back(aktualnyWierzcholek);
        for (int i = 0; i < parent.liczbaWierzcholkow; i++) {
            if (!odwiedzone[i]) {
                suma += pow(parent.feromony[aktualnyWierzcholek][i], parent.alfa) *
                        pow(1.0 / parent.macierz[aktualnyWierzcholek][i], parent.beta);
            }
        }
        for (int i = 0; i < parent.liczbaWierzcholkow; i++) {
            if (odwiedzone[i])
                prawdopodobienstwo[i] = 0;
            else {
                prawdopodobienstwo[i] = pow(parent.feromony[aktualnyWierzcholek][i], parent.alfa) *
                                        (pow((1.0 / parent.macierz[aktualnyWierzcholek][i]), parent.beta)) / suma;
            }
        }
        double generowana = parent.dis(gen);
        int licznik = -1;
        while (generowana >= 0) {
            licznik++;
            generowana = generowana - prawdopodobienstwo[licznik];
        }
        if (parent.feromony[aktualnyWierzcholek][licznik] < parent.maksymalnyFeromon)
            parent.feromony[aktualnyWierzcholek][licznik]++;
        aktualnyWierzcholek = licznik;
    }
    std::cout << aktualnyWierzcholek << "   ";
    rozwiazanie.push_back(parent.wierzcholekPoczatkowy);
    policzWynik();
}

void AlgorytmMrowkowy::zmienFeromony() {
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        for (int j = 0; j < liczbaWierzcholkow; j++) {
            feromony[i][j] -= feromony[i][j] * ro;
            if (feromony[i][j] < 1)
                feromony[i][j] = 1;
        }
    }
    //dopisac to co mrowki przeszly
}

void AlgorytmMrowkowy::utworzFeromony() {
    feromony = new int *[liczbaWierzcholkow];
    for (int j = 0; j < liczbaWierzcholkow; j++) {
        feromony[j] = new int[liczbaWierzcholkow];
        for (int k = 0; k < liczbaWierzcholkow; k++) {
            feromony[j][k] = 1;
        }
    }
}

void AlgorytmMrowkowy::usunFeromony() {
    for (int i; i < liczbaWierzcholkow; i++)
        delete[] feromony[i];
    delete feromony;
}

AlgorytmMrowkowy::Mrowka::Mrowka(AlgorytmMrowkowy &parent) : parent(parent) {
    odwiedzone = new bool[parent.liczbaWierzcholkow];
    prawdopodobienstwo = new double[parent.liczbaWierzcholkow];
    for (int i = 0; i < parent.liczbaWierzcholkow; i++)
        odwiedzone[i] = false;
}

AlgorytmMrowkowy::Mrowka::~Mrowka() {
    delete[] odwiedzone;
    delete[] prawdopodobienstwo;
}

AlgorytmMrowkowy::~AlgorytmMrowkowy() {
    usunFeromony();
}
