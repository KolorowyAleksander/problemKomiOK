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
        //kombinacja();
        //mutacja();
    }

}

void AlgorytmGenetyczny::generujPopulacje() {
    for (int i = 0; i < liczbaOsobnikow; i++) {
        populacja.emplace_back(OsobnikDNA(this));
        populacja[i].generujRozwiazanie();
    }
}

void AlgorytmGenetyczny::OsobnikDNA::generujRozwiazanie() {
    for (int i = 0; i < parent->liczbaWierzcholkow; i++)
        rozwiazanie.push_back(i);
    std::random_shuffle(rozwiazanie.begin(), rozwiazanie.end());
    policzWynik();
}

void AlgorytmGenetyczny::selekcja() {
    std::sort(populacja.begin(), populacja.end(), [](OsobnikDNA a, OsobnikDNA b) {
        return a.wynik >= b.wynik;
    });
    populacja.erase(populacja.begin() + populacja.size() / 2, populacja.end());

    auto s = populacja.size();
    //populacja.resize(2 * s);
    std::copy_n(populacja.begin(), s, populacja.begin() + s);

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
