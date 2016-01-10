cmake_minimum_required(VERSION 3.3)
project(problemKomiOK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graf.cpp Graf.h MetodaSilowaDFS.cpp MetodaSilowaDFS.h MetodaSilowaPermutacje.cpp
        MetodaSilowaPermutacje.h HeurystykaNajblizszegoSasiada.cpp HeurystykaNajblizszegoSasiada.h Rozwiazanie.cpp
        Rozwiazanie.h AlgorytmMrowkowy.cpp AlgorytmMrowkowy.h Osobnik.h)
add_executable(problemKomiOK ${SOURCE_FILES})