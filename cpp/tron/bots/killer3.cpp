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
        position1 = std::pair<int, int>(pos1_row, pos1_col);
        position2 = std::pair<int, int>(pos2_row, pos2_col);
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

void Tron::loadDir(const int check_row, const int check_col, std::vector<int> &direction){
    if(direction.size() != 4) direction.resize(4);
    std::cerr << "========= " << std::endl;
    int l = 0;
    //gora
    if(arena[ check_row - 1 ][ check_col ] == ' ') {
        --l;
        while(arena[ check_row - 1 - l ][ check_col ] == ' ') --l;
        direction[0] = check_row - abs(l);
    }
    else direction[0] = 0;
    std::cerr << "Gora: " << direction[0] << std::endl;

    l = 0;
    //dol
    if(arena[ check_row + 1 ][ check_col ] == ' ') {
        ++l;
        while(arena[ check_row + 1 + l ][ check_col] == ' ') ++l;
        direction[2] = abs(l);
    }
    else direction[2] = 0;
    std::cerr << "Dol: " << direction[2] << std::endl;

    l = 0;
    //prawo
    if(arena[ check_row ][ check_col + 1 ] == ' ') {
        ++l;
        while(arena[ check_row ][check_col + 1 + l] == ' ') ++l;
        direction[1] = abs(l);
    }
    else direction[1] = 0;
    std::cerr << "Prawo: " << direction[1] << std::endl;

    l = 0;
    //lewo
    if(arena[ check_row ][ check_col - 1 ] == ' ') {
        --l;
        while(arena[ check_row ][ check_col - 1 - l] == ' ') --l;
        direction[3] = check_col - abs(l);
    }
    else direction[3] = 0;
    std::cerr << "Lewo: " << direction[3] << std::endl;
}

void Tron::loadData(){
    loadDim();
    loadArena();
    loadPos();    
}



void Tron::bfs(){
    std::queue<std::pair<int, int>> myqueue; // kolejka wezlow do odwiedzenia
    std::cerr << "Test" << std::endl;

    std::vector<std::vector<bool>>visited; // stany czy cos zostalo odwiedzone
    std::vector<std::pair<int, int>> parents; //stany rodzicow
    std::vector<bool> pos_state;
    std::pair<int, int> position(pos1_row, pos1_col);

    visited.resize(arena_row, std::vector<bool>(arena_col)); // resize areny booli
    

    myqueue.push(position1);
    visited[position.first][position.second]=true;

    while(!myqueue.empty()){
        
        std::pair<int, int> para;
        para = myqueue.front();
        myqueue.pop();

        //if(!visited[para.first][para.second]) <- cz
        if(arena[para.first][para.second] == '2'){
            // zwrocic sciezke, bo znalezlismy przeciwnika, pozniej mozna zmienic na co innego
            std::cerr << para.first << ' ' << para.second << std::endl;
        }

        //przetworzenie danych, wyliczenie oplacalnosci czy cos, wtedy zmodyfikowac loadDir zeby zwracal cos sensownego

        //zakolejkowac dzieci pary, wrzucic do myqueue sasiednie stany
        
        pos_state = isWall(position1.first, position1.second);
        

        if(pos_state[0]) myqueue.emplace(std::pair<int, int>(position.first-1, position.second)); //gora
        if(pos_state[1]) myqueue.emplace(std::pair<int, int>(position.first, position.second+1)); //prawo
        if(pos_state[2]) myqueue.emplace(std::pair<int, int>(position.first+1, position.second)); //dol
        if(pos_state[3]) myqueue.emplace(std::pair<int, int>(position.first, position.second-1)); //lewo
        //std::cerr << pos_state[0] << ' ' << pos_state[1] << ' ' << pos_state[2] << ' ' << pos_state[3] << std::endl;
        
        parents.emplace_back(position);
    
    }


}

std::vector<bool> Tron::isWall(const int row, const int col){
    std::vector<bool> directions;
    directions.resize(4);
    if(arena[ row - 1 ][ col ] == ' ') directions[0]=true;
    else directions[0]=false;
    if(arena[ row + 1 ][ col ] == ' ') directions[2]=true;
    else directions[2]=false;
    if(arena[ row ][ col + 1 ] == ' ') directions[1]=true;
    else directions[1]=false;
    if(arena[ row ][ col - 1 ] == ' ') directions[3]=true;
    else directions[3]=false;
    return directions;
}

int Tron::maxEl(const std::vector<int> &wektor){
    int max=0;
    for(int i=1; i<wektor.size(); i++){
        if(wektor[max]<=wektor[i]) max = i;
    }
    return max;
}

void Tron::makeMove(){

    loadDir(pos1_row, pos1_col, direction1);
    bfs();
    //loadDir(pos2_row, pos2_col, direction2);
    //struct timespec ts;
    //clock_gettime(CLOCK_MONOTONIC, &ts);
    //std::srand((time_t)ts.tv_nsec);
    std::cout << maxEl(direction1)+1;

}