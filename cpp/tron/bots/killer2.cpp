#include "killer2.h"
#include <iomanip>

void Tron::loadDim(){
    char c;
    std::cin >> col >> row >> std::noskipws >> c;
    std::cerr << col << ' ' << row << std::endl;
}

void Tron::loadArena(){
    std::string arena_string;
    while(getline(std::cin, arena_string)){
        std::cerr << arena_string << std::endl;
        arena.push_back(arena_string);
    }
    /*
    for(int i=0; i<arena.size(); i++){
        std::cerr << arena[i];
    }*/
}

void Tron::loadPos(){
    pos1.resize(2);
    pos2.resize(2);
    
    for(iRow = 0; iRow < row; iRow++){
        for(jColumn = 0; jColumn < col; jColumn++){
                if(arena[iRow][jColumn]=='1'){
                pos1[0]=iRow;
                pos1[1]=jColumn;
                std::cerr << jColumn << ' ' << iRow;
            } 
        }
    }
}

void Tron::loadData(){
    loadDim();
    loadArena();
    loadPos();
}

void Tron::checkWall(){
    //check gora
    dir_lenght.resize(4);
    if(arena[pos1[0]-1][pos1[1]] != '#') dir_lenght[0] = 1;
    else dir_lenght[0] = 0;
    //check dol
    if(arena[pos1[0]+1][pos1[1]] != '#') dir_lenght[2] = 1;
    else dir_lenght[2] = 0;
    //check lewo
    if(arena[pos1[0]][pos1[1]-1] != '#') dir_lenght[3] = 1;
    else dir_lenght[3] = 0;
    //check prawo
     if(arena[pos1[0]][pos1[1]+1] != '#') dir_lenght[1] = 1;
     else dir_lenght[1] = 0;
}

int Tron::max_el(){
    int largest = 0;
    for(int i=0; i<4; i++){
        if(largest<dir_lenght[i]) largest = i;
    }
    return largest+1; //TODO
}

void Tron::makeMove(){
    std::srand(std::time(nullptr));
    int direction = std::rand() % 4;
    checkWall();
    //std::cout << direction + 1;
    std::cout << max_el();
}
