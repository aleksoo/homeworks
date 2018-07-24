#include "killer3.h"

void Tron::loadDim()
{
    char c;
    std::cin >> arena_col >> arena_row >> std::noskipws >> c;
    std::cerr << arena_col << ' ' << arena_row << std::endl;
}

void Tron::loadArena()
{
    std::string item;

    while (getline(std::cin, item))
    {
        arena.push_back(item);
    }

    for (int i = 0; i < arena.size(); i++)
    {
        std::cerr << arena[i] << std::endl;
    }
}

void Tron::loadPos()
{
    for (int i = 0; i < arena_row; ++i)
        for (int j = 0; j < arena_col; ++j)
        {
            if (arena[i][j] == '1')
            {
                pos1_row = i;
                pos1_col = j;
            }
            if (arena[i][j] == '2')
            {
                pos2_row = i;
                pos2_col = j;
            }
        }
    position1 = std::pair<int, int>(pos1_row, pos1_col);
    position2 = std::pair<int, int>(pos2_row, pos2_col);
    std::cerr << pos1_row << ' ' << pos1_col << std::endl;
    std::cerr << pos2_row << ' ' << pos2_col << std::endl;
}

int Tron::getPos1(int c)
{
    if (c)
        return static_cast<int>(pos1_row);
    else
        return static_cast<int>(pos1_col);
}

int Tron::getPos2(int c)
{
    if (c)
        return static_cast<int>(pos2_row);
    else
        return static_cast<int>(pos2_col);
    ;
}



void Tron::loadDir(const int check_row, const int check_col, std::vector<int> &direction)
{
    if (direction.size() != 4)
        direction.resize(4);
    std::cerr << "========= " << std::endl;
    int l = 0;
    //gora
    if (arena[check_row - 1][check_col] == ' ')
    {
        --l;
        while (arena[check_row - 1 - l][check_col] == ' ')
            --l;
        direction[0] = check_row - abs(l);
    }
    else
        direction[0] = 0;
    //std::cerr << "Gora: " << direction[0] << std::endl;

    l = 0;
    //dol
    if (arena[check_row + 1][check_col] == ' ')
    {
        ++l;
        while (arena[check_row + 1 + l][check_col] == ' ')
            ++l;
        direction[2] = abs(l);
    }
    else
        direction[2] = 0;
    //std::cerr << "Dol: " << direction[2] << std::endl;

    l = 0;
    //prawo
    if (arena[check_row][check_col + 1] == ' ')
    {
        ++l;
        while (arena[check_row][check_col + 1 + l] == ' ')
            ++l;
        direction[1] = abs(l);
    }
    else
        direction[1] = 0;
    //std::cerr << "Prawo: " << direction[1] << std::endl;

    l = 0;
    //lewo
    if (arena[check_row][check_col - 1] == ' ')
    {
        --l;
        while (arena[check_row][check_col - 1 - l] == ' ')
            --l;
        direction[3] = check_col - abs(l);
    }
    else
        direction[3] = 0;
    //std::cerr << "Lewo: " << direction[3] << std::endl;
}

void Tron::loadData()
{
    loadDim();
    loadArena();
    loadPos();
}

void Tron::bfs()
{
    std::queue<std::pair<int, int>> myqueue; // kolejka wezlow do odwiedzenia
    std::vector<std::vector<bool>> visited;   // stany pol, czy zostaly odwiedzone
    std::vector<std::vector<std::pair<int, int>>> parents; // na wspolrzednych row col zawarta jest informacja o poprzednim polu (skad przyszlismy)
    std::vector<bool> pos_state;              // mozliwe drogi z danego polozenia
    std::pair<int, int> position(pos1_row, pos1_col); //pozycja startowac

    visited.resize(arena_row, std::vector<bool>(arena_col)); // resize areny booli
    parents.resize(arena_row, std::vector<std::pair<int, int>>(arena_col)); // resize 

    myqueue.push(position); // wrzucam pierwsza pozycje do kolejki
    visited[position.first][position.second] = true; // zaznaczam odwiedzony stan
    
    //parents[position.first][position.second].first = -1;
    //parents[position.first][position.second].second = -1;
    while (!myqueue.empty())
    {

        std::pair<int, int> paraPos; // "para" to obecna pozycja do przettworzenia
        paraPos = myqueue.front();   // czyta aktualna pozycje, "para" staje sie aktualnym polozeniem
        myqueue.pop();
        //std::cerr << "Powrot na pole: " << paraPos.first << ' ' << paraPos.second << std::endl;
        if (arena[paraPos.first][paraPos.second] == '2') // jaka decyzje podjac po odnalezieniu przeciwnika
        {
            std::cerr << "Znaleziona 2: " << paraPos.first << ' ' << paraPos.second << std::endl;
            //while do miejsca poczatkowego
            while((parents[paraPos.first][paraPos.second].first != position.first) || (parents[paraPos.first][paraPos.second].second != position.second)) {
                paraPos = parents[paraPos.first][paraPos.second]; 
                //std::cerr << "Powrot na pole: " << paraPos.first << ' ' << paraPos.second << std::endl;                
            } // JAK SIE TEN WHILE SKONCZY TO paraPos MA POLE NA KTORE NALEZY ISC JEZELI CHCEMY ISC W STRONE PRZECIWNIKA
            if(paraPos.first == position.first){
                if(paraPos.second < position.second) std::cout << 4;
                else std::cout << 2;
            } else if(paraPos.second == position.second){
                if(paraPos.first < position.first) std::cout << 1;
                else std::cout << 3;
            }

            break;
        } // koniec while po znalezieniu przeciwnika

        //przetworzenie danych, wyliczenie oplacalnosci czy cos, wtedy zmodyfikowac loadDir zeby zwracal cos sensownego
        //zakolejkowac dzieci pary, wrzucic do myqueue sasiednie stany, ZROBIONE

        // Przetworzenie pol pod wzgledem mozliwosci podrozy
        pos_state = isWall(paraPos.first, paraPos.second);
        std::pair<int, int> pozycja[4] = {{paraPos.first - 1, paraPos.second}, {paraPos.first, paraPos.second + 1}, {paraPos.first + 1, paraPos.second}, {paraPos.first, paraPos.second - 1}};
        for (int i = 0; i < 4; ++i)
        {
            auto para_dziecko = pozycja[i];
            if (pos_state[i] && !visited[para_dziecko.first][para_dziecko.second] && (arena[para_dziecko.first][para_dziecko.second] == ' ' || arena[para_dziecko.first][para_dziecko.second] == '2'))
            {
                myqueue.emplace(std::pair<int, int>(para_dziecko.first, para_dziecko.second));
                visited[para_dziecko.first][para_dziecko.second] = true;
                parents[para_dziecko.first][para_dziecko.second] = paraPos;
            }
        }
    }
    //to jest miejsce, gdzie mam wpisywac rzeczy jak sie nei znajdzie przeciwniora
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    std::srand((time_t)ts.tv_nsec);
    loadDir(pos1_row, pos1_col, direction1);
    std::cout << maxEl(direction1) + 1;
}

std::vector<bool> Tron::isWall(const int row, const int col)
{
    std::vector<bool> directions;
    directions.resize(4);
    if (arena[row - 1][col] == ' ')
        directions[0] = false;
    else
        directions[0] = true;
    if (arena[row + 1][col] == ' ')
        directions[2] = false;
    else
        directions[2] = true;
    if (arena[row][col + 1] == ' ')
        directions[1] = false;
    else
        directions[1] = true;
    if (arena[row][col - 1] == ' ')
        directions[3] = false;
    else
        directions[3] = true;
    return directions;
}

int Tron::maxEl(const std::vector<int> &wektor)
{
    int max = 0;
    for (int i = 1; i < wektor.size(); i++)
    {
        if (wektor[max] <= wektor[i])
            max = i;
    }
    return max;
}

void Tron::makeMove()
{

    
    bfs();
    //loadDir(pos2_row, pos2_col, direction2);

}