#include "killer3.h"

void Tron::loadDim(){
    char c;
    std::cin >> arena_col >> arena_row >> std::noskipws >> c;
    std::cerr << arena_col << ' ' << arena_row << std::endl;
}

void Tron::loadArena(){
    std::string item;
 
    while(getline(std::cin, item))
    {
        arena.push_back(item);
    }
    
    for(int i=0; i<arena.size(); i++){
        std::cerr << arena[i] << std::endl;
    }
}

void Tron::loadPos(){
    for(int i=0; i < arena_row; ++i)
        for(int j=0; j < arena_col; ++j){
            if(arena[i][j]=='1'){
                pos1_row = i;
                pos1_col = j;
            }
            if(arena[i][j]=='2'){
                pos2_row = i;
                pos2_col = j;
            }
        }
        std::cerr << pos1_row << ' ' << pos1_col << std::endl;
        std::cerr << pos2_row << ' ' << pos2_col << std::endl;
}

int Tron::getPos1(int c){
    if(c) return static_cast<int>(pos1_row);
    else return static_cast<int>(pos1_col);
}

int Tron::getPos2(int c){
    if(c) return static_cast<int>(pos2_row);
    else return static_cast<int>(pos2_col);;
}

void Tron::loadDir(const int &check_row, const int &check_col){
    if(direction.size() != 4) direction.resize(4);

    int l = 0;
    //gora
    if(arena[ check_row - 1 ][ check_col ] == ' ') direction[0] = 1;
    else direction[0] = 0;
    std::cerr << "Gora: " << direction[0] << std::endl;

    //dol
    if(arena[ check_row + 1 ][ check_col ] == ' ') direction[2] = 1;
    else direction[2] = 0;
    std::cerr << "Dol: " << direction[2] << std::endl;

    //prawo
    if(arena[ check_row ][ check_col + 1 ] == ' ') direction[1] = 1;
    else direction[1] = 0;
    std::cerr << "Prawo: " << direction[1] << std::endl;

    //lewo
    if(arena[ check_row ][ check_col - 1 ] == ' ') direction[3] = 1;
    else direction[3] = 0;
    std::cerr << "Lewo: " << direction[3] << std::endl;
}


void Tron::loadData(){
    loadDim();
    loadArena();
    loadPos();
}

void Tron::makeMove(){
    //sleep(1);

    loadDir(pos1_row, pos1_col);
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    std::srand((time_t)ts.tv_nsec);

    int choice;
    while(1) {
        choice = rand()%4;
        if(direction[choice]!=0){
            std::cout << choice+1;
            break;
        }
    }
}