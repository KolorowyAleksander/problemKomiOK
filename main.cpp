#include <iostream>
#include <chrono>
#include "Graf.h"
#include "MetodaSilowaPermutacje.h"
#include "HeurystykaNajblizszegoSasiada.h"
#include "AlgorytmGenetyczny.h"
#include "AlgorytmMrowkowy.h"
#include <fstream>

using namespace std;


int main(int argc, char *argv[]) {
    int liczbaWierzcholkow;
    int wierzcholekPoczatkowy;
    double alfa = 1.0, beta = 3.0, ro = 0.5, q = 100;
    srand((unsigned int) std::chrono::system_clock::now().time_since_epoch().count());

    if (argc > 1) {
        liczbaWierzcholkow = atoi(argv[1]);
        wierzcholekPoczatkowy = atoi(argv[2]);
    } else {
        cout << "Podaj liczbe wierzcholkow i wierzcholek poczatkowy\n";
        cin >> liczbaWierzcholkow >> wierzcholekPoczatkowy;
    }
    system("cls");

    Graf *graf = new Graf(liczbaWierzcholkow, wierzcholekPoczatkowy);

    bool end = false;
    int ster;
    while (!end) {
        cout << "0:Koniec, 1:Algorytm silowy, 2:Najblizszy sasiad, 3:Mrowki,"
                " 4:Genetyczny, 5:Edycja Mrowek, 6:Edycja grafu, 7:Wyswietlanie grafu\n$:";
        cin >> ster;
        //system("cls");
        switch (ster) {
            case 0:
                end = true;
                break;
            case 1: {
                MetodaSilowaPermutacje m(graf);
                m.rozwiaz();
                cout << "czas: " << m.getCzas() << '\n';
                for (auto i : m.getRozwiazanieWektor()) {
                    cout << i << ' ';
                }
                cout << "droga: " << m.getRozwiazanieSuma() << '\n';
                break;
            }
            case 2: {
                HeurystykaNajblizszegoSasiada k(graf);
                k.rozwiaz();
                cout << "czas: " << k.getCzas() << '\n';
                for (auto i : k.getRozwiazanieWektor()) {
                    cout << i << ' ';
                }
                cout << "droga: " << k.getRozwiazanieSuma() << '\n';
                break;
            }
            case 3: {
                AlgorytmMrowkowy m(graf);
                m.rozwiaz(alfa, beta, ro, q);
                m.rozwiaz(2.0, 2.0, 0.1, 100);
                cout << "czas: " << m.getCzas() << '\n';
                for (auto i : m.getRozwiazanieWektor()) {
                    cout << i << ' ';
                }
                cout << "droga: " << m.getRozwiazanieSuma() << '\n';
                break;
            }
            case 4: {
                AlgorytmGenetyczny m(graf);
                m.rozwiaz();
                cout << "czas: " << m.getCzas() << '\n';
                for (auto i : m.getRozwiazanieWektor()) {
                    cout << i << ' ';
                }
                cout << "droga: " << m.getRozwiazanieSuma() << '\n';
            }
                break;
            case 6: {
                cout << "Podaj liczbe wierzcholkow i wierzcholek poczatkowy\n";
                int a, b;
                cin >> a >> b;
                if ((b >= a) || (b < 0))
                    cout << "Zly wierzcholek poczatkowy\n";
                else {
                    liczbaWierzcholkow = a;
                    wierzcholekPoczatkowy = b;
                    delete graf;
                    graf = new Graf(liczbaWierzcholkow, wierzcholekPoczatkowy);
                }
                break;
            }
            case 5: {
                cout << "Podaj: alfa, beta, ro, q\n";
                cout << "Aktualnie: " << alfa << ' ' << beta << ' ' << ro << ' ' << q << '\n';
                cin >> alfa >> beta >> ro >> q;
                break;
            }
            case 7: {
                cout << '\n';
                graf->wyswietl();
                cout << '\n';
                break;
            }
            default:
                break;
        }
    }
    delete graf;
    return 0;
}
