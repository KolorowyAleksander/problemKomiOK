//
// Created by A on 2016-01-10.
//

#include "AlgorytmGenetyczny.h"
#include <chrono>
#include <climits>

AlgorytmGenetyczny::AlgorytmGenetyczny(Graf *graf)
        : Rozwiazanie(graf) { }

AlgorytmGenetyczny::OsobnikDNA::OsobnikDNA(AlgorytmGenetyczny *parent) : parent(parent) { }

void AlgorytmGenetyczny::rozwiaz() {
    auto start = std::chrono::system_clock::now();
    generujPopulacje();
    for (int i = 0; i < 1000; i++) {
        selekcja();
        kombinacja();
        mutacja();
    }
    auto end = std::chrono::system_clock::now();
    czas = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
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
        return a.wynik > b.wynik;
    });
    populacja.erase(populacja.begin() + (populacja.size() + 1) / 2, populacja.end());
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
    unsigned long long int size = (populacja.size() + 1) / 2;
    for (int i = 0; i < size; i++) {
        krzyzuj(populacja[i], populacja[size - i]);
    }
    std::sort(populacja.begin(), populacja.end(), [](OsobnikDNA a, OsobnikDNA b) {
        return a.wynik < b.wynik;
    });
    populacja.resize((unsigned long long int) liczbaOsobnikow);
    rozwiazanie = populacja[0].getRozwiazanie();
    sumaOdleglosci = populacja[0].getWynik();
}

void AlgorytmGenetyczny::OsobnikDNA::mutacja() {
    if (rand() % 1000 < 50)
        for (int i = 0; i < rand() % 3; i++)
            std::swap(rozwiazanie[(rand() % (parent->liczbaWierzcholkow - 1)) + 1],
                      rozwiazanie[(rand() % (parent->liczbaWierzcholkow - 1)) + 1]);
}

void AlgorytmGenetyczny::mutacja() {
    for (int i = 0; i < populacja.size(); i++)
        populacja[i].mutacja();
}

void AlgorytmGenetyczny::OsobnikDNA::policzWynik() {
    wynik = 0;
    for (int i = 0; i < rozwiazanie.size() - 1; i++)
        wynik += parent->macierz[rozwiazanie[i]][rozwiazanie[i + 1]];
}

void AlgorytmGenetyczny::krzyzuj(AlgorytmGenetyczny::OsobnikDNA ojciec, AlgorytmGenetyczny::OsobnikDNA matka) {
    std::vector<int> a = ojciec.getRozwiazanie(), b = matka.getRozwiazanie();
    a = inwersja(a);
    b = inwersja(b);
    int i = rand() % liczbaWierzcholkow;
    std::swap_ranges(a.begin() + i, a.end(), b.begin() + i);
    a = odwrotnaInversja(a);
    b = odwrotnaInversja(b);
    if (a[0] != wierzcholekPoczatkowy)
        for (int i = 0; i < a.size(); i++)
            if (a[i] == wierzcholekPoczatkowy) {
                std::swap(a[0], a[i]);
                break;
            }
    if (b[0] != wierzcholekPoczatkowy)
        for (int i = 0; i < b.size(); i++)
            if (b[i] == wierzcholekPoczatkowy) {
                std::swap(b[0], b[i]);
                break;
            };
    OsobnikDNA syn(this), corka(this);
    syn.setRozwiazanie(a);
    corka.setRozwiazanie(b);
    populacja.push_back(syn);
    populacja.push_back(corka);
}

void AlgorytmGenetyczny::OsobnikDNA::setRozwiazanie(std::vector<int> rozwiazanie) {
    this->rozwiazanie = rozwiazanie;
    policzWynik();
}

std::vector<int> AlgorytmGenetyczny::inwersja(const std::vector<int> v) {
    std::vector<int> t(v.size() - 1);
    int m;
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        t[i] = 0;
        m = 0;
        while (v[m] != i) {
            if (v[m] > i) {
                t[i]++;
            }
            m++;
        }
    }
    return t;
}

std::vector<int> AlgorytmGenetyczny::odwrotnaInversja(const std::vector<int> v) {
    std::vector<int> out(v.size()), t(v.size());
    for (int i = liczbaWierzcholkow - 1; i > 0; i--) {
        for (int j = i; j < liczbaWierzcholkow; j++)
            if (t[j] >= v[i] + 1) {
                t[j]++;
            }
        t[i] = v[i] + 1;
    }
    for (int i = 0; i < liczbaWierzcholkow; i++)
        out[t[i]] = i;
    out.push_back(wierzcholekPoczatkowy);
    return out;
}
