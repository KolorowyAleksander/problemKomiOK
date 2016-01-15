//
// Created by A on 2016-01-10.
//

#include "AlgorytmGenetyczny.h"

AlgorytmGenetyczny::AlgorytmGenetyczny(Graf *graf)
        : Rozwiazanie(graf) { }

AlgorytmGenetyczny::OsobnikDNA::OsobnikDNA(AlgorytmGenetyczny *parent) : parent(parent) { }

void AlgorytmGenetyczny::rozwiaz() {
    generujPopulacje(); // ile osobnikow w populacji
    while (true) { //!termination()
        selekcja();
        kombinacja();
        mutacja();
        break;
    }
}

void AlgorytmGenetyczny::generujPopulacje() {
    for (int i = 0; i < liczbaOsobnikow; i++) {
        populacja.emplace_back(OsobnikDNA(this));
        populacja[i].generujRozwiazanie();
    }
}

void AlgorytmGenetyczny::OsobnikDNA::generujRozwiazanie() {
    rozwiazanie.push_back(parent->wierzcholekPoczatkowy);
    for (int i = 0; i < parent->liczbaWierzcholkow; i++)
        if (i != parent->wierzcholekPoczatkowy)
            rozwiazanie.push_back(i);
    std::random_shuffle(rozwiazanie.begin() + 1, rozwiazanie.end());
    rozwiazanie.push_back(parent->wierzcholekPoczatkowy);
    policzWynik();
}

void AlgorytmGenetyczny::selekcja() {
    std::sort(populacja.begin(), populacja.end(), [](OsobnikDNA a, OsobnikDNA b) {
        return a.wynik >= b.wynik;
    });
    populacja.erase(populacja.begin() + populacja.size() / 2, populacja.end());

    populacja.shrink_to_fit();
}

AlgorytmGenetyczny::OsobnikDNA &AlgorytmGenetyczny::OsobnikDNA::operator=(const AlgorytmGenetyczny::OsobnikDNA &rhs) {
    this->parent = rhs.parent;
    this->wynik = rhs.wynik;
    this->rozwiazanie = rhs.rozwiazanie;
    return *this;
}

AlgorytmGenetyczny::OsobnikDNA::OsobnikDNA() { }

AlgorytmGenetyczny::OsobnikDNA::OsobnikDNA(const AlgorytmGenetyczny::OsobnikDNA &obj) {
    this->parent = obj.parent;
    this->wynik = obj.wynik;
    this->rozwiazanie = obj.rozwiazanie;
}

void AlgorytmGenetyczny::kombinacja() {

}

void AlgorytmGenetyczny::OsobnikDNA::mutacja() {
    if (rand() % 1000 < 5)
        for (int i = 0; i < rand() % 3; i++)
            std::swap(rozwiazanie[rand() % parent->liczbaWierzcholkow],
                      rozwiazanie[rand() % parent->liczbaWierzcholkow]);
}

void AlgorytmGenetyczny::mutacja() {
    for (int i = 0; i < populacja.size(); i++)
        populacja[i].mutacja();
}

void AlgorytmGenetyczny::OsobnikDNA::policzWynik() {
    for (int i = 0; i < rozwiazanie.size() - 1; i++)
        wynik += parent->macierz[rozwiazanie[i]][rozwiazanie[i + 1]];
}
