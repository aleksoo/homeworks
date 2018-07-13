#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cmath>
#include <algorithm>

#ifndef KILLER3_H
#define KILLER3_H


class Tron{
    public:

    void loadData();
    void makeMove();
    int getPos1(int); //1 zwraca row, 0 zwraca col
    int getPos2(int); //1 zwraca row, 0 zwraca col

    private:
    
    std::vector<std::string> arena;
    std::vector<int> direction1;
    std::vector<int> direction2;
    int pos1_row, pos1_col;
    int pos2_row, pos2_col;
    int arena_row, arena_col;
    /*
    ROW - TUTAJ JEST WYSOKOSC MAPY, GORA DOL arena[ROW][], 
    PORUSZAM SIE PO STRINGACH, NIE ICH ZAWARTOSCI

    COL - DO TEGO JEST WPISANA SZEROKOSC MAPY, CZYLI SLUZY
    DO PORUSZANIA SIE NA BOKI TYPU arena[][COL] BO PORUSZAM
    SIE PO STRINGU, STRING TO JEDNA LINIA 

    */

    void loadDim();
    void loadArena();
    void loadPos();
    void loadDir(const int&, const int&, std::vector<int>&); //
    int maxEl(const std::vector<int>&);

};

#endif