#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

#ifndef KILLER_H
#define KILLER_H


class Tron{
    public:

    void loadData();
    void makeMove();



    private:
    
    std::vector<std::string> arena;    
    std::vector<int> pos1; //
    std::vector<int> pos2;
    std::vector<int> dir_lenght; // 0 gora, 1 prawo, 2 dol, 3 lewo
    int row, col;
    int iRow, jColumn;

    int max_el();
    void loadDim();
    void loadArena();
    void loadPos();
    void checkWall();

};

#endif