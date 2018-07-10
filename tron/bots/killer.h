#ifndef KILLER_H
#define KILLER_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Tron{
    public:

    // ma zwrocic kierunek ruchu (1,2,3,4), moze w destruktorze

    private:
    std::fstream data_stream; // plik na mapke
    std::vector<int> pos; // pozycja, 0 to x, 1 to y
    std::vector<std::vector<char>> arena; // tutaj bede wpisywal informacje o stanie areny


    void load_map(void); // TODO: uzupelnic przez podanie streamem
    void load_pos(std::vector<int> &pos); // TODO: uzupelnic przez podanie streamem
    void check_wall(std::vector<int> &pos);
    void map_state(std::vector<std::vector<char>> &map); // wyswietlanie stanu mapy

    // jakies heurystyki na koniec

};

#endif